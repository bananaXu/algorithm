#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <cmath>
#include <vector> 
#include <queue>
#include <set>
#include <ctype.h>
#include <map>
#include <cfloat>
using namespace std; 

int dp[11][100005];
#define MOD 1000000007

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; i ++)
		dp[1][i] = 1;
	for (int i = 2; i <= n; i ++)
	{
		int t  = 0;
		for (int j = 1; j <= k; j ++)
			t = (t+dp[i-1][j])%MOD;
		for (int j = 1; j <= k; j ++)
		{
			dp[i][j] = t;
			for (int l = j+j; l <= k; l += j)
				dp[i][j] = (dp[i][j]-dp[i-1][l])%MOD;
		}
	}
	int sum = 0;
	for (int i = 1; i <= k; i ++)
		sum = (sum+dp[n][i])%MOD;
	sum = (sum+MOD)%MOD;
	printf("%d\n", sum);
	return 0;
}
/*
С�׷ǳ�ϲ��ӵ���������ʵ�����:
1�����еĳ���Ϊn
2�������е�ÿ��������1��k֮��(����1��k)
3������λ�����ڵ�������A��B(A��Bǰ),������(A <= B)��(A mod B != 0)(������һ����)
����,��n = 4, k = 7
��ô{1,7,7,2},���ĳ�����4,��������Ҳ��1��7��Χ��,�����������������,����С����ϲ��������е�
����С�ײ�ϲ��{4,4,4,2}������С�С�׸���n��k,ϣ�����ܰ�������ж��ٸ�������ϲ�������С� 
��������:
���������������n��k(1 �� n �� 10, 1 �� k �� 10^5)


�������:
���һ������,������Ҫ������и���,��Ϊ�𰸿��ܴܺ�,�����1,000,000,007ȡģ�Ľ����

��������1:
2 2

�������1:
3
*/
