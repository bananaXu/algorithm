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

#define N 205
#define M 20005
#define INF 0x3f3f3f3f
#define MIN(a, b) a < b ? a : b 

struct Edge
{
	int r;
	int allowflow;
	int next;
}edge[M];

int head[N]; 	// �ߵ���� 
int d[N]; 	 	// ������t�ľ��� 
int num[N];     // �þ�������� 
int Index;   	// �ߵ����� 
int n, m, s, t, sum; // n���ڵ㣬m���ߣ�Դ��s�����t 

void insert(int l, int r, int allowflow) // ������Լ�����ͨ�������� 
{
	edge[Index].r = r;
	edge[Index].allowflow = allowflow;
	edge[Index].next = head[l];
	head[l] = Index ++;
}

void bfs() // �ӻ��t����bfs���ҵ����е������ľ��� 
{
	int i;
	memset(d, INF, (n+1)*sizeof(int));
	queue <int> iq;
	iq.push(t);
	d[t] = 0;
	while (!iq.empty())
	{
		int x = iq.front();
		iq.pop();
		for (i = head[x]; i != -1; i = edge[i].next)
		{
			int r = edge[i].r, allowflow = edge[i].allowflow;
			if (!allowflow && d[x]+1 < d[r]) // �ñ��Ƿ���ģ����Ҵ�x��r����û�����¹� 
			{
				d[r] = d[x]+1;
				num[d[r]] ++;
				iq.push(r);
			}
		}
	}
} 

int augment(int x, int Maxflow) // ��x��ͷ����������Maxflow��·�� 
{	
	if (x == t) // ������ 
		return Maxflow;
	int flow = 0;
	for (int i = head[x]; i != -1; i = edge[i].next) // x�����ӵ����б� 
	{
		int r = edge[i].r, allowflow = edge[i].allowflow;
		if (d[x] == d[r]+1) // ����Ϊd[x]-1 
		{
			int Temp = augment(r, MIN(Maxflow, allowflow)); 
			flow += Temp, Maxflow -= Temp, edge[i].allowflow -= Temp, edge[i^1].allowflow += Temp;
			if (!Maxflow) // �������� 
				return flow; 
		}
	}
	// ��x�����ӵ�����d[x]-1����ı����� 
	if (!(-- num[d[x]]))  
		d[s] = n+1;
	++ num[++ d[x]];
	return flow;
} 

void init()
{
	Index = 0; sum = 0; s = 0; t = n+m+1;
	memset(head, -1, sizeof(head));
	memset(num, 0, sizeof(num)); 
	int i, j;
	for (i = 1; i <= n; i ++)
	{
		int f, t;
		scanf("%d%d", &f, &t);
		sum += f;
		insert(0, i, f);
		insert(i, 0, 0);
		for (j = 1; j <= t; j ++)
		{
			int v;
			scanf("%d", &v);
			insert(i, v+n, INF);
			insert(v+n, i, 0);
		}
	} 
	for (i = 1; i <= m; i ++)
	{
		int pi;
		scanf("%d", &pi);
		insert(i+n, n+m+1, pi);
		insert(n+m+1, i+n, 0);
	}
	n = n+m+2;
	bfs();
}

int ISAP()
{
	init();
	int flow = augment(s, INF);
	while (d[s] <= n) flow += augment(s, INF);
	return sum-flow; 
}

int main()
{
	while (~scanf("%d%d", &n, &m)) 
	{
		printf("%d\n", ISAP());
	}
	return 0;
} 
/*
̫�շ��мƻ�
ʱ�����ƣ�1000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�4
����
W ��������Ϊ���Һ������ļƻ�һϵ�е�̫�շ��С�ÿ��̫�շ��пɽ���һϵ����ҵ��ʵ�����ȡ����
����ȷ����һ���ɹ�ѡ���ʵ�鼯��E={E1��E2������Em}���ͽ�����Щʵ����Ҫʹ�õ�ȫ�������ļ���
I={I1��I2����In}��ʵ��Ej��Ҫ�õ���������I���Ӽ�Rj ����������Ik�ķ���Ϊck��Ԫ��ʵ��Ej������
����ͬ��Ϊ��ʵ����֧��pj��Ԫ��W���ڵ��������ҳ�һ����Ч�㷨��ȷ����һ��̫�շ�����Ҫ������
Щʵ�鲢��˶�������Щ��������ʹ̫�շ��еľ�����������ﾻ������ָ����ʵ������õ�ȫ������
������������ȫ�����õĲ�
���ڸ�����ʵ��������������������ҳ���������������ƻ���

����
����������ݣ�������500�飩
ÿ�����ݵ�1����2 ��������m��n(m,n <= 100)��m��ʵ������n������������������m �У�ÿ����һ��ʵ����й����ݡ���һ����������ͬ��֧����ʵ��ķ���f(f < 10000)�������Ǹ�ʵ����Ҫ�õ��������ĸ���t��������t�������ı�š����һ�е�n����������ÿ�������ķ���pi(pi <=100����
���
ÿ���������ռһ�У�������ľ����棨����޷����棬���0����
��������
2 3
10 2 1 2
25 2 2 3
5 6 7
�������
17
*/
