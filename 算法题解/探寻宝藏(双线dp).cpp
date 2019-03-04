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
int dp[55][55][105]; // dp[i][j][k] 表示一条前进到第i行，另一条j行，横纵坐标和为k 
 
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
			int t = k > n ? k-n : 1; // k-i <= n 并且 k-j < n 
			for (i = t; i < k && i <= m; i ++) // i < k && i <= m 
			{
				for (j = i+1; j < k && j <= m; j ++) // j比i大，dp数组此时只用了一半不到 
				{	// 可以由四种状态到达这个状态 
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
探 寻 宝 藏
时间限制：1000 ms  |  内存限制：65535 KB
难度：5
描述
传说HMH大沙漠中有一个M*N迷宫，里面藏有许多宝物。某天，Dr.Kong找到了迷宫的地图，他发现迷宫内处处有宝物，最珍贵的宝物就藏在右下角，迷宫的进出口在左上角。当然，迷宫中的通路不是平坦的，到处都是陷阱。Dr.Kong决定让他的机器人卡多去探险。

但机器人卡多从左上角走到右下角时，只会向下走或者向右走。从右下角往回走到左上角时，只会向上走或者向左走，而且卡多不走回头路。（即：一个点最多经过一次）。当然卡多顺手也拿走沿路的每个宝物。

Dr.Kong希望他的机器人卡多尽量多地带出宝物。请你编写程序，帮助Dr.Kong计算一下，卡多最多能带出多少宝物。
输入
第一行： K 表示有多少组测试数据。 
接下来对每组测试数据：
第1行: M N
第2~M+1行： Ai1 Ai2 ……AiN (i=1,…..,m)


【约束条件】
2≤k≤5 1≤M, N≤50 0≤Aij≤100 (i=1,….,M; j=1,…,N)
所有数据都是整数。 数据之间有一个空格。
输出
对于每组测试数据，输出一行：机器人卡多携带出最多价值的宝物数
样例输入
2
2 3
0 10 10
10 10 80
3 3
0 3 9
2 8 5
5 7 100
样例输出
120
134
*/ 
