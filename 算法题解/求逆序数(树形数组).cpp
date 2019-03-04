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
#define Max(a, b) a > b ? a : b

struct NODE
{
	int i;
	int val;
}node[MAX];

int bit[MAX];
int j, n;
int imap[MAX];

int lowbit(int x)
{
	return x&(-x);
}

long long getsum(int i)
{
	long long s = 0;
	while(i > 0)
	{
		s += bit[i];
		i -= lowbit(i);
	}
	return s;
}

void add(int i, int x)
{
	while(i <= j)
	{
		bit[i] += x;
		i += lowbit(i);
	}
}

bool cmp(NODE a, NODE b)
{
	return a.val < b.val;
}

int main()
{
	int i, t, x;
	long long sum;
	scanf("%d", &t);
	while(t --)
	{
		scanf("%d", &n);
		for (i = 1; i <= n; i ++)
		{
			node[i].i = i;
			scanf("%d", &node[i].val);
		}
		sort(node+1, node+n+1, cmp);	
		j = 1;
		imap[node[1].i] = 1;
		for (i = 2; i <= n; i ++)
		{
			if (node[i].val != node[i-1].val)
				j ++;
			imap[node[i].i] = j;
		}
		memset(bit, 0, (j+1)*sizeof(int));
		sum = 0;
		for (i = 1; i <= n; i ++)
		{
			add(imap[i], 1);
			sum += i-getsum(imap[i]);
		}
		printf("%lld\n", sum);
	}
	return 0;
}
/*
描述
在一个排列中，如果一对数的前后位置与大小顺序相反，即前面的数大于后面的数，那么它们就称为一个逆序。一个排列中逆序的总数就称为这个排列的逆序数。
现在，给你一个N个元素的序列，请你判断出它的逆序数是多少。
比如 1 3 2 的逆序数就是1。
输入
第一行输入一个整数T表示测试数据的组数（1<=T<=5)
每组测试数据的每一行是一个整数N表示数列中共有N个元素（2〈=N〈=1000000）
随后的一行共有N个整数Ai(0<=Ai<1000000000)，表示数列中的所有元素。
数据保证在多组测试数据中，多于10万个数的测试数据最多只有一组。
输出
输出该数列的逆序数
样例输入
2
2
1 1
3
1 3 2
样例输出
0
1
*/
