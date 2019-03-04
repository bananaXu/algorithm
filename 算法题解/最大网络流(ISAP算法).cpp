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

#define N 100
#define M 10000
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
int index;   	// 边的索引 
int n, m, s, t; // n个节点，m条边，源点s，汇点t 

void insert(int l, int r, int allowflow) // 插入边以及允许通过的流量 
{
	edge[index].r = r;
	edge[index].allowflow = allowflow;
	edge[index].next = head[l];
	head[l] = index ++;
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
	int flow = 0, Nextd = n+1;
	for (int i = head[x]; i != -1; i = edge[i].next) // x点连接的所有边 
	{
		int r = edge[i].r, allowflow = edge[i].allowflow;
		if (d[x] == d[r]+1) // 距离为d[x]-1 
		{
			int Temp;
			Temp = augment(r, MIN(Maxflow, allowflow)); 
			flow += Temp, Maxflow -= Temp, edge[i].allowflow -= Temp, edge[i^1].allowflow += Temp;
			if (!Maxflow) // 流量用完 
				return flow; 
		}
		else
			Nextd = MIN(d[r]+1, Nextd); 
	}
	// 与x点连接的所有d[x]-1距离的边用完 
	if (!(-- num[d[x]]))  
		d[s] = n+1;
	d[Nextd] ++;
	++ num[d[Nextd]];
	return flow;
} 

void init()
{
	scanf("%d%d", &n, &m);
	index = 0;
	memset(head, -1, sizeof(head));
	memset(num, 0, sizeof(num)); 
	for (int i = 1; i <= m; i ++)
	{
		int l, r, flow; // 边的端点以及流量 
		scanf("%d%d%d", &l, &r, &flow);
		insert(l, r, flow); // 正向允许流为flow，反向允许流为为0 
	 	insert(r, l, 0);
	} 
	bfs();
}

int ISAP()
{
	init();
	int flow = augment(s, INF);
	while (d[s] <= n) flow += augment(s, INF);
	return flow; 
}

int main()
{
	printf("%d\n", ISAP());
	return 0;
} 
