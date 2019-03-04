#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
using namespace std;

#define M 10005
#define N 105
#define MIN(a, b) a < b ? a : b
#define MAX(a, b) a > b ? a : b

struct EDGE
{
	int r;
	int next;
}edge[M]; // �洢�� 

int head[N]; 
int Index; // ����(ʱ����)
int res;   // �㼯 
stack <int> ist;
int dfn[N]; // �õ�ʱ���� 
int low[N]; // �õ�֮���ܹ�����õ����Сʱ��� 
int t[N];   // �����ڵļ��� 
int instack[N]; // �Ƿ���ջ�� 

void insert(int l, int r) // ����� 
{
	edge[Index].r = r;
	edge[Index].next = head[l];
	head[l] = Index ++;
}

int targan(int x) // targanǿ��ͨͼ�����㷨 
{
	int i, r, v;
	ist.push(x); 
	dfn[x] = low[x] = Index ++;
	instack[x] = 1;
	for(i = head[x]; i != -1; i = edge[i].next)
	{
		r = edge[i].r;
		if (!dfn[r]) // ���r��û��ʹ�ù�����rΪ�������targan�㷨 
		{
			targan(r);
			low[x] = MIN(low[x], low[r]); // ���r���ܴ�ǰ��ĵ㵽�� 
		}
		else if (instack[r])
		{
			low[x] = MIN(low[x], dfn[r]); // ���r����ջ�� 
		}
	}
	if (low[x] == dfn[x]) // ��������ٴӺ���ѭ������õ㲢����
						  // �ȸõ�ʱ���С�ĵ㣬��ô����ͨ��ͼ���� 
	{
		++ res;
		do
		{
			v = ist.top();
			instack[v] = 0;
			t[v] = res;
			ist.pop();
		}while (v != x);
	}
}

int main()
{
	int i, j, r, T, m, x, y, sum;
	int in[N], out[N];
	scanf("%d", &T);
	while (T --)
	{
		memset(head, -1, sizeof(head));
		memset(dfn, 0, sizeof(dfn));
		memset(instack, 0, sizeof(instack));
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		scanf("%d", &m);
		Index = 0;
		res = 0;
		for (i = 1; i <= m; i ++)
		{
			x = 1;
			while(1)
			{
				scanf("%d", &x);
				if (!x)
					break;
				insert(i, x);
			}
		}
		Index = 1;
		sum = 0;
		for (i = 1; i <= m; i ++) // �������������ǿ��ͨͼ���� 
		{
			if (!dfn[i])
			{
				targan(i);
			}
		}
		if (res == 1) // �����ļ���ֻ��һ��������Ҫ��ӱ� 
		{
			printf("0\n");
		}
		else
		{
			// ����ÿ��ǿ��ͨ�����Ⱥͳ��� 
			for (i = 1; i <= m; i ++)
			{
				for (j = head[i]; j != -1; j = edge[j].next)
				{
					r = edge[j].r;
					if (t[r] != t[i]) 
					{
						in[t[r]] ++;
						out[t[i]] ++;
					}
				}
			}
			x = y = 0;
			// �������Ϊ0��ĸ��������Ϊ0��ĸ���
			// ���Ϊ�������ģ���֤ÿ���㶼����Ⱥͳ��� 
			for (i = 1; i <= res; i ++)
			{
				if (in[i] == 0)
					x ++;
				if (out[i] == 0)
					y ++;
			}
			printf("%d\n", MAX(x, y));
		}
	} 
	return 0;
}
/*
У԰����
ʱ�����ƣ�3000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�5
����
������ѧԺ����M��ϵ���ֱ���1~M,���и���ϵ֮������һ����Э�飬���ĳϵ�����������ʱ����ϵ������һЩ������ϵ���Ʋ�ʹ�ø���������������ϵ�ǵ���ģ�����Aϵ����Bϵʹ��A�����ʱ��Bδ��һ������Aʹ��B�������

���ڣ�����дһ�����򣬸��ݸ���ϵ֮���ɵ�Э������������������Ҫ��Ӷ��ٸ���ϵ֮������������ϵ������ʹ�κ�һ��ϵ�����ʹ�õ�ʱ����������ϵҲ����������á�

����
��һ������һ������T����ʾ�������ݵ�����(T<10)
ÿ��������ݵĵ�һ����һ������M����ʾ����M��ϵ(2<=M<=100)��
����M�У�ÿ�ж���һЩ���������еĵ�i�б�ʾϵi�����⼸��ϵ���Ʋ�ʹ��ϵi�������ÿ�н�β����һ��0����ʾ����������������ĳ��ϵ�����������κ�ϵʹ�ø�ϵ���������ֻ��һ��0.
���
����ÿ��������ݣ����������Ҫ��ӵ����������ϵ�ĸ�����
��������
1
5
2 4 3 0
4 5 0
0
0
1 0
�������
2
*/
