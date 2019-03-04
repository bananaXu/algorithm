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
using namespace std;

#define INF 0x3f3f3f3f
#define MIN(a, b) a < b ? a : b
#define MAX(a, b) a > b ? a : b

int a[1000005];

int main()
{
	int t, i, n, x, min, max;
	scanf("%d", &t);
	while (t --)
	{
		scanf("%d", &n);
		a[0] = 0;
		min = INF;
		for (i = 1; i <= n; i ++)
		{
			scanf("%d", &x);
			a[i] = x+a[i-1]; // a[i]保存前n项和 
			min = MIN(min, abs(x)); // 找单个数字中最小的 
			min = MIN(min, abs(a[i])); // 找前n项最小的 
		}
		sort(a+1, a+n+1); // a[i]-a[j]为sum[j+1..i] 
		if (min)
		{
			for (i = 2; i <= n; i ++)
				min = MIN(min, a[i]-a[i-1]); // 找i到j项和最小的 
		}
		if ((a[1]^a[n]) < 0) // a[1]和a[n]异号 
			max = abs(a[n]-a[1]);
		else // a[1]和a[n]同号
			max = MAX(abs(a[1]), abs(a[n]));
		printf("%d\n", max-min);
	}
	return 0;
}
/*
字串和之差
时间限制：3000 ms  |  内存限制：65535 KB
难度：4
描述
给出一个数列{a1,a2,a3,a4……an},选出一个连续非空子序列，使该序列的绝对值max最大，再选出一个非空子序列（与第一个序列的选择无关），使该序列的绝对值min最小。输出max与min的差值。
输入
第一行是一个整数m（m<15)表示测试数据的组数。
每组数据第一行是一个整数 n（n<1000000),表示这个数列元素的个数，接下来一行是n个整数x(-100<x<100)。
输出
输出max与min的差值（max-min).每组数据输出占一行。
样例输入
2
4
-1 1 3 2
5
2 3 -2 4 1
样例输出
6
7
*/
