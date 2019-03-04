#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <cmath>
#include <vector> 
#include <queue>
#include <ctype.h>
#include <map>
#include <cfloat>
using namespace std;

int a[55][55];
int dp[55][55][105]; // dp[i][j][k] ��ʾһ��ǰ������i�У���һ��j�У����������Ϊk 
 
int MAX(int a, int b, int c, int d)
{  
	int Maxab = a > b ? a : b;
	int Maxcd = c > d ? c : d; 
    return Maxab > Maxcd ? Maxab : Maxcd;  
}

int main()
{
	int t, n, m, i, j, k;
	scanf("%d", &t);
	while (t --)
	{
		scanf("%d%d", &m, &n);
		for (i = 1; i <= m; i ++)
		{
			for (j = 1; j <= n; j ++)
				scanf("%d", &a[i][j]);
		}
		dp[1][1][2] = a[1][1];
		for (k = 3; k <= m+n-1; k ++) 
		{
			int t = k > n ? k-n : 1; // k-i <= n ���� k-j < n 
			for (i = t; i < k && i <= m; i ++) // i < k && i <= m 
			{
				for (j = i+1; j < k && j <= m; j ++) // j��i��dp�����ʱֻ����һ�벻�� 
				{	// ����������״̬�������״̬ 
					dp[i][j][k] = MAX(dp[i][j][k-1], dp[i-1][j][k-1],
			  			dp[i][j-1][k-1], dp[i-1][j-1][k-1])+a[i][k-i]+a[j][k-j];
				}
			}
		}
		printf("%d\n", dp[m-1][m][m+n-1]+a[m][n]);
	}
	return 0;
} 
/*
̽ Ѱ �� ��
ʱ�����ƣ�1000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�5
����
��˵HMH��ɳĮ����һ��M*N�Թ������������౦�ĳ�죬Dr.Kong�ҵ����Թ��ĵ�ͼ���������Թ��ڴ����б�������ı���Ͳ������½ǣ��Թ��Ľ����������Ͻǡ���Ȼ���Թ��е�ͨ·����ƽ̹�ģ������������塣Dr.Kong���������Ļ����˿���ȥ̽�ա�

�������˿�������Ͻ��ߵ����½�ʱ��ֻ�������߻��������ߡ������½������ߵ����Ͻ�ʱ��ֻ�������߻��������ߣ����ҿ��಻�߻�ͷ·��������һ������ྭ��һ�Σ�����Ȼ����˳��Ҳ������·��ÿ�����

Dr.Kongϣ�����Ļ����˿��ྡ����ش�����������д���򣬰���Dr.Kong����һ�£���������ܴ������ٱ��
����
��һ�У� K ��ʾ�ж�����������ݡ� 
��������ÿ��������ݣ�
��1��: M N
��2~M+1�У� Ai1 Ai2 ����AiN (i=1,��..,m)


��Լ��������
2��k��5 1��M, N��50 0��Aij��100 (i=1,��.,M; j=1,��,N)
�������ݶ��������� ����֮����һ���ո�
���
����ÿ��������ݣ����һ�У������˿���Я��������ֵ�ı�����
��������
2
2 3
0 10 10
10 10 80
3 3
0 3 9
2 8 5
5 7 100
�������
120
134
*/ 
