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
#include <cfloat>
using namespace std;

#define M 5005
#define MAX(a, b) a > b ? a : b

struct Node
{
	int l;
	int r;
	int v;
	bool operator <(const Node &p)const {return r < p.r;}
}node[M];

int dp[M];

int main()
{
	int i, j, n, Max;
	while (~scanf("%d", &n))
	{
		for (i = 1; i <= n; i ++)
			scanf("%d%d%d", &node[i].l, &node[i].r, &node[i].v);
		sort(node+1, node+n+1);
		for (i = 1; i <= n; i ++)
		{
			dp[i] = node[i].v;
			for (j = 1; node[j].r < node[i].l; j ++)
				dp[i] = MAX(dp[i], dp[j]+node[i].v);
		}
		Max = 0;
		for (i = 1; i <= n; i ++)
			Max = MAX(Max, dp[i]);
		printf("%d\n", Max);
	}
	return 0;
}
