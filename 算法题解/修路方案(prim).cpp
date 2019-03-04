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
#define M 505
#define MAX(a, b) a > b ? a : b

struct EDGE
{
	int r;
	int next;
	int val;
}edge[400005];

struct node
{
	node(){}
	node(int x, int v){i = x; dis = v;}
	int i;
	int dis;
	bool operator<(const node a) const
	{
		return dis > a.dis;
	}
};

int head[M];
int used[M];
int dis[M];
int maxd[M][M];
int father[M];
int I, n, m;
priority_queue <node> nq;

void insert(int l, int r, int val)
{
	edge[I].r = r;
	edge[I].val = val;
	edge[I].next = head[l];
	head[l] = I ++;
}

void prim()
{
	int i, r, val, now = 1, sum = 1;
	node x;
	while (!nq.empty()) nq.pop();
	nq.push(node(1, 0));
	dis[1] = 0;
	used[1] = 1;
	maxd[1][0] = maxd[0][1] = 0;
	while (sum < n)
	{
		for (i = head[now]; i != -1; i = edge[i].next)
		{
			r = edge[i].r;
			val = edge[i].val;
			if (!used[r] && val < dis[r])
			{
				dis[r] = val;
				father[r] = now;
				nq.push(node(r, val));
			}
		}
		x = nq.top();
		nq.pop();
		while(used[x.i])
		{
			x = nq.top();
			nq.pop();
		}
		now = x.i;
		used[x.i] = 1;
		sum ++;
		for (i = 1; i <= n; i ++)
		{
			if (used[i] && i != now)
			{
				if (father[now] == i)
					maxd[i][now] = maxd[now][i] = x.dis;
				else
					maxd[i][now] = maxd[now][i] = MAX(maxd[father[now]][i], x.dis);
			}
		}
	}
}

// 次小生成树prim 
int main()
{
	int i, j, t, l, r, val;
	bool find;
	scanf("%d", &t);
	while (t --)
	{
		scanf("%d%d", &n, &m);
		memset(head, -1, (n+1)*sizeof(int));
		memset(dis, INF, (n+1)*sizeof(int));
		memset(used, 0, (n+1)*sizeof(int));
		memset(father, 0, (n+1)*sizeof(int));
		I = 0;	
		for (i = 1; i <= m; i ++)
		{
			scanf("%d%d%d", &l, &r, &val);
			insert(l, r, val);
			insert(r, l, val);
		}
		prim();
		find = false;
		for (i = 1; !find && i <= n; i ++)
		{
			for (j = head[i]; !find && j != -1; j = edge[j].next)
			{
				r = edge[j].r;
				val = edge[j].val;
				if (father[i] != r && father[r] != i && maxd[i][r] == val)
					find = true;
			}
		}
		if (find)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
} 
/*
描述
南将军率领着许多部队，它们分别驻扎在N个不同的城市里，这些城市分别编号1~N，由于交通不太便利，南将军准备修路。

现在已经知道哪些城市之间可以修路，如果修路，花费是多少。

现在，军师小工已经找到了一种修路的方案，能够使各个城市都联通起来，而且花费最少。

但是，南将军说，这个修路方案所拼成的图案很不吉利，想让小工计算一下是否存在另外一种方案花费和刚才的方案一样，现在你来帮小工写一个程序算一下吧。

输入
第一行输入一个整数T(1<T<20)，表示测试数据的组数
每组测试数据的第一行是两个整数V,E，(3<V<500,10<E<200000)分别表示城市的个数和城市之间路的条数。数据保证所有的城市都有路相连。
随后的E行，每行有三个数字A B L，表示A号城市与B号城市之间修路花费为L。
输出
对于每组测试数据输出Yes或No（如果存在两种以上的最小花费方案则输出Yes,如果最小花费的方案只有一种，则输出No)
样例输入
2
3 3
1 2 1
2 3 2
3 1 3
4 4
1 2 2
2 3 2
3 4 2
4 1 2
样例输出
No
Yes
2
4 4
1 2 2
2 3 2
3 4 2
4 1 2
5 5
1 2 5
1 3 4
2 3 5
4 5 7
3 4 5
*/ 
