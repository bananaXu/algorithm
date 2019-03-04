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

/*
题目大意：
求n个矩形组成的面积
方法：线段树扫描法
从下往上扫描，矩形下边标记为1，上边标记为-1
遇到一条边，加上或减去这条边，剩余的部分乘以两y的差就是这部分面积，
扫描完整个部分即为所求面积 
*/

#define M 20005
#define mid ((l+r)>>1)
#define lson (i<<1), l, mid
#define rson (i<<1)+1, mid+1, r

double x[M], num[M<<1];
int sum[M<<1];

struct EDGE
{
	EDGE(){};
	EDGE(double a, double b, double c, int d):x1(a), x2(b), y(c), t(d){};
	double x1, x2, y;
	int t;
	bool operator <(const EDGE &a)const{return y < a.y;}
}edge[M];

void getnum(int i, int l, int r)
{
	if (sum[i])
		num[i] = x[r+1]-x[l];
	else if (l == r)
		num[i] = 0.0;
	else
		num[i] = num[i<<1]+num[(i<<1)+1];
}

void update(int i, int l, int r, int m ,int n, int val)
{
	if (m <= l && r <= n)
	{
		sum[i] += val;
		getnum(i, l, r);
		return;
	}
	if (m <= mid)
		update(lson, m, n, val);
	if (n > mid)
		update(rson, m, n, val);
	getnum(i, l, r);
}

int findx(int l, int r, double val)
{
	while (l <= r)
	{
		if (val == x[mid])
			return mid;
		else if (val < x[mid])
			r = mid-1;
		else
			l = mid+1;
	}
	return -1;
}

int main() 
{
	int n, Case = 0;
	while (scanf("%d", &n) && n != 0)
	{
		int m = 0;
		for (int i = 1; i <= n; i ++)
		{
			double x1, x2, y1, y2;
			scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
			x[m] = x1;
			edge[m ++] = EDGE(x1, x2, y1, 1);
			x[m] = x2;
			edge[m ++] = EDGE(x1, x2, y2, -1);
		}
		sort(x, x+m);
		sort(edge, edge+m);
		int t = 1;
		for (int i = 1; i < m; i ++)
		{
			if (x[i] != x[i-1])
				x[t ++] = x[i];
		}
		memset(num, 0, sizeof(num));
		memset(sum, 0, sizeof(sum));
		double s = 0.0;
		for (int i = 0; i < m-1; i ++)
		{
			int l = findx(0, t-1, edge[i].x1);
			int r = findx(0, t-1, edge[i].x2)-1;
			if (l <= r)
				update(1, 0, t-1, l, r, edge[i].t);
			s += num[1]*(edge[i+1].y-edge[i].y);
		}
		printf("Test case #%d\nTotal explored area: %.2lf\n\n", ++ Case, s);
	}
	return 0;
}

/*
4
10 10 15 15
12.4 12.5 22.3 22.4
14.7 14.8 23.4 23.3
18.5 18.6 24.2 21.3

Atlantis
时间限制：1000 ms  |  内存限制：65535 KB
难度：6
描述
There are several ancient Greek texts that contain descriptions of the fabled island Atlantis. Some of these texts even include maps of parts of the island. But unfortunately, these maps describe different regions of Atlantis. Your friend Bill has to know the total area for which maps exist. You (unwisely) volunteered to write a program that calculates this quantity.
输入
The input consists of several test cases. Each test case starts with a line containing a single integer n (1 <= n <= 10000) of available maps. The n following lines describe one map each. Each of these lines contains four numbers x1;y1;x2;y2 (0 <= x1 < x2 <= 100000;0 <= y1 < y2 <= 100000), not necessarily integers. The values (x1; y1) and (x2;y2) are the coordinates of the top-left resp. bottom-right corner of the mapped area. 
The input file is terminated by a line containing a single 0. Don't process it.
输出
For each test case, your program should output one section. The first line of each section must be "Test case #k", where k is the number of the test case (starting with 1). The second one must be "Total explored area: a", where a is the total explored area (i.e. the area of the union of all rectangles in this test case), printed exact to two digits to the right of the decimal point. 
Output a blank line after each test case.
样例输入
2
10 10 20 20
15 15 25 25.5
0
样例输出
Test case #1
Total explored area: 180.00 
*/
