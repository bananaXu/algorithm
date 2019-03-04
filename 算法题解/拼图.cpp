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

#define EPS 1e-8

struct MAP
{
	int n, m;
	int a[5][5];
}Map[5];

int t;
int a[15][15];

bool CanPut(int n, int m, int i, int j)
{
	for (int k = i; k < Map[n].n+i; k ++)
	{
		for (int l = j; l < Map[n].m+j; l ++)
		{
			if (k >= m || l >= m)
				return false;
			if (a[k][l] && Map[n].a[k-i][l-j])
				return false;
		}
	}
	return true;
}

bool Push(int n, int m)
{
	if (n == t)
	{
		for (int i = 0; i < m; i ++)
		{
			for (int j = 0; j < m; j ++)
				printf("%d", a[i][j]);
			printf("\n");
		}
		return true;
	}
	for (int i = 0; i < m; i ++)
	{
		for (int j = 0; j < m; j ++)
		{
			if (CanPut(n, m, i, j))
			{
				for (int k = i; k < Map[n].n+i; k ++)
				{
					for (int l = j; l < Map[n].m+j; l ++)	
						if (Map[n].a[k-i][l-j])
								a[k][l] = n+1;
				}
				if (Push(n+1, m))
					return true;
				for (int k = i; k < Map[n].n+i; k ++)
				{
					for (int l = j; l < Map[n].m+j; l ++)
						if (a[k][l] == n+1)
							a[k][l] = 0;
				}
			}
		}
	}
	return false;
}

void findREC(int num)
{
	if (num == 1)
	{
		printf("1\n");
		return;
	}
	int m = (int)(sqrt(num*1.0)+EPS);
	if (m*m != num)
	{
		printf("No solution possible\n");
		return;
	}
	if (!Push(0, m))
		printf("No solution possible\n");
}

int main()
{
	while (~scanf("%d", &t))
	{
		int n, m, num = 0;
		memset(a, 0, sizeof(a));
		for (int i = 0; i < t; i ++)
		{
			scanf("%d%d", &Map[i].n, &Map[i].m);
			for (int j = 0; j < Map[i].n; j ++)
			{
				char s[5];
				scanf("%s", &s);
				for (int k = 0; k < Map[i].m; k ++)
				{
					Map[i].a[j][k] = s[k]-'0';
					if (Map[i].a[j][k] == 1)
						num ++;
				}
			}
		}
		findREC(num);
	}
	return 0;
}
/*
����
�����ж������ݡ��ļ��ĵ�һ����һ������n����ʾͼ�εĸ�������Χ��1��5��
��������n�����֣�ÿ�����ֵĵ�һ����2������i��j����ʾ�����i��j����������һ��ͼ�Ρ�ͼ����0��1��ʾ��1��ʾͼ��ռ�����λ�ã�0��ʾ��ռ�У��м�û�пո�������ͼ��ͼ��A��������
2 3
111
101
����ͼ�εĳ����������5��
����ͼ�θ�����˳���ÿ��ͼ�α�ţ���1��ʼ�����ൽ5��
��֤�����޶�������
���
�������ƴ��һ�������Σ��������No solution possible�����������һ��ƴ�ķ�����һ�������ε�����ÿ��λ���ϵ�������ռ�����λ�õ�ͼ�εı�ţ��м�û�пո���������A��B��C��D�ı��������1��2��3��4����ô�Ϳ������
1112
1412
3422
3442
��������
4
1 4
1111
1 4
1111
1 4
1111
2 3
111
001

5
2 2
11
11
2 3
111
100
3 2
11
01
01
1 3
111
1 1
1

�������
No solution possible
1133
1153
2223
2444
*/
