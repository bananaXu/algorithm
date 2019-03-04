#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
using namespace std;

#define M 1000005

int a[M] = {0};
int m;

int lowbit(int x)
{
	return x&-x;
}

void add(int x, int val)
{
	while (x <= m)
	{
		a[x] += val;
		x += lowbit(x);
	}
}

int getsum(int x)
{
	int sum = 0;
	while (x > 0)
	{
		sum += a[x];
		x -= lowbit(x);
	}
	return sum;
}

int main()
{
	int t, x, y, val;
	char s[5];
	scanf("%d%d", &t, &m);
	while (t --)
	{
		scanf("%s", &s);
		if (s[0] == 'A')
		{
			scanf("%d%d%d", &x, &y, &val);
			add(x, val);
			add(y+1, -val);
		}
		else
		{
			scanf("%d", &x);
			printf("%d\n", getsum(x));
		}
	}
	return 0;
}
// 思想:树形数组区间更新 
/*
士兵杀敌（四）
时间限制：2000 ms  |  内存限制：65535 KB
难度：5
描述
南将军麾下有百万精兵，现已知共有M个士兵，编号为1~M，每次有任务的时候，总会有一批编号连在一起人请战（编号相近的人经常在一块，相互之间比较熟悉），最终他们获得的军功，也将会平分到每个人身上，这样，有时候，计算他们中的哪一个人到底有多少军功就是一个比较困难的事情，军师小工的任务就是在南将军询问他某个人的军功的时候，快速的报出此人的军功，请你编写一个程序来帮助小工吧。

假设起始时所有人的军功都是0.

输入
只有一组测试数据。
每一行是两个整数T和M表示共有T条指令，M个士兵。（1<=T,M<=1000000)
随后的T行，每行是一个指令。
指令分为两种：
一种形如
ADD 100 500 55 表示，第100个人到第500个人请战，最终每人平均获得了55军功，每次每人获得的军功数不会超过100，不会低于-100。
第二种形如：
QUERY 300 表示南将军在询问第300个人的军功是多少。
输出
对于每次查询输出此人的军功，每个查询的输出占一行。
样例输入
4 10
ADD 1 3 10
QUERY 3
ADD 2 6 50
QUERY 3
样例输出
10
60
*/
