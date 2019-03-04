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
��ʦ��֪����ĳĳͬѧ���У�������ߵ��Ƕ��٣�����������ģ����ʦ��ѯ�ʡ���Ȼ����ʦ��ʱ����Ҫ����ĳλͬѧ�ĳɼ�. 
��������:
�����������������ݡ�
ÿ�������һ��������������N��M��0 < N <= 30000,0 < M < 5000��,�ֱ����ѧ������Ŀ�Ͳ�������Ŀ��
ѧ��ID��Ŵ�1�ൽN��
�ڶ��а���N��������������N��ѧ���ĳ�ʼ�ɼ������е�i��������IDΪi��ѧ���ĳɼ�
��������M�У�ÿһ����һ���ַ�C��ֻȡ��Q����U������������������A,B,��CΪ'Q'��ʱ��, ��ʾ����һ��ѯ�ʲ�������ѯ��ID��A��B������A,B����ѧ�����У��ɼ���ߵ��Ƕ���
��CΪ��U����ʱ�򣬱�ʾ����һ�����²�����Ҫ���IDΪA��ѧ���ĳɼ�����ΪB��


�������:
����ÿһ��ѯ�ʲ�������һ�����������߳ɼ�.

��������1:
5 7
1 2 3 4 5
Q 1 5
U 3 6
Q 3 4
Q 4 5
U 4 5
U 2 9
Q 1 5

�������1:
5
6
5
9
*/
