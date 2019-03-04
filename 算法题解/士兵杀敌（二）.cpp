#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define MAX 1000005

int bit[MAX];
int n, m, x, y;
char c[10];

int lowbit(int x)
{
	return x&-x;
}

int sum(int i)
{
	int s = 0;
	while(i > 0)
	{
		s += bit[i];
		i -= lowbit(i);
	}
	return s;
}

void add(int i, int x)
{
	while(i <= n)
	{
		bit[i] += x;
		i += lowbit(i);
	}
}

void init()
{ 
	int i, j, t;
	for(i = n; i >= 1; i --) 
	{ 
		t = 0; 
		for(j = i-lowbit(i)+1; j <= i; j ++) 
		t += bit[j]; 
		bit[i] = t; 
	} 
} 

int main()
{
	int i, t;
	scanf("%d%d", &n, &m);
	for(i=1;i<=n;i++)
	{
		scanf("%d", &t);
		add(i, t);
	}
	while (m --)
	{
		scanf("%s%d%d", &c, &x, &y);
		if(c[0] == 'A') 
			add(x, y);
		else 
			printf("%d\n", sum(y)-sum(x-1));
	}
	return 0;
}
/*
描述
南将军手下有N个士兵，分别编号1到N，这些士兵的杀敌数都是已知的。

小工是南将军手下的军师，南将军经常想知道第m号到第n号士兵的总杀敌数，请你帮助小工来回答南将军吧。

南将军的某次询问之后士兵i可能又杀敌q人，之后南将军再询问的时候，需要考虑到新增的杀敌数。

输入
只有一组测试数据
第一行是两个整数N,M，其中N表示士兵的个数(1<N<1000000)，M表示指令的条数。(1<M<100000)
随后的一行是N个整数，ai表示第i号士兵杀敌数目。(0<=ai<=100)
随后的M行每行是一条指令，这条指令包含了一个字符串和两个整数，首先是一个字符串，如果是字符串QUERY则表示南将军进行了查询操作，后面的两个整数m,n，表示查询的起始与终止士兵编号；如果是字符串ADD则后面跟的两个整数I,A(1<=I<=N,1<=A<=100),表示第I个士兵新增杀敌数为A.
输出
对于每次查询，输出一个整数R表示第m号士兵到第n号士兵的总杀敌数，每组输出占一行
样例输入
5 6
1 2 3 4 5
QUERY 1 3
ADD 1 2
QUERY 1 3
ADD 2 3
QUERY 1 2
QUERY 1 5
样例输出
6
8
8
20
*/ 
