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
1.��M��ͬ����ƻ������N��ͬ���������
  �����е����ӿ��Ų��ţ��ʹ��ж����ֲ�ͬ�ķַ���
 ����K��ʾ��5��1��1��1��5��1 ��ͬһ�ַַ���
2.��һ���ǲ������ݵ���Ŀt��0 <= t <= 20����
  ����ÿ�о�������������M��N���Կո�ֿ���1<=M��N<=10��
3.�������ÿ������M��N����һ�������Ӧ��K��
*/
