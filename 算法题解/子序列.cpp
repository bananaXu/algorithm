#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define M 1000005
#define INF 0x3f3f3f3f

int a[M];
int b[M];

struct Point // Ϊ��������ɢ�� 
{
	int i;
	int v;
}p[M];

bool cmp(Point x, Point y)
{
	return x.v < y.v;
}

bool cmp2(Point x, Point y)
{
	return x.i < y.i;
}

int main()
{ 
	int len, t, i, j, sum, min, pre;
	scanf("%d", &t);
	while (t --)
	{
		scanf("%d", &len);
		memset (a, 0, sizeof(a));
		memset (b, 0, sizeof(b));
		for (i = 1; i <= len; i ++)
		{
			p[i].i = i; 
			scanf("%d", &p[i].v);
		} 
		sort(p+1, p+len+1, cmp);
		pre = p[1].v;
		p[1].v = 0;
		for (i = 2; i <= len; i ++)
		{
			if (p[i].v == pre)
				p[i].v = p[i-1].v;
			else
			{
				pre = p[i].v;
				p[i].v = p[i-1].v+1;
			}
		}
		sort(p+1, p+len+1, cmp2);
		sum = 0;
		// ��ȡ����1.���ҵ��ӿ�ͷ���ܰ����������ݵ���̾��룬
		//         2.���ȥ����ͷ�����������䣬��ȥ��������������ұ߼�һ��
		//         3.�����ظ�1��2ֱ����������β�� 
		for (i = 1; i <= len; i ++) 
		{
			if (!a[p[i].v])
			{
				sum ++;
				j = i; 
			} 
			a[p[i].v] ++;
		}
		min = j;
		if (min != sum)
		{
			for (i= 1; i <= j; i ++)
				b[p[i].v] ++;
			i = 1;
			while (j <= len)
			{
				if (i != j && b[p[i].v] > 1)
				{
					b[p[i].v] --;
					i ++;
					if (j-i+1 < min)
						min = j-i+1;
				}
				else
				{
					j ++;
					b[p[j].v] ++;
				}
			}	
		}
		printf ("%d\n", min);
	}
	return 0;
}
/*
������
ʱ�����ƣ�3000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�5
����
����һ�����У�������������е�һ�������������У�ʹԭ���г��ֵ�����Ԫ�ؽ��ڸ��������г��ֹ�����1�Ρ�

��2 8 8 8 1 1�������Ӵ�����2 8 8 8 1��

����
��һ������һ������T(0<T<=5)��ʾ�������ݵ�����
ÿ��������ݵĵ�һ����һ������N(1<=N<=1000000)����ʾ�������еĳ��ȡ�
����һ����N������������ʾ�����������е�����Ԫ�ء�
���ݱ�֤��������������ᳬ��32λ�����ķ�Χ��
���
����ÿ�����룬�������������������Ԫ�ص���������еĳ���
��������
2
5
1 8 8 8 1
6
2 8 8 8 1 1
�������
2
5
*/
