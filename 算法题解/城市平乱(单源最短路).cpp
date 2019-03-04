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
����
�Ͻ���ͳ����N�����ӣ���N�����ӷֱ�פ����N����ͬ�ĳ��С�

��������N������ά����M�����е��ΰ�����M�����зֱ��Ŵ�1��M��

���ڣ�С����ʦ�����Ͻ�������K�ų��з����˱��ң��Ͻ����Ӹ������Ӷ���ǲ��һ���ֶ������·ȥ�����ҳ���ƽ�ҡ�

������֪��������������֮���·�о������ʱ�䣬����Ϊ�Ͻ��������������ĳ���Ա�������дһ�������������Ͻ�����һ���ֶӵ������ҳ��������ʱ�䡣



ע�⣬��������֮����ܲ�ֻһ��·��

����
��һ������һ������T����ʾ�������ݵ�������(T<20)
ÿ��������ݵĵ�һ�����ĸ�����N,M,P,Q(1<=N<=100,N<=M<=1000,M-1<=P<=100000)����N��ʾ��������M��ʾ��������P��ʾ����֮���·������,Q��ʾ�������ҵĳ��б�š�
����һ����N����������ʾ�������ڳ��еı�š�
��֮���P�У�ÿ����������������a,b,t(1<=a,b<=M,1<=t<=100)����ʾa,b֮���·����о���Ҫ��ʱΪt

���ݱ�֤���ҵĳ����ǿɴ�ġ�
���
����ÿ��������ݣ������һ֧���ӵ������ҳ���ʱ��ʱ�䡣ÿ�����ռһ��
��������
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
�������
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
