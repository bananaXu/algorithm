#include <iostream>
#include<algorithm>
#include <cstring>
using namespace std;

#define MAX(a, b) a > b ? a : b
int dp[65][65][115];
int v[52][52],f[102][52][52];
int a[65][65];

void test1()
{
	int i, j, k, t, n, m;
	memset(dp, 0, sizeof(dp));
	m = n = 50;
	for (i = 1; i <= m; i ++)
	{
		for (j = 1; j < i; j ++)
		{
			for (k = i+1; k <= m+n-1 && k-i <= n && k-j<=n; k ++)
			{
				dp[i][j][k] = dp[i][j][k-1];
				dp[i][j][k] = MAX(dp[i][j][k], dp[i-1][j-1][k-1]);
				dp[i][j][k] = MAX(dp[i][j][k], dp[i-1][j][k-1]);
				dp[i][j][k] = MAX(dp[i][j][k], dp[i][j-1][k-1]);
				dp[i][j][k] += a[i][k-i]+a[j][k-j];
			}
		}
	}
	cout << dp[m][n-1][m+n-1] << endl;
}

void test2()
{
	int i,j,k,t,c,T,m,n;
	memset(f,0,sizeof(f));
	m = n = 50;
	c=m+n-2; 
	for(k=1;k<c;k++){
		t=k+2>m?m:k+2;
		for(i=1;i<=t;i++)
			for(j=i+1;j<=t;j++)
				f[k][i][j]=max(max(f[k-1][i][j],f[k-1][i][j-1]),max(f[k-1][i-1][j],f[k-1][i-1][j-1]))
							+v[i][k-i+2]+v[j][k-j+2];
	}
	printf("%d\n",f[c-1][m-1][m]);
}

int main()
{
	int i, j, t;
	srand(time(0));
	cin >> t;
	while (t --)
	{
		for (i = 1; i <= 50; i ++)
		{
			for (j = 1; j <= 50; j ++)
			{
				a[i][j] = v[i][j] = rand()%1000;
			}
		}
		test1();
		test2(); 
	}
	return 0;
}
