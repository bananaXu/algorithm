#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <cmath>
#include <ctype.h>
using namespace std;

#define MAX(a, b) a > b ? a : b
int n, m, Max, MaxNum;
int a[1007];
int b[17];

void GetMaxNum()
{
	int i, x, sum;
	x = sum = 0;
	for (i = 1; i <= Max; i ++)
	{
		x += 1<<(b[i]-1); // ����ʱ�ܹ����ܵĲ����ö����ƴ洢 
	}
	for (i = 1; i <= n; i ++)
	{
		if ((x|a[i]) == x) // �����ţ��û�н��ܲ���֮��Ĳ�������������һ 
			sum ++;
	}
	MaxNum = MAX(MaxNum, sum);
}

void find(int x, int y)
{
	int i; // ö�ٰ����Ĳ������� 
	if (x == Max+1) // ������������������������ͬʱ��������ѡ�����ţ���� 
	{
		GetMaxNum();
		return;
	}
	for (i = y; i <= m-Max+x; i ++)
	{
		b[x] = i;
		find(x+1, i+1);
	}
}

int main()
{
	int i, j, t, x, v;
	scanf("%d", &t);
	while (t --)
	{
		MaxNum = 0;
		scanf("%d%d%d", &n, &m, &Max);
		for (i = 1; i <= n; i ++)
		{
			scanf("%d", &x);
			a[i] = 0;
			for (j = 1; j <= x; j ++)
			{
				scanf("%d", &v);
				a[i] += 1<<(v-1); // ��ţ�̰����Ĳ����ö����ƴ洢 
			}
		}
		find(1, 1);
		printf("%d\n", MaxNum);
	}
	return 0;
} 
/*
С��Ĺ���
ʱ�����ƣ�1000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�4
����
С����һ����ţ������ţ�����������D��1<D<=15���ֲ�����С���ũ��һ����N��1<N<=1000��ֻ��ţ��������K��1<=K<=D���ֲ�����ţ�̲��ò�����.(ţ���к�����ţ���ϵĲ���)������ϣ����дһ��������ȷ��һ��һ��Ͱ��������԰�������ͷ��ţ��ţ�̡�

����
��һ��һ������M��1<M<=7��,��ʾ��M��������ݣ���������M�����ݵĵ�һ��������������N��D��K���ֱ��ʾ��ţ�������������������࣬���һ��Ͱ�п��԰����Ĳ���������������N�У���i�У���һ���� i1����ʾ��iͷţ�����Ĳ���������������i1��������ʾ���ǲ�������ı��(Ĭ�϶�D���������ı�ţ���1��D )�����i1 Ϊ0����ʾ��û�в�����
���
ÿ���������������༷����ͷţ������Ͱ�������н�����
��������
1
6 3 2
0
1 1
1 2
1 3
2 2 1
2 2 1
�������
5
*/
