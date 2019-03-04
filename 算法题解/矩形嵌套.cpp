#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX(a, b) a > b ? a : b

struct REC
{
	int w;
	int h;
}rec[1005];

bool cmp(REC a, REC b)
{
	if (a.w < b.w)
		return true;
	if (a.w == b.w)
		return a.h < b.h;
	return false;
}

int main()
{
	int t, i, j, n, x, y, max;
	int dp[1005];
	cin >> t;
	while (t --)
	{
		cin >> n;
		for (i = 1; i <= n; i ++)
		{
			cin >> x >> y;
			if (x > y) // 将矩形转换成高比宽长，方便计算 
			{
				swap(x, y);
			}
			rec[i].w = x;
			rec[i].h= y;
		}
		sort(rec+1, rec+n+1, cmp); // 将矩形按宽排序
		memset(dp, 0, sizeof(dp));
		max = 0;
		for (i = 1; i <= n; i ++)
		{	// 如果宽相同就停止 
			for (j = 1; j < i && rec[i].w != rec[j].w; j ++)
			{
				if (rec[i].h > rec[j].h)
				{
					dp[i] = MAX(dp[i], dp[j]+1);
				}
			}
			max = MAX(max, dp[i]);
		}
		cout << max+1 << endl;
	} 
	return 0;
}
/*
描述
有n个矩形，每个矩形可以用a,b来描述，表示长和宽。矩形X(a,b)可以嵌套在矩形Y(c,d)中当且仅当a<c,b<d或者b<c,a<d（相当于旋转X90度）。例如（1,5）可以嵌套在（6,2）内，但不能嵌套在（3,4）中。你的任务是选出尽可能多的矩形排成一行，使得除最后一个外，每一个矩形都可以嵌套在下一个矩形内。
输入
第一行是一个正正数N(0<N<10)，表示测试数据组数，
每组测试数据的第一行是一个正正数n，表示该组测试数据中含有矩形的个数(n<=1000)
随后的n行，每行有两个数a,b(0<a,b<100)，表示矩形的长和宽
输出
每组测试数据都输出一个数，表示最多符合条件的矩形数目，每组输出占一行
样例输入
1
10
1 2
2 4
5 8
6 10
7 9
3 1
5 8
12 10
9 7
2 2
样例输出
5
*/ 
