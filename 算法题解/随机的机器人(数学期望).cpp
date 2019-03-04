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
思路：
dp[i][j][k]表示第i步，长度为j，在第k个位置
那么dp[i][j][k]下一步 
当k == 1时，下一步可以为dp[i+1][j+1][k]或dp[i+1][j][k+1](j != 1)
当k == j时，下一步可以为dp[i+1][j][k-1](j != 1)或dp[i+1][j+1][k+1]
当1 < k < j时，下一步可以为dp[i+1][j][k-1]或dp[i+1][j][k+1] 

优化：
k == 1时，下一步为dp[i+1][j+1][k]，否则为dp[i+1][j][k-1] 
k == j时，下一步为dp[i+1][j+1][k+1]，否则为dp[i+1][j][k+1] 

再度优化：
由于dp[i+1][j][k]只与dp[i][x][y]有关
所以可以用滚动数组优化 
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
有一条无限长的纸带,分割成一系列的格子,最开始所有格子初始是白色。现在在一个格子上放上一个萌萌的机器人(放上的这个格子也会被染红),机器人一旦走到某个格子上,就会把这个格子涂成红色。现在给出一个整数n,机器人现在会在纸带上走n步。每一步,机器人都会向左或者向右走一个格子,两种情况概率相等。机器人做出的所有随机选择都是独立的。现在需要计算出最后纸带上红色格子的期望值。 
输入描述:
输入包括一个整数n(0 ≤ n ≤ 500),即机器人行走的步数。


输出描述:
输出一个实数,表示红色格子的期望个数,保留一位小数。

输入例子1:
4

输出例子1:
3.4
*/
