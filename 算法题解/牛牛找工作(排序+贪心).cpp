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

struct P
{
	int x, y;
	bool operator <(const P &a)const {return y > a.y;}
}p[M];

struct S
{
	int v, i, x;
}s[M];

int Search(int x, int l, int r)
{
	if (l == r)
		return x >= p[l].x ? l : l+1;
	int mid = ((l+r)>>1);
	if (x < p[mid].x)
		return Search(x, mid+1, r);
	return Search(x, l, mid);
}

bool cmp1(const S &a, const S &b)
{
	return a.v < b.v;
}

bool cmp2(const S &a, const S &b)
{
	return a.i < b.i;
}

int main()
{
	int n, m;
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
		scanf("%d%d", &p[i].x, &p[i].y);
	sort(p+1, p+n+1);
	int Index = 1;
	for (int i = 2, t = p[1].x; i <= n; i ++)
	{
		if (p[i].x < t)
		{
			p[++ Index] = p[i];
			t = p[i].x;
		}
	}
	p[Index+1].x = p[Index+1].y = 0;
	for (int i = 1; i <= m; i ++)
	{
		scanf("%d", &s[i].v);
		s[i].i = i;
	}
	sort(s+1, s+m+1, cmp1);
	for (int i = 1, t = Index; i <= m; i ++)
	{
		t = Search(s[i].v, 1, t);
		s[i].x = p[t].y;
	}
	sort(s+1, s+m+1, cmp2);
	for (int i = 1; i <= m; i ++)
		printf("%d\n", s[i].x);
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
/*
Ϊ���ҵ��Լ�����Ĺ�����ţţ�ռ���ÿ�ֹ������ѶȺͱ��ꡣţţѡ�����ı�׼�����ѶȲ�������������ֵ������£�ţţѡ�񱨳���ߵĹ�������ţţѡ�����Լ��Ĺ�����ţţ��С���������ţţ��æѡ������ţţ��Ȼʹ���Լ��ı�׼������С����ǡ�ţţ��С���̫���ˣ�������ֻ�ð�������񽻸����㡣 
��������:
ÿ���������һ������������
ÿ�����������ĵ�һ�а����������������ֱ��ʾ����������N(N<=100000)��С��������M(M<=100000)��
��������N��ÿ�а����������������ֱ��ʾ��������Ѷ�Di(Di<=1000000000)�ͱ���Pi(Pi<=1000000000)��
��������һ�а���M�����������ֱ��ʾM��С��������ֵAi(Ai<=1000000000)��
��֤������������ı�����ͬ��


�������:
����ÿ��С��飬�ڵ�����һ�����һ����������ʾ���ܵõ�����߱��ꡣһ���������Ա������ѡ��

��������1:
3 3 
1 100 
10 1000 
1000000000 1001 
9 10 1000000000

�������1:
100 
1000 
1001Ϊ���ҵ��Լ�����Ĺ�����ţţ�ռ���ÿ�ֹ������ѶȺͱ��ꡣţţѡ�����ı�׼�����ѶȲ�������������ֵ������£�ţţѡ�񱨳���ߵĹ�������ţţѡ�����Լ��Ĺ�����ţţ��С���������ţţ��æѡ������ţţ��Ȼʹ���Լ��ı�׼������С����ǡ�ţţ��С���̫���ˣ�������ֻ�ð�������񽻸����㡣 
��������:
ÿ���������һ������������
ÿ�����������ĵ�һ�а����������������ֱ��ʾ����������N(N<=100000)��С��������M(M<=100000)��
��������N��ÿ�а����������������ֱ��ʾ��������Ѷ�Di(Di<=1000000000)�ͱ���Pi(Pi<=1000000000)��
��������һ�а���M�����������ֱ��ʾM��С��������ֵAi(Ai<=1000000000)��
��֤������������ı�����ͬ��


�������:
����ÿ��С��飬�ڵ�����һ�����һ����������ʾ���ܵõ�����߱��ꡣһ���������Ա������ѡ��

��������1:
3 3 
1 100 
10 1000 
1000000000 1001 
9 10 1000000000

�������1:
100 
1000 
1001
*/
