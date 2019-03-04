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

#define Ma 200005
#define M 505
#define MAX(a, b) a > b ? a : b

struct EDGE
{
	int l;
	int r;
	int val;
	bool operator<(const EDGE a) const
	{
		return val < a.val;
	}
}edge[Ma];

struct NODE
{
	int r;
	int next;
	int val;
}node[1005];

int n, m, I;
int father[M];
bool used[Ma];
bool use[M];
int head[M];

int findfather(int x)
{
	while (father[x] != x) x = father[x];
	return x;
}

void insert(int l, int r, int val)
{
	node[I].r = r;
	node[I].val = val;
	node[I].next = head[l];
	head[l] = I ++;
}

int dfs(int l, int r, int val)
{
	int i, nr, m, x;
	if (l == r)
		return val;
	for (i = head[l]; i != -1; i = node[i].next)
	{
		nr = node[i].r;
		if (!use[nr])
		{
			m = MAX(node[i].val, val);
			use[nr] = true;	
			x = dfs(nr, r, m);
			use[nr] = false;
			if (x)
				return x;
		}
	}
	return 0;
}

int main()
{
	int i, t, sum, l, r, val, fl, fr;
	bool find;
	scanf("%d", &t);
	while (t --)
	{
		scanf("%d%d", &n, &m);
		for (i = 1; i <= m; i ++)
			scanf("%d%d%d", &edge[i].l, &edge[i].r, &edge[i].val);
		sum = 0;
		memset(used, false, (m+1)*sizeof(bool));
		memset(head, -1, (n+1)*sizeof(int));
		I = 0;
		sort(edge+1, edge+m+1);
		for (i = 1; i <= n; i ++)
			father[i] = i;
		for (i = 1; sum < n && i <= m; i ++)
		{
			l = edge[i].l;
			r = edge[i].r;
			val = edge[i].val;
			fl = findfather(l); 
			fr = findfather(r);
			if (fl != fr)
			{
				sum ++;
				used[i] = true;
				father[fl] = fr;
				insert(l, r, val);
				insert(r, l, val);
			}
		}
		find = false;
		for (i = 1; !find && i <= m; i ++)
		{
			if (!used[i])
			{
				memset(use, false, (n+1)*sizeof(int));
				use[edge[i].l] = true;
				if (dfs(edge[i].l, edge[i].r, 0) == edge[i].val)
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
*/ 
