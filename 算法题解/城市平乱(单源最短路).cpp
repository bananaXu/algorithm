#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define INF 0x3f3f3f3f

struct EDGE
{
	int r;
	int next;
	int val;
}edge[200005];

struct DIS
{
	DIS(){};
	DIS(int a, int b){x = a; d = b;}
	int x;
	int d;
	bool operator<(const DIS &a) const
	{
		return d > a.d;
	}
}dis;

int head[1005];
int way[1005][1005];
int dist[1005];
int I;
bool army[1005];
bool vis[1005];
priority_queue <DIS> dp;
int n, m, p, q;

void insert(int l, int r, int val)
{
	edge[I].r = r;
	edge[I].val = val;
	edge[I].next = head[l];
	head[l] = I ++;
}

void FindArmy()
{
	int i, r, d, x;
	while(!dp.empty()) dp.pop();
	dp.push(DIS(q, 0));
	vis[q] = true;
	dist[q] = 0;
	while(!dp.empty())
	{
		dis = dp.top();
		dp.pop();
		d = dis.d;
		x = dis.x;
		vis[x] = true;
		if (army[x])
		{
			cout << d << endl;
			return;
		}
		for (i = head[x]; i != -1; i = edge[i].next)
		{
			r = edge[i].r;
			if (!vis[r] && d+edge[i].val < dist[r])
			{
				dist[r] = d+edge[i].val;
				dp.push(DIS(r, dist[r]));
			}
		}
	}
}

int main()
{
	int i, j, t, x, y, val;
	cin >> t;
	while (t --)
	{
		cin >> n >> m >> p >> q;
		I = 0;
		memset(army, false, sizeof(army));
		memset(head, -1, sizeof(head));
		memset(vis, false, sizeof(vis));
		memset(way, INF, sizeof(way));
		memset(dist, INF, sizeof(dist));
		for (i = 1; i <= n; i ++)
		{
			cin >> x;
			army[x] = true;
		}
		for (i = 1; i <= p; i ++)
		{
			cin >> x >> y >> val;
			if (val < way[x][y])
			{
				way[x][y] = val;
				way[y][x] = val;
			}
		}
		for (i = 1; i <= m; i ++)
		{
			for (j = 1; j <= m; j ++)
			{
				if (way[i][j] != INF)
					insert(i, j, way[i][j]);
			}
		}
		FindArmy();
	}
	return 0;
}
/*
描述
南将军统领着N个部队，这N个部队分别驻扎在N个不同的城市。

他在用这N个部队维护着M个城市的治安，这M个城市分别编号从1到M。

现在，小工军师告诉南将军，第K号城市发生了暴乱，南将军从各个部队都派遣了一个分队沿最近路去往暴乱城市平乱。

现在已知在任意两个城市之间的路行军所需的时间，你作为南将军麾下最厉害的程序员，请你编写一个程序来告诉南将军第一个分队到达叛乱城市所需的时间。



注意，两个城市之间可能不只一条路。

输入
第一行输入一个整数T，表示测试数据的组数。(T<20)
每组测试数据的第一行是四个整数N,M,P,Q(1<=N<=100,N<=M<=1000,M-1<=P<=100000)其中N表示部队数，M表示城市数，P表示城市之间的路的条数,Q表示发生暴乱的城市编号。
随后的一行是N个整数，表示部队所在城市的编号。
再之后的P行，每行有三个正整数，a,b,t(1<=a,b<=M,1<=t<=100)，表示a,b之间的路如果行军需要用时为t

数据保证暴乱的城市是可达的。
输出
对于每组测试数据，输出第一支部队到达叛乱城市时的时间。每组输出占一行
样例输入
1
3 8 9 8
1 2 3
1 2 1
2 3 2
1 4 2
2 5 3
3 6 2
4 7 1
5 7 3
5 8 2
6 8 2 
样例输出
4

3
3 8 9 8
1 2 3
1 2 1
2 3 2
1 4 2
2 5 3
3 6 2
4 7 1
5 7 3
5 8 2
6 8 2 
3 8 9 7
1 2 3
1 2 1
2 3 2
1 4 2
2 5 3
3 6 2
4 7 1
5 7 3
5 8 2
6 8 2 
4 8 9 7
1 2 4 5
1 2 6
3 2 4
7 8 1
2 8 4
1 5 3
5 8 3
2 4 2
4 5 3
5 2 1
*/
