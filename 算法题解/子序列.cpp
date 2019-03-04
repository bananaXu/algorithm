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

struct Point // 为了数据离散化 
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
		// 尺取法：1.先找到从开头到能包含所有数据的最短距离，
		//         2.如果去掉开头的数数量不变，则去掉，如果减少则右边加一个
		//         3.反复重复1、2直到到达数组尾部 
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
子序列
时间限制：3000 ms  |  内存限制：65535 KB
难度：5
描述
给定一个序列，请你求出该序列的一个连续的子序列，使原串中出现的所有元素皆在该子序列中出现过至少1次。

如2 8 8 8 1 1，所求子串就是2 8 8 8 1。

输入
第一行输入一个整数T(0<T<=5)表示测试数据的组数
每组测试数据的第一行是一个整数N(1<=N<=1000000)，表示给定序列的长度。
随后的一行有N个正整数，表示给定的序列中的所有元素。
数据保证输入的整数都不会超出32位整数的范围。
输出
对于每组输入，输出包含该序列中所有元素的最短子序列的长度
样例输入
2
5
1 8 8 8 1
6
2 8 8 8 1 1
样例输出
2
5
*/
