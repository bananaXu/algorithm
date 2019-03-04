#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct TIME
{
	int l;
	int r;
}ti[10005];

bool cmp(TIME a, TIME b)
{
	return a.r < b.r;
}

int main()
{
	int i, t, m, num, Min;
	cin >> t;
	while (t --)
	{
		cin >> m;
		for (i = 1; i <= m; i ++)
		{
			scanf("%d%d", &ti[i].l, &ti[i].r);
		}
		sort(ti+1, ti+m+1, cmp);
		Min = -1;
		num = 0;
		for (i = 1; i <= m; i ++)
		{
			if (Min < ti[i].l)
			{
				Min = ti[i].r;
				num ++;
			}
		}
		cout << num << endl;
	}
	return 0;
} 
/*
描述
学校的小礼堂每天都会有许多活动，有时间这些活动的计划时间会发生冲突，需要选择出一些活动进行举办。小刘的工作就是安排学校小礼堂的活动，每个时间最多安排一个活动。现在小刘有一些活动计划的时间表，他想尽可能的安排更多的活动，请问他该如何安排。
输入
第一行是一个整型数m(m<100)表示共有m组测试数据。
每组测试数据的第一行是一个整数n(1<n<10000)表示该测试数据共有n个活动。
随后的n行，每行有两个正整数Bi,Ei(0<=Bi,Ei<10000),分别表示第i个活动的起始与结束时间（Bi<=Ei)
输出
对于每一组输入，输出最多能够安排的活动数量。
每组的输出占一行
样例输入
2
2
1 10
10 11
3
1 10
10 11
11 20
样例输出
1
2
*/
