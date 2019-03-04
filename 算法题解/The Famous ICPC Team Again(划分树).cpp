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

#define M 100005

int a[M];
int tree[20][M];
int toleft[20][M];

void buildTree(int l, int r, int i)
{
	if (l == r)
		return;
	int mid = (l+r)>>1;
	int j = mid, num = 0;
	while (j >= l && a[j --] == a[mid]) num ++;
	int left = l, right = mid+1;
	for (j = l; j <= r; j ++)
	{
		if (j == l)
			toleft[i-1][j] = 0;
		else
			toleft[i-1][j] = toleft[i-1][j-1];
		if (tree[i-1][j] < a[mid])
		{ 
			tree[i][left ++] = tree[i-1][j];
			toleft[i-1][j] ++;
		} 
		else if (tree[i-1][j] > a[mid])
			tree[i][right ++] = tree[i-1][j];
		else if (num -- > 0)
		{
			toleft[i-1][j] ++;
			tree[i][left ++] = tree[i-1][j];
		}
		else
			tree[i][right ++] = tree[i-1][j];
	}
	buildTree(l, mid, i+1);
	buildTree(mid+1, r, i+1);
}

int query(int x, int y, int k, int l, int r, int i)
{
	if (l == r)
		return tree[i][x];
	int mid = (l+r)>>1;
	int xTol = l == x ? 0 : toleft[i][x-1];
	int yTol = toleft[i][y] - xTol;
	if (k <= yTol)
		return query(l+xTol, l+xTol+yTol-1, k, l, mid, i+1);
	else
		return query(mid+x-l+1-xTol, mid+y-l+1-yTol-xTol, k-yTol, mid+1, r, i+1);
}

int main()
{
	int n;
	int Case = 0;
	while (~scanf("%d", &n))
	{
		for (int i = 1; i <= n; i ++)
		{
			scanf("%d", &a[i]);
			tree[0][i] = a[i];
		}
		sort(a+1, a+n+1);
		buildTree(1, n, 1);
		int m;
		scanf("%d", &m);
		printf("Case %d:\n", ++ Case);
		while (m --)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			printf("%d\n", query(x, y, ((x+y)>>1)-x+1, 1, n, 0));
		}
	}
	return 0;
} 
/*
题目大意：
输入一个数组，输入m个查询，查询[x,y]之间的中位数 
*/ 
