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
using namespace std;

#define INF 0x3f3f3f3f

int a[105][105];
bool vis[105][105];
int Dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, Max, Min;

bool dfs(int x, int y, int l, int r)
{
	int i, p, q;
	vis[x][y] = true;
	if (a[x][y] >= l && a[x][y] <= r)
	{
		if (x == n && y == n) // 找到了一条满足(l, r)区间的路 
			return true;
		for (i = 0; i <= 3; i ++) // 向四个方向搜索 
		{
			p = x+Dir[i][0];
			q = y+Dir[i][1];
			if (p && q && q <= n && p <= n && !vis[p][q])
			{
				if (dfs(p, q, l, r))
					return true;	
			}
		}
	}
	return false;
}

int Search(int l, int r) // 二分查找最大值与最小值差 
{
	if (l == r)
		return l;
	int mid = (l+r)>>1;
	int i;
	for (i = Min; i <= Max-mid; i ++) // 枚举差值为mid的最大值与最小值所在区间 
	{
		memset(vis, false, sizeof(vis));
		if (dfs(1, 1, i, i+mid)) // 深度遍历搜索(i, i+mid)这个区间是否能走通 
			return Search(l, mid);
	}
	return Search(mid+1, r); // 差值mid走不通 
}

int main()
{
	int i, j;
	while(~scanf("%d", &n))
	{
		Max = -INF;
		Min = INF;
		for (i = 1; i <= n; i ++)
		{
			for (j = 1; j <= n; j ++)
			{
				scanf("%d", &a[i][j]);
				if (a[i][j] > Max)
					Max = a[i][j];
				if (a[i][j] < Min)
					Min = a[i][j];
			}
		}
		printf("%d\n", Search(0, Max-Min));
	}
	return 0;
}
/*
走迷宫
时间限制：1000 ms  |  内存限制：65535 KB
难度：5
描述
Dr.Kong设计的机器人卡多非常爱玩，它常常偷偷跑出实验室，在某个游乐场玩之不疲。这天卡多又跑出来了，在SJTL游乐场玩个不停，坐完碰碰车，又玩滑滑梯，这时卡多又走入一个迷宫。整个迷宫是用一个N * N的方阵给出，方阵中单元格中填充了一个整数，表示走到这个位置的难度。
这个迷宫可以向上走，向下走，向右走，向左走，但是不能穿越对角线。走迷宫的取胜规则很有意思，看谁能更快地找到一条路径，其路径上单元格最大难度值与最小难度值之差是最小的。当然了，或许这样的路径不是最短路径。
     机器人卡多现在在迷宫的左上角（第一行，第一列）而出口在迷宫的右下角（第N行，第N列）。
卡多很聪明，很快就找到了这样的一条路径。你能找到吗？
输入
有多组测试数据，以EOF为输入结束的标志
第一行： N 表示迷宫是N*N方阵 (2≤ N≤ 100)
接下来有N行，	每一行包含N个整数，用来表示每个单元格中难度 (0≤任意难度≤120)。
输出
输出为一个整数，表示路径上最高难度与和最低难度的差。
样例输入
5
1 1 3 6 8
1 2 2 5 5
4 4 0 3 3
8 0 2 3 4
4 3 0 2 1
样例输出
2
*/
