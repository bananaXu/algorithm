#include <iostream>
#include <queue>
using namespace std;
#define MAX 1000
#define MaxInt 0x7fffffff/10

struct Edge // �洢�� 
{
	int val;
	int next;
	int r;
}edge[4*MAX+5];

int head[MAX+5]; // ����ӱ�ʽ�洢�ڵ� 
int dis[MAX+5]; // ��Դ����� 
int InQueue[MAX+5]; // �Ƿ��ڶ��ڣ�1���ǣ�2���� 
int I = 0;
queue <int>open;

void insert(int l, int r, int val)
{
	edge[I].val = val;
	edge[I].next = head[l];
	edge[I].r = r;
	head[l] = I++;
}

void SPFA(int begin)
{
	int i, a;
	open.push(begin);  // ����Դ�� 
	InQueue[1] = 1;
	while (!open.empty())
	{
		a = open.front(); // ����һ��Ԫ�أ�����ȥˢ�½ڵ�
		open.pop();
		InQueue[a] = 0;
		for (i = head[a]; i != -1; i = edge[i].next)
		{
			if (dis[a]+edge[i].val < dis[edge[i].r]) // �����ԭ·���� 
			{
				dis[edge[i].r] = dis[a]+edge[i].val;
				if (!InQueue[edge[i].r]) // û�ڶ��ڣ�������� 
				{
					InQueue[edge[i].r] = 1;
					open.push(edge[i].r);
				}
			}
		}
	}
}

int main()
{
	int i, n, m, l, r, val;
	cin >> m >> n;
	for (i = 0; i <= MAX; i ++)
	{
		head[i] = -1;
		dis[i] = MaxInt;
		InQueue[i] = 0;
	}
	for (i = 1; i <= n; i ++)
	{
		cin >> l >> r >> val;
		insert(l, r, val);
		insert(r, l, val);
	}
	dis[1] = 0;
	SPFA(1);
	cout << dis[m] << endl;
	return 0;
}
// �������� 
/*
5 5
1 2 1
2 3 1
3 4 1
4 5 2
4 5 1
*/
/*
1 4
1 1 1
1 1 1
1 1 1
1 1 1
*/
/*
9 12
1 3 2
3 5 2
5 7 2
7 9 2
1 2 1
2 3 1
3 4 1
4 5 1
5 6 1
6 7 1
7 8 1
8 9 1
*/
