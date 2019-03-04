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

#define M 205
#define INF 0x3f3f3f3f
#define MOD 1000000009

struct POINT // 保存点的信息 
{
	int dis;
	int num;
}point[M][M];

struct Point
{
	int x;
    int y;
    int dis;
	bool operator < (const struct Point &a)const {return this->dis > a.dis;}
}; // 为排序准备的类 

priority_queue <Point> pq; // 优先队列 
int vis[M][M]; // 是否访问过 
int a[M][M]; // 点的值 
int n;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // 方向 

int getNum()
{
	Point p;
	p.x = 1; p.y = 1; p.dis = 0;
	pq.push(p); // 将原点压入优先队列 
	int i, j, l, r, min, num, x, y, dis;
	point[1][1].num = 1;
	memset(vis, 0, sizeof(vis));
	min = INF; num = 0;
	while (!pq.empty())
	{
		p = pq.top();
		x = p.x; y = p.y; dis = p.dis;
		vis[x][y] = 1;
		pq.pop();
		if (x+y == n+1) // 如果是终点 
		{
			if (dis < min) // 由于是优先队列，当找到第一个点时就是最小距离 
			{
				min = dis; // 传入最小距离 
				num = (num+point[x][y].num)%MOD;
			}
			else if (p.dis == min) // 如果这个终点也是最小距离 
				num = (num+point[x][y].num)%MOD;
			else // 大于最小距离,队列置空，为下组数据准备 
			{
				while(!pq.empty()) pq.pop();
				return num;
			}
		}
		else
		{
			for (i = 0; i <= 3; i ++)
			{
				l = x+dir[i][0];
				r = y+dir[i][1]; // 四个方向的点 
				// 如果这个点合法并且(没有出队列过或距离不变)
				if (l && r && l+r <= n+1 && dis+a[l][r] <= point[l][r].dis) 
				{	// 距离不变，那么到这个点方法数加上到达上个点的方法数
					// 由于是优先队列且方法数与路径无关，出队列一个点时已经将所有到达这个点的累加
					// 所以可以直接相加 
					point[l][r].num = (point[l][r].num+point[x][y].num)%MOD;
					if (!vis[l][r] && dis+a[l][r] < point[l][r].dis) // 未出队列过且距离可更新 
					{
						point[l][r].dis = dis+a[l][r];
						p.x = l; p.y = r; p.dis = point[l][r].dis;
						pq.push(p);	
					}
				}
			}
		}
	}
	return num;
}

int main()
{
	int i, j, x;
	while (1)
	{
		scanf("%d", &n);
		if (n == 0)
			break;
		memset(a, 0, sizeof(a));
		for (i = 1; i <= n; i ++)
		{
			for (j = 1; j <= n; j ++)
			{
				scanf("%d", &x);
				if (i+j <= n+1)
					a[i][j] += x; // 沿对角线相加 
				else
					a[n+1-j][n+1-i] += x;
			}
		}
		for (i = 1; i <= n; i ++)
		{
			for (j = 1; j+i <= n+1; j ++)
			{
				point[i][j].dis = INF; // 先将每个点距原点距离置为最大，到达这个点的方法数置为0 
				point[i][j].num = 0;
			}
		}
		printf("%d\n", getNum());
	}
	return 0;
}
/*
最优对称路径
时间限制：1000 ms  |  内存限制：65535 KB
难度：3
描述
    给一个 n 行 n 列的网格，每个格子里有一个 1 到 9 的数字。你需要从左上角走到右下角，
	其中每一步只能往上、下、左、右四个方向之一走到相邻格子，不能斜着走，也不能走出网格，
	但可以重复经过一个格子。为了美观，你经过的路径还必须关于“左下-右上”这条对角线对称。下
	图是一个 6x6 网格上的对称路径。
    你的任务是统计所有合法路径中，数字之和最小的路径有多少条。
输入
输入最多包含 25 组测试数据。每组数据第一行为一个整数 n（2<=n<=200）。以下 n 行每行包含 n 个 1 到 9
的数字，表示输入网格。输入结束标志为 n=0。
输出
对于每组数据，输出合法路径中，数字之和最小的路径条数除以 1,000,000,009 的余数。
样例输入
2 
1 1 
1 1 
3 
1 1 1 
1 1 1 
2 1 1 
0 
样例输出
2 
3
*/
