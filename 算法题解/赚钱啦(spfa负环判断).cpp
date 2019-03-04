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

#define M 1005
#define INF 0x3f3f3f3f

struct EDGE
{
	int r, next, val;
}edge[M<<1];

int head[M], dis[M], num[M];
bool Inqueue[M];
int n, m, Index;

void init()
{
	memset(head, -1, n*sizeof(int));
	memset(num, 0, n*sizeof(int));
	memset(Inqueue, false, n*sizeof(bool));
	memset(dis, INF, n*sizeof(int));
	Index = 0;
}

void Insert(int l, int r, int val)
{
	edge[Index].r = r;
	edge[Index].val = val;
	edge[Index].next = head[l];
	head[l] = Index ++;
}

void spfa()
{
	queue <int> q;
	Inqueue[0] = true;
	dis[0] = 0;
	q.push(0);
	while (!q.empty())
	{
		int t = q.front();
		num[t] ++;
		if (num[t] > n)
		{
			printf("$$$\n");
			return;
		}
		Inqueue[t] = false;
		q.pop();
		for (int i = head[t]; i != -1; i = edge[i].next)
		{
			int val = edge[i].val, r = edge[i].r;
			if (dis[r] > dis[t]+val)
			{
				dis[r] = dis[t]+val;
				if (!Inqueue[r])
				{
					Inqueue[r] = true;
					q.push(r);
				}
			}
		} 
	}
	printf("%d\n", -dis[n-1]);
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t --)
	{
		scanf("%d%d", &n, &m);
		init();
		for (int i = 1; i <= m; i ++)
		{
			int a, b, c, u, v;
			scanf("%d%d%d%d%d", &a, &b, &c, &u, &v);
			Insert(a, b, c-u);
			Insert(b, a, c-v);
		}
		spfa();
	}
	return 0;
}
/*
某国家里有N个城市，分别编号为0~N-1，一个精明的商人准备从0号城市旅行到N-1号城市，在旅行的过程中，从一个城市移动到另外一个城市需要有一定的花费，并且从A城市移动到B城市的花费和B城市移动到A城市的花费相同，但是，从A城市移动到B城市能赚取的钱和从B城市移动到A城市赚的钱不一定相同。

现在，已知各个城市之间移动的花费和城市之间交易可赚取的金钱，求该商人在从0号城市移动到N-1号城市的过程中最多能赚取多少钱？

输入
第一行是一个整数T(T<=10)表示测试数据的组数
每组测试数据的第一行是两个整数N,M表示，共有N个城市(1<N<=1000),M条路(1<=M<=1000)
随后的M行，每行有5个正整数，前两个数a,b(0<=a,b<N)表示两个城市的编号。后面的三个数c,u,v分别表示在a,b城市之间移动的花费，a城市移动到b城市可赚取的资金，b城市移动到a城市可赚取的资金。
(0<=c,u,v<=1000)
输出
如果商人能够在旅行过程中赚取无限多的资金，则输出$$$
否则输出他在移动过程中最多能赚取的资金数量
如果只会赔钱的话就输出一个负数，表示最少赔的钱数。
样例输入
2
2 1
0 1 10 11 11
3 3
0 1 10 16 0
1 2 10 15 5
0 2 20 32 0
样例输出
$$$
12
*/
