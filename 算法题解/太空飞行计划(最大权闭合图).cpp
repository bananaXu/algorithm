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

#define N 205
#define M 20005
#define INF 0x3f3f3f3f
#define MIN(a, b) a < b ? a : b 

struct Edge
{
	int r;
	int allowflow;
	int next;
}edge[M];

int head[N]; 	// 边的起点 
int d[N]; 	 	// 距离汇点t的距离 
int num[N];     // 该距离的数量 
int Index;   	// 边的索引 
int n, m, s, t, sum; // n个节点，m条边，源点s，汇点t 

void insert(int l, int r, int allowflow) // 插入边以及允许通过的流量 
{
	edge[Index].r = r;
	edge[Index].allowflow = allowflow;
	edge[Index].next = head[l];
	head[l] = Index ++;
}

void bfs() // 从汇点t进行bfs，找到所有点距离汇点的距离 
{
	int i;
	memset(d, INF, (n+1)*sizeof(int));
	queue <int> iq;
	iq.push(t);
	d[t] = 0;
	while (!iq.empty())
	{
		int x = iq.front();
		iq.pop();
		for (i = head[x]; i != -1; i = edge[i].next)
		{
			int r = edge[i].r, allowflow = edge[i].allowflow;
			if (!allowflow && d[x]+1 < d[r]) // 该边是反向的，并且从x到r距离没被更新过 
			{
				d[r] = d[x]+1;
				num[d[r]] ++;
				iq.push(r);
			}
		}
	}
} 

int augment(int x, int Maxflow) // 以x开头流量不超过Maxflow的路径 
{	
	if (x == t) // 到达汇点 
		return Maxflow;
	int flow = 0;
	for (int i = head[x]; i != -1; i = edge[i].next) // x点连接的所有边 
	{
		int r = edge[i].r, allowflow = edge[i].allowflow;
		if (d[x] == d[r]+1) // 距离为d[x]-1 
		{
			int Temp = augment(r, MIN(Maxflow, allowflow)); 
			flow += Temp, Maxflow -= Temp, edge[i].allowflow -= Temp, edge[i^1].allowflow += Temp;
			if (!Maxflow) // 流量用完 
				return flow; 
		}
	}
	// 与x点连接的所有d[x]-1距离的边用完 
	if (!(-- num[d[x]]))  
		d[s] = n+1;
	++ num[++ d[x]];
	return flow;
} 

void init()
{
	Index = 0; sum = 0; s = 0; t = n+m+1;
	memset(head, -1, sizeof(head));
	memset(num, 0, sizeof(num)); 
	int i, j;
	for (i = 1; i <= n; i ++)
	{
		int f, t;
		scanf("%d%d", &f, &t);
		sum += f;
		insert(0, i, f);
		insert(i, 0, 0);
		for (j = 1; j <= t; j ++)
		{
			int v;
			scanf("%d", &v);
			insert(i, v+n, INF);
			insert(v+n, i, 0);
		}
	} 
	for (i = 1; i <= m; i ++)
	{
		int pi;
		scanf("%d", &pi);
		insert(i+n, n+m+1, pi);
		insert(n+m+1, i+n, 0);
	}
	n = n+m+2;
	bfs();
}

int ISAP()
{
	init();
	int flow = augment(s, INF);
	while (d[s] <= n) flow += augment(s, INF);
	return sum-flow; 
}

int main()
{
	while (~scanf("%d%d", &n, &m)) 
	{
		printf("%d\n", ISAP());
	}
	return 0;
} 
/*
太空飞行计划
时间限制：1000 ms  |  内存限制：65535 KB
难度：4
描述
W 教授正在为国家航天中心计划一系列的太空飞行。每次太空飞行可进行一系列商业性实验而获取利润。
现已确定了一个可供选择的实验集合E={E1，E2，…，Em}，和进行这些实验需要使用的全部仪器的集合
I={I1，I2，…In}。实验Ej需要用到的仪器是I的子集Rj 。配置仪器Ik的费用为ck美元。实验Ej的赞助
商已同意为该实验结果支付pj美元。W教授的任务是找出一个有效算法，确定在一次太空飞行中要进行哪
些实验并因此而配置哪些仪器才能使太空飞行的净收益最大。这里净收益是指进行实验所获得的全部收入
与配置仪器的全部费用的差额。
对于给定的实验和仪器配置情况，编程找出净收益最大的试验计划。

输入
多组测试数据（不超过500组）
每组数据第1行有2 个正整数m和n(m,n <= 100)。m是实验数，n是仪器数。接下来的m 行，每行是一个实验的有关数据。第一个数赞助商同意支付该实验的费用f(f < 10000)；接着是该实验需要用到的仪器的个数t，接着是t个仪器的编号。最后一行的n个数是配置每个仪器的费用pi(pi <=100）。
输出
每组数据输出占一行，输出最大的净收益（如果无法收益，输出0）。
样例输入
2 3
10 2 1 2
25 2 2 3
5 6 7
样例输出
17
*/
