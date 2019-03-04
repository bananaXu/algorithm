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
#include <map>
#include <cfloat>
using namespace std;

struct Fra
{
	Fra(int m, int n) {x = m; y = n;}
	int x;
	int y;
	bool operator <(const Fra &a)const {return x*a.y < y*a.x;}
};

struct Point
{
	int l;
	int r;
	int val;
	bool operator <(const Point &a)const {return val < a.val;}
}point[5005];

int father[505];

int findfather(int x)
{
	while (father[x] != x) x = father[x];
	return x;
}

int Gcd(int x, int y)
{
	if (x < y)
		swap(x, y);
	while (y)
	{
		x %= y;
		if (x < y)
			swap(x, y);
	}
	return x;
}

int main()
{
	int i, j, n, m, t, S, T;
	scanf("%d", &t);
	while (t --)
	{
		scanf("%d%d", &n, &m);
		for (i = 1; i <= m; i ++)
			scanf("%d%d%d", &point[i].l, &point[i].r, &point[i].val);
		sort(point+1, point+m+1); // �����б������ٶȰ���С�������� 
		scanf("%d%d", &S, &T);
		Fra MinFra(1, 0); // ��С�ķ�������ʼ��Ϊ1/0 
		for (i = m; i >= 1; i --) // ���Ӵ�С�ٶȵı���Ѱ�ҽ������յ㲢��һ������ 
		{
			int Max = point[i].val;
			for (j = 1; j <= n; j ++) // ��ʼ��ÿ��������Ƚڵ� 
				father[j] = j;
			for (j = i; j >= 1; j --) // �ӵ�ǰ�������� 
			{
				int Min = point[j].val;
				Fra nowFra(Max, Min);
				if (MinFra < nowFra) // ��ʱ���ٶȹ�С������ٶ�/��С�ٶȹ��� 
					break;
				int fl = findfather(point[j].l), fr = findfather(point[j].r);
				if (fl != fr) // ������������������㲻��һ�����ϣ������Ǻϲ� 
				{
					father[fl] = fr;
					if (findfather(S) == findfather(T)) // �ϲ��������յ���ͨ 
					{
						if (nowFra < MinFra) // �˾�ϻ�������ɾ 
						{
							MinFra = nowFra;
							break;
						}
					}
				}
			}
		}
	 	int x = MinFra.x, y = MinFra.y;
		if (y == 0) // ��δ�ҵ���ͨS��T��· 
			printf("IMPOSSIBLE\n");
		else if (x%y)
		{
			int GCD = Gcd(x, y);
			printf("%d/%d\n", x/GCD, y/GCD);
		}	
		else
			printf("%d\n", x/y);
	}
	return 0;
}
/*
�����ʵ�·��
ʱ�����ƣ�5000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�5
����
������Ǳ����ĳ�����һ���������С������繲��N����Ԫ�����Ϊ1,2,3,��,N������Щ��Ԫ��M��ͨ�������š�������Ԫ֮������ж���ͨ���������ѿ�������Щͨ���������ζ�����������������һ��ͨ�����ζ��ٶȱ�����һ���ġ���Ȼ�����Ѳ�ϣ����һ��ͨ���ζ�����һ��ͨ���ٶȱ仯̫�󣬷�������ܲ������

���������Ѿ۾�����ԪS�㣬���ζ�����ԪT�㡣��ϣ��ѡ��һ���ζ�������ͨ������ٶ�����С�ٶȱȾ�����С��·�ߣ�Ҳ������ν�����ʵ�·�ߡ�

����
��һ�У� K ��ʾ�ж�����������ݡ� 
��������ÿ��������ݣ�
��1��: N M
��2~M+1�У� Xi Yi Vi (i=1,��..,M)
��ʾ��ԪXi ����ԪYi֮��ͨ�����ٶȱ�����Vi
���һ�У� S T ( S ? T )

��Լ��������
2��K��5 1<N��500 0<M��5000 1�� Xi, Yi , S , T ��N 0< Vi <30000��
Vi������������֮����һ���ո�
���
����ÿ��������ݣ����һ�У������ԪS����ԪTû��·�ߣ������IMPOSSIBLE�����������һ��������ʾ��С���ٶȱȡ������Ҫ�����һ����Լ������
��������
2
3 2
1 2 2
2 3 4
1 3
3 3
1 2 10
1 2 5
2 3 8
1 3
�������
2
5/4
*/
