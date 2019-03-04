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

// ��С������prim 
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
