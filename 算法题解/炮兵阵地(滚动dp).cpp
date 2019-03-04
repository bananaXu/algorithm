#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

#define MAX(a, b) a > b ? a : b 

int dp[2][61][61]; // 用来滚动存放上行的当前状态和上一状态以及当前行的当前状态和上一状态
int c[3][61]; // 用这个数组存放当前行，前一行，前前行所有状态 
char a[105][15]; // 输入的图 
int num[61]; // 存储当前行的当前状态所放的炮兵数 
int m, n;
// 第i行，第j列，二进制数sum，当前行x，状态数z，当前状态炮兵数 
void GetC(int i, int j, int sum, int x, int &z, int y)
{
	if (j == n+1)
	{
		c[x][++ z] = sum;
		num[z] = y;
		return;
	}
	sum <<= 1;
	if (a[i][j-1] == 'P' && !((sum>>1)&1) && !((sum>>2)&1))
		GetC(i, j+1, sum+1, x, z, y+1);
	GetC(i, j+1, sum, x, z, y);	
}

int main()
{
	// 滚动index，p，q，r分别表示前前行，前一行，当前行
	// x，y，z分别表示前前行状态数，前一行状态数，当前行状态数
	int i, j, k, l, index, t, p, q, r, x, y, z, max;
	cin >> t;
	while(t --)
	{
		cin >> m >> n;
		if (m == 0 || n == 0)
		{
			cout << 0 << endl;
			continue;
		}
		memset(dp, 0, sizeof(dp));
		memset(c, 0, sizeof(c));
		for (i = 1; i <= m; i ++)
		{
			scanf("%s", &a[i]);
		}
		index = 0;
		p = 0;
		q = 1;
		r = 2;
		x = 1;
		y = 0;
		z = 0;
		GetC(1, 1, 0, q, y, 0); // 第0行就一个状态0，处理第一行 
		for (i = 1; i <= y; i ++)
			dp[index][i][1] = num[i];
		for (i = 2; i <= m; i ++)
		{
			GetC(i, 1, 0, r, z, 0); // 获得当前行可行状态 
			for (j = 1; j <= z; j ++)
			{
				for (k = 1; k <= y; k ++)
				{
					dp[1-index][j][k] = 0;
					for (l = 1; l <= x; l ++)
					{   // 三个状态不冲突 
						if ((c[p][l]|c[q][k]|c[r][j]) == c[p][l]+c[q][k]+c[r][j])
							dp[1-index][j][k] = MAX(dp[1-index][j][k], dp[index][k][l]+num[j]);
					}
				}
			}
			index = 1-index;
			x = y;
			y = z;
			z = 0;
			p = q;
			q = r;
			r = 3-p-q;
		}
		max = 0;
		for (i = 1; i <= x; i ++)
		{
			for (j = 1; j <= y; j ++)
				max = MAX(max, dp[index][j][i]);
		}
		cout << max << endl;	
	}
	return 0;
}
/*
描述
司令部的将军们打算在N*M的网格地图上部署他们的炮兵部队。一个N*M的地图由N行M列组成，地图的每一格可能是山地（用"H" 表示），也可能是平原（用"P"表示），如下图。在每一格平原地形上最多可以布置一支炮兵部队（山地上不能够部署炮兵部队）；一支炮兵部队在地图上的攻击范围如图中黑色区域所示： 
如果在地图中的灰色所标识的平原上部署一支炮兵部队，则图中的黑色的网格表示它能够攻击到的区域：沿横向左右各两格，沿纵向上下各两格。图上其它白色网格均攻击不到。从图上可见炮兵的攻击范围不受地形的影响。 
现在，将军们规划如何部署炮兵部队，在防止误伤的前提下（保证任何两支炮兵部队之间不能互相攻击，即任何一支炮兵部队都不在其他支炮兵部队的攻击范围内），在整个地图区域内最多能够摆放多少我军的炮兵部队。
输入
第一行输出数据测试组数X（0<X<100）
接下来每组测试数据的第一行包含两个由空格分割开的正整数，分别表示N和M； 接下来的N行，每一行含有连续的M个字符('P'或者'H')，中间没有空格。按顺序表示地图中每一行的数据。0<=N <= 100；0<=M <= 10。
输出
每组测试数据输出仅一行，包含一个整数K，表示最多能摆放的炮兵部队的数量。
样例输入
1
5 4
PHPP
PPHH
PPPP
PHPP
PHHP
样例输出
6
*/ 
