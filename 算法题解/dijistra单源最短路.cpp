#include <iostream>
#include <queue>
using namespace std;
#define MAX 1000
#define MaxInt 0x7fffffff/10

struct Edge // 存储边 
{
	int val;
	int next;
	int r;
}edge[4*MAX+5];

struct Dis// 离源点距离 
{
	int i;
	int val;
	bool operator<(const struct Dis &a)const
	{
		return this->val < a.val;
	}
}dis[MAX+5];
int n, m; // 边数与点数 
int head[MAX+5]; // 以领接表方式存储节点 
int close[MAX+5]; // 是否关闭，1、是，2、否 
int I = 0;
priority_queue <Dis>open;

void insert(int l, int r, int val)
{
	edge[I].val = val;
	edge[I].next = head[l];
	edge[I].r = r;
	head[l] = I++;
}

void Dijkstra(int begin)
{
	Dis d;
	int now; // 当前节点 
	int i, r;
	open.push(dis[begin]);
	while(1)
	{
		d = open.top();
		now = d.i;
		if (now == m)
			return;
		open.pop();
		for (i = head[now]; i != -1; i = edge[i].next)
		{
			r = edge[i].r;
			if (dis[now].val+edge[i].val < dis[r].val)
			{
				dis[r].val = dis[now].val+edge[i].val;
				open.push(dis[r]);
			}
		}
	}
}

int main()
{
	int i, l, r, val;
	cin >> m >> n;
	for (i = 0; i <= MAX; i ++)
	{
		head[i] = -1;
		dis[i].i = i;
		dis[i].val = MaxInt;
		close[i] = 0;
	}
	for (i = 1; i <= n; i ++)
	{
		cin >> l >> r >> val;
		insert(l, r, val);
		insert(r, l, val);
	}
	dis[1].val = 0;
	Dijkstra(1);
	cout << dis[m].val << endl;
	return 0;
}
// 测试数据 
/*
5 5
1 2 1
2 3 1
3 4 1
4 5 2
4 5 1
*/
/*
1 4
1 1 1
1 1 1
1 1 1
1 1 1
*/
/*
9 12
1 3 1
3 5 2
5 7 4
7 9 3
1 2 3
2 3 5
3 4 3
4 5 6
5 6 3
6 7 5
7 8 3
8 9 2
*/
