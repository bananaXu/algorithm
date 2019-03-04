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
����
�Ͻ�����������ಿ�ӣ����Ƿֱ�פ����N����ͬ�ĳ������Щ���зֱ���1~N�����ڽ�ͨ��̫�������Ͻ���׼����·��
�����Ѿ�֪����Щ����֮�������·�������·�������Ƕ��١�
���ڣ���ʦС���Ѿ��ҵ���һ����·�ķ������ܹ�ʹ�������ж���ͨ���������һ������١�
���ǣ��Ͻ���˵�������·������ƴ�ɵ�ͼ���ܲ�����������С������һ���Ƿ��������һ�ַ������Ѻ͸ղŵķ���һ��������������С��дһ��������һ�°ɡ�
����
��һ������һ������T(1<T<20)����ʾ�������ݵ�����
ÿ��������ݵĵ�һ������������V,E��(3<V<500,10<E<200000)�ֱ��ʾ���еĸ����ͳ���֮��·�����������ݱ�֤���еĳ��ж���·������
����E�У�ÿ������������A B L����ʾA�ų�����B�ų���֮����·����ΪL��
���
����ÿ������������Yes��No����������������ϵ���С���ѷ��������Yes,�����С���ѵķ���ֻ��һ�֣������No)
��������
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
�������
No
Yes
*/ 
