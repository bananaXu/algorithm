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

#define M 505

double dp[2][M][M];

/*
˼·��
dp[i][j][k]��ʾ��i��������Ϊj���ڵ�k��λ��
��ôdp[i][j][k]��һ�� 
��k == 1ʱ����һ������Ϊdp[i+1][j+1][k]��dp[i+1][j][k+1](j != 1)
��k == jʱ����һ������Ϊdp[i+1][j][k-1](j != 1)��dp[i+1][j+1][k+1]
��1 < k < jʱ����һ������Ϊdp[i+1][j][k-1]��dp[i+1][j][k+1] 

�Ż���
k == 1ʱ����һ��Ϊdp[i+1][j+1][k]������Ϊdp[i+1][j][k-1] 
k == jʱ����һ��Ϊdp[i+1][j+1][k+1]������Ϊdp[i+1][j][k+1] 

�ٶ��Ż���
����dp[i+1][j][k]ֻ��dp[i][x][y]�й�
���Կ����ù��������Ż� 
*/

int main()
{
	int n;
	scanf("%d", &n);
	dp[0][1][1] = 1; 
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= i+1; j ++)
		{
			for (int k = 1; k <= j; k ++)
				dp[i&1][j][k] = 0.0;
		}
		for (int j = 1; j <= i; j ++)
		{
			for (int k = 1; k <= j; k ++)
			{
				double x = dp[1-(i&1)][j][k]/2;
				if (k == 1)
					dp[i&1][j+1][k] += x;
				else
					dp[i&1][j][k-1] += x;
			 	if (k == j)
					dp[i&1][j+1][k+1] += x;
				else
					dp[i&1][j][k+1] += x;
			}
		}
	}
	double sum = 0.0;
	for (int i = 1; i <= n+1; i ++)
	{
		for (int j = 1; j <= i; j ++)
			sum += dp[n&1][i][j]*i;
	}
	printf("%.1lf\n", sum);
	return 0;
}
/*
��һ�����޳���ֽ��,�ָ��һϵ�еĸ���,�ʼ���и��ӳ�ʼ�ǰ�ɫ��������һ�������Ϸ���һ�����ȵĻ�����(���ϵ��������Ҳ�ᱻȾ��),������һ���ߵ�ĳ��������,�ͻ���������Ϳ�ɺ�ɫ�����ڸ���һ������n,���������ڻ���ֽ������n����ÿһ��,�����˶����������������һ������,�������������ȡ��������������������ѡ���Ƕ����ġ�������Ҫ��������ֽ���Ϻ�ɫ���ӵ�����ֵ�� 
��������:
�������һ������n(0 �� n �� 500),�����������ߵĲ�����


�������:
���һ��ʵ��,��ʾ��ɫ���ӵ���������,����һλС����

��������1:
4

�������1:
3.4
*/
