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

#define M 1005
#define INF 0x3f3f3f3f

struct EDGE
{
	int r, next, val;
}edge[M<<1];

int head[M], dis[M], num[M];
bool Inqueue[M];
int n, m, Index;

void init()
{
	memset(head, -1, n*sizeof(int));
	memset(num, 0, n*sizeof(int));
	memset(Inqueue, false, n*sizeof(bool));
	memset(dis, INF, n*sizeof(int));
	Index = 0;
}

void Insert(int l, int r, int val)
{
	edge[Index].r = r;
	edge[Index].val = val;
	edge[Index].next = head[l];
	head[l] = Index ++;
}

void spfa()
{
	queue <int> q;
	Inqueue[0] = true;
	dis[0] = 0;
	q.push(0);
	while (!q.empty())
	{
		int t = q.front();
		num[t] ++;
		if (num[t] > n)
		{
			printf("$$$\n");
			return;
		}
		Inqueue[t] = false;
		q.pop();
		for (int i = head[t]; i != -1; i = edge[i].next)
		{
			int val = edge[i].val, r = edge[i].r;
			if (dis[r] > dis[t]+val)
			{
				dis[r] = dis[t]+val;
				if (!Inqueue[r])
				{
					Inqueue[r] = true;
					q.push(r);
				}
			}
		} 
	}
	printf("%d\n", -dis[n-1]);
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t --)
	{
		scanf("%d%d", &n, &m);
		init();
		for (int i = 1; i <= m; i ++)
		{
			int a, b, c, u, v;
			scanf("%d%d%d%d%d", &a, &b, &c, &u, &v);
			Insert(a, b, c-u);
			Insert(b, a, c-v);
		}
		spfa();
	}
	return 0;
}
/*
ĳ��������N�����У��ֱ���Ϊ0~N-1��һ������������׼����0�ų������е�N-1�ų��У������еĹ����У���һ�������ƶ�������һ��������Ҫ��һ���Ļ��ѣ����Ҵ�A�����ƶ���B���еĻ��Ѻ�B�����ƶ���A���еĻ�����ͬ�����ǣ���A�����ƶ���B������׬ȡ��Ǯ�ʹ�B�����ƶ���A����׬��Ǯ��һ����ͬ��

���ڣ���֪��������֮���ƶ��Ļ��Ѻͳ���֮�佻�׿�׬ȡ�Ľ�Ǯ����������ڴ�0�ų����ƶ���N-1�ų��еĹ����������׬ȡ����Ǯ��

����
��һ����һ������T(T<=10)��ʾ�������ݵ�����
ÿ��������ݵĵ�һ������������N,M��ʾ������N������(1<N<=1000),M��·(1<=M<=1000)
����M�У�ÿ����5����������ǰ������a,b(0<=a,b<N)��ʾ�������еı�š������������c,u,v�ֱ��ʾ��a,b����֮���ƶ��Ļ��ѣ�a�����ƶ���b���п�׬ȡ���ʽ�b�����ƶ���a���п�׬ȡ���ʽ�
(0<=c,u,v<=1000)
���
��������ܹ������й�����׬ȡ���޶���ʽ������$$$
������������ƶ������������׬ȡ���ʽ�����
���ֻ����Ǯ�Ļ������һ����������ʾ�������Ǯ����
��������
2
2 1
0 1 10 11 11
3 3
0 1 10 16 0
1 2 10 15 5
0 2 20 32 0
�������
$$$
12
*/
