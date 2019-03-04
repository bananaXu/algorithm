#include <iostream>
using namespace std;

int t, m, n;
int dp[15][15];

int getk()
{
	int i, j;
	memset(dp, 0, sizeof(dp));
	for (i = 1; i <= n; i ++)
		dp[0][i] = 1;
	for (i = 1; i <= m; i ++)
	{
		for (j = 1; j <= n; j ++)
			dp[i][j] = dp[i][j-1]+(i >= j ? dp[i-j][j] : 0);
	}
	return dp[m][n];
}

int main()
{
	int k;
	cin >> t;
	while (t --)
	{
		cin >> m >> n;
		k = getk();
		cout << k << endl;
	}
	for (int i = 1; i <= m; i ++)
	{
		for (int j = 1; j <= n; j ++)
			cout << dp[i][j] << " ";
		cout << endl; 
	} 
	return 0;
} 
// dp[i][j] = dp[i-1][j]+dp[i-1][j-1]
/*
1.把M个同样的苹果放在N个同样的盘子里，
  允许有的盘子空着不放，问共有多少种不同的分法？
 （用K表示）5，1，1和1，5，1 是同一种分法。
2.第一行是测试数据的数目t（0 <= t <= 20）。
  以下每行均包含二个整数M和N，以空格分开。1<=M，N<=10。
3.对输入的每组数据M和N，用一行输出相应的K。
*/
