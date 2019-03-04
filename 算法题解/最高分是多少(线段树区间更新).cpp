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

#define M 30005
#define MAX(a, b) a > b ? a : b
#define mid ((l+r)>>1)
#define lson i<<1, l, mid 
#define rson i<<1|1, mid+1, r 

int a[M<<2];

void init(int i, int l, int r)
{
	a[i] = 0;
	if (l == r)
		return;
	init(lson);
	init(rson);
} 

void update(int i, int l, int r, int x, int v)
{
	if (l == r)
	{
		a[i] = v;
		return;
	}
	if (x <= mid)
		update(lson, x, v);
	else
		update(rson, x, v);
	a[i] = MAX(a[i<<1], a[(i<<1)+1]);
}

int fmax(int i, int l, int r, int x, int y)
{
	if (l == x && r == y)
		return a[i];
	if (y <= mid)
		return fmax(lson, x, y);
	if (x > mid)
		return fmax(rson, x, y);
	return MAX(fmax(lson, x, mid), fmax(rson, mid+1, y));
}

int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		init(1, 1, n);
		for (int i = 1; i <= n; i ++)
		{
			int x;
			scanf("%d", &x);
			update(1, 1, n, i, x);
		}
		for (int i = 1; i <= m; i ++)
		{
			char c;
			int x, y;
			scanf("%*c%c%d%d", &c, &x, &y);
			if (c == 'Q')
			{
				if (x > y)
					swap(x, y);
				printf("%d\n", fmax(1, 1, n, x, y));
			}
			else
				update(1, 1, n, x, y);
		}
	}
	return 0;
}
/*
老师想知道从某某同学当中，分数最高的是多少，现在请你编程模拟老师的询问。当然，老师有时候需要更新某位同学的成绩. 
输入描述:
输入包括多组测试数据。
每组输入第一行是两个正整数N和M（0 < N <= 30000,0 < M < 5000）,分别代表学生的数目和操作的数目。
学生ID编号从1编到N。
第二行包含N个整数，代表这N个学生的初始成绩，其中第i个数代表ID为i的学生的成绩
接下来又M行，每一行有一个字符C（只取‘Q’或‘U’），和两个正整数A,B,当C为'Q'的时候, 表示这是一条询问操作，他询问ID从A到B（包括A,B）的学生当中，成绩最高的是多少
当C为‘U’的时候，表示这是一条更新操作，要求把ID为A的学生的成绩更改为B。


输出描述:
对于每一次询问操作，在一行里面输出最高成绩.

输入例子1:
5 7
1 2 3 4 5
Q 1 5
U 3 6
Q 3 4
Q 4 5
U 4 5
U 2 9
Q 1 5

输出例子1:
5
6
5
9
*/
