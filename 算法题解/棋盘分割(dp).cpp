#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

#define INF 0x3f3f3f3f
#define MIN(a, b) a < b ? a : b

int a[9][9];
int sum[9][9][9] = {0}; // sum[i][j][k]代表k列，第i行到第j行的和 
int dp[15][9][9][9][9] = {0};

int main()
{
	int n, i, j, k, l, m, x, s;
	double p;
	cin >> n;
	s = 0;
	for (i = 1; i <= 8; i ++)
	{
		for (j = 1; j <= 8; j ++)
		{
			cin >> a[i][j];
			s += a[i][j];
		}
	}
	for (i = 1; i <= 8; i ++)
	{
		for (j = i; j <= 8; j ++)
		{
			for (k = 1; k <= 8; k ++)
				sum[i][j][k] = sum[i][j-1][k]+a[j][k];
		}
	}
	for (i = 1; i <= 8; i ++)
	{
		for (j = 1; j <= 8; j ++)
		{
			for (k = i; k <= 8; k ++)
			{
				for (l = j; l <= 8; l ++)
					dp[0][i][j][k][l] = dp[0][i][j][k][l-1]+sum[i][k][l];
			}
		}
	}
	for (i = 1; i <= 8; i ++)
	{
		for (j = 1; j <= 8; j ++)
		{
			for (k = i; k <= 8; k ++)
			{
				for (l = j; l <= 8; l ++)
					dp[0][i][j][k][l] = dp[0][i][j][k][l]*dp[0][i][j][k][l];
			}
		}
	}
	for (i = 1; i <= n; i ++)
	{
		for (j = 1; j <= 8; j ++)
		{
			for (k = 1; k <= 8; k ++)
			{
				for (l = j; l <= 8; l ++)
				{
					for (m = k; m <= 8; m ++)
					{
						dp[i][j][k][l][m] = INF;
						for (x = k; x < m; x ++)
						{
							dp[i][j][k][l][m] = MIN(dp[i][j][k][l][m], 
													dp[0][j][k][l][x]+dp[i-1][j][x+1][l][m]);
							dp[i][j][k][l][m] = MIN(dp[i][j][k][l][m], 
													dp[i-1][j][k][l][x]+dp[0][j][x+1][l][m]);
		 				}
						for (x = j; x < l; x ++)
						{
							dp[i][j][k][l][m] = MIN(dp[i][j][k][l][m], 
													dp[i-1][j][k][x][m]+dp[0][x+1][k][l][m]);
							dp[i][j][k][l][m] = MIN(dp[i][j][k][l][m], 
													dp[0][j][k][x][m]+dp[i-1][x+1][k][l][m]);
						}
					}
				}
			}
		}
	}
	p = sqrt(1.0*dp[n-1][1][1][8][8]/n-1.0*s*s/n/n);
	printf("%.3f\n", p);
	return 0;
}
/*
将一个８*８的棋盘进行如下分割：将原棋盘割下一块矩形棋盘并使剩下部分也是矩形，再将剩下的部分继续如此分割，这样割了(n-1)次后，连同最后剩下的矩形棋盘共有n块矩形棋盘。(每次切割都只能沿着棋盘格子的边进行) 
原棋盘上每一格有一个分值，一块矩形棋盘的总分为其所含各格分值之和。现在需要把棋盘按上述规则分割成n块矩形棋盘，并使各矩形棋盘总分的均方差最小。 
均方差，其中平均值，xi为第i块矩形棋盘的总分。 
请编程对给出的棋盘及n，求出O'的最小值。 
输入
第1行为一个整数n(1 < n < 15)。 
第2行至第9行每行为8个小于100的非负整数，表示棋盘上相应格子的分值。每行相邻两数之间用一个空格分隔。
输出
仅一个数，为O'（四舍五入精确到小数点后三位）。
样例输入
3
1 1 1 1 1 1 1 3
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 0
1 1 1 1 1 1 0 3
样例输出
1.633
*/
//1460 484
