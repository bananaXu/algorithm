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

#define N 100
#define M 10000
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
int index;   	// �ߵ����� 
int n, m, s, t; // n���ڵ㣬m���ߣ�Դ��s�����t 

void insert(int l, int r, int allowflow) // ������Լ�����ͨ�������� 
{
	edge[index].r = r;
	edge[index].allowflow = allowflow;
	edge[index].next = head[l];
	head[l] = index ++;
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
	int flow = 0, Nextd = n+1;
	for (int i = head[x]; i != -1; i = edge[i].next) // x�����ӵ����б� 
	{
		int r = edge[i].r, allowflow = edge[i].allowflow;
		if (d[x] == d[r]+1) // ����Ϊd[x]-1 
		{
			int Temp;
			Temp = augment(r, MIN(Maxflow, allowflow)); 
			flow += Temp, Maxflow -= Temp, edge[i].allowflow -= Temp, edge[i^1].allowflow += Temp;
			if (!Maxflow) // �������� 
				return flow; 
		}
		else
			Nextd = MIN(d[r]+1, Nextd); 
	}
	// ��x�����ӵ�����d[x]-1����ı����� 
	if (!(-- num[d[x]]))  
		d[s] = n+1;
	d[Nextd] ++;
	++ num[d[Nextd]];
	return flow;
} 

void init()
{
	scanf("%d%d", &n, &m);
	index = 0;
	memset(head, -1, sizeof(head));
	memset(num, 0, sizeof(num)); 
	for (int i = 1; i <= m; i ++)
	{
		int l, r, flow; // �ߵĶ˵��Լ����� 
		scanf("%d%d%d", &l, &r, &flow);
		insert(l, r, flow); // ����������Ϊflow������������ΪΪ0 
	 	insert(r, l, 0);
	} 
	bfs();
}

int ISAP()
{
	init();
	int flow = augment(s, INF);
	while (d[s] <= n) flow += augment(s, INF);
	return flow; 
}

int main()
{
	printf("%d\n", ISAP());
	return 0;
} 
