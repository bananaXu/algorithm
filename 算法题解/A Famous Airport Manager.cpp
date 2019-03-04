#include <iostream>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;

struct Edge
{
	int next;
	int r;
	int x;
	int y;
}edge[690];

int head[256];
int I = 0;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char a[3][3];
int b[3][3];
int f[3][3]; 
int used[256];
int num;

void insert(int l, int r, int x, int y)
{
	edge[I].r = r;
	edge[I].next = head[l];
	edge[I].x = x;
	edge[I].y = y;
	head[l] = I ++;
}

void GetNextL(int p, int x, int y)
{	// Ѱ���¸��ܵ�����ɵ�ķɻ� 
	int i, q, n_x, n_y;
	f[x][y] = 1;
	if (b[x][y])
	{
		q = p^(1<<(3*x+y-1)); // ���ı����һλ��0 
		insert(p, q, x, y); // ���뵱ǰ״̬����һ״̬��ɵı� 
		return;
	}
	for (i = 0; i <= 3; i ++)
	{
		n_x = x+dir[i][0];
		n_y = y+dir[i][1];
		if (n_x >= 0 && n_x < 3 && n_y >= 0 && n_y < 3 && !f[n_x][n_y])
		{ 	//�ܹ�������û�߹��ĵ� 
			GetNextL(p, n_x, n_y);
		}
	}
}

void dfs(int x, int L)
{
	if (!x) // ȫ����� 
	{
		if (!used[L])
		{
			used[L] = 1;
			num ++;
		}
		return;
	}
	int i, m, n, s, t;
	for (i = head[x]; i != -1; i = edge[i].next)
	{
		t = (L<<1)+(a[edge[i].x][edge[i].y] == 'B' ? 0 : 1);
		dfs(edge[i].r, t);
	}
}

int main()
{
	int i, j, k, x, Case;
	Case = 0;
	memset(head, -1, sizeof(head));
	for (i = 1; i < 256; i ++) // ��1~2^8-1 255��״̬��ʼ��Ѱ�ҷ���һ���ɻ������һ״̬ 
	{						   // �зɻ��ĵ�Ϊ1��û�е�Ϊ0 
		x = i;
		memset(f, 0, sizeof(f));
		for (j = 0; j < 3; j ++)
		{
			for (k = 0; k < 3; k ++)
			{
				if (!j && !k)
				{
					b[j][k] = 0; 
					continue;
				}
				b[j][k] = x&1; //��b�洢i��ÿһλ 
				x >>= 1;
			}
		}
		GetNextL(i, 0, 0); // ��ȡ�¸����ܵ�״̬ 
	}
	while (scanf("%s", &a[0]) != EOF)
	{
		scanf("%s", &a[1]);
		scanf("%s", &a[2]);
		x = num = 0;
		memset(used, 0, sizeof(used));
		for (i = 2; i >= 0; i --)
		{
			for (j = 2; j >= 0; j --)
			{
				if (!i && !j) continue;
				x = (x<<1)+(a[i][j] == '*' ? 0 : 1); // �����������ݶ�Ӧ��״̬ 
			}
		}
		dfs(x, 0); // ���� 
		printf("Case %d: %d\n", ++Case, num);
	}
	return 0; 
}
/*
��Ŀ����
3X3�ķɻ���,(0,0)��Ϊ��ɵ㣬'*'�գ�'G'��ɫ��'B'��ɫ��
�ɻ����ߵ�����λ�ã����ܿ����������ɫ˳��������� 
*BB  
BBB
BBB
*GB
BBB
BBB
*BG
BBB
*GB
*GB
GBG
BGB
*G*
B*G
GGB
*/
