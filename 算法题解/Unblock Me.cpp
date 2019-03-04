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

typedef long long ll;
typedef pair<ll, int> P;

struct EDGE
{
	int x;
	int len;
	int dir;
}edge[20];

int n, r;
set <ll> vis;
int Map[10][10];

bool check(ll s)
{
	ll v = (s&(7ll<<(r*3)))>>(r*3);
	if (v+edge[r].len == 6)
		return true;
	return false;
}

void buildmap(ll s)
{
	memset(Map, 0, sizeof(Map));
	for (int i = 0; i < n; i ++)
	{
		int v = (s&(7ll<<(i*3)))>>(i*3);
		for (int j = 0; j < edge[i].len; j ++)
		{
			if (!edge[i].dir)
				Map[edge[i].x][v+j] = 1;
			else
				Map[v+j][edge[i].x] = 1;
		}
	}
}

bool CanMoveBack(int x, int i)
{
	if (!edge[i].dir && Map[edge[i].x][x+edge[i].len-1])
		return false;
	if (edge[i].dir && Map[x+edge[i].len-1][edge[i].x])
		return false;
	return true;
}

bool CanMoveAhead(int x, int i)
{
	if (!edge[i].dir && Map[edge[i].x][x])
		return false;
	if (edge[i].dir && Map[x][edge[i].x])
		return false;
	return true;
}

int bfs(ll s)
{
	vis.clear();
	vis.insert(s);
	queue <P> q;
	q.push(make_pair(s, 0));
	while (!q.empty())
	{
		P p;
		p = q.front();
		q.pop();
		if (check(p.first))
			return p.second == 0 ? 1 : p.second;
		for (int i = 0; i < n; i ++)
		{
			int v = (p.first&(7ll<<(i*3)))>>(i*3);
			buildmap(p.first);
			for (int j = v+1; j+edge[i].len <= 6; j ++)
			{
				if (CanMoveBack(j, i))
				{
					ll s1 = p.first;
					s1 &= ~(7ll<<(i*3));
					s1 |= (ll)j<<(i*3);
					if (!vis.count(s1))
					{
						vis.insert(s1);
						q.push(make_pair(s1, p.second+1));
					}
				}
				else
					break;
			}
			for (int j = v-1; j >= 0; j --)
			{
				if (CanMoveAhead(j, i))
				{
					ll s1 = p.first;
					s1 &= ~(7ll<<(i*3));
					s1 |= (ll)j<<(i*3);
					if (!vis.count(s1))
					{
						vis.insert(s1);
						q.push(make_pair(s1, p.second+1));
					}
				}
				else
					break;
			}
		}
	}
	return 0;
}

int main()
{
	while (~scanf("%d", &n))
	{
		int i;
		ll s = 0;
		for (i = 0; i < n; i ++)
		{
			int x1, x2, y1, y2;
			scanf("%*d%d%d%d%d", &x1, &y1, &x2, &y2);
			if (x1 == x2)
			{
				edge[i].dir = 0;
				edge[i].len = y2-y1+1;
				edge[i].x = x1;
				s |= (ll)y1<<(i*3); 
			}
			else
			{
				edge[i].dir = 1;
				edge[i].len = x2-x1+1;
				edge[i].x = y1;
				s |= (ll)x1<<(i*3); 
			}
		}
		scanf("%d", &r);
		printf("%d\n", bfs(s)); 
	}
	return 0;
}
/*
Unblock Me
12
0 0 1 0 2
1 1 0 1 1
2 2 0 2 1
3 3 0 5 0
4 1 2 2 2
5 3 1 3 2
6 4 1 4 2
7 5 1 5 3
8 0 3 1 3
9 2 3 3 3
10 4 3 4 4
11 0 4 0 5
4
16

6*6的面板
有1*3和1*2两种方块 
初始以一定方式放置
要求将3行0列，横置的方块 移到最右边
每个方块只能延与长水平的方向移动
求最少移动次数 
*/
