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
#define mid ((l+r)>>1)

int a[MAX], b[MAX];
long long sum;

void merge(int l, int r)
{
	int i = l, j = mid+1, k = l;
	while (i <= mid && j <= r)
	{
		if (a[i] <= a[j])
			b[k ++] = a[i ++];
		else
		{
			sum += j-k;
			b[k ++] = a[j ++];
		}
	}
	while (i <= mid) b[k ++] = a[i ++];
	while (j <= r) b[k ++] = a[j ++];
	for (i = l; i <= r; i ++)
		a[i] = b[i];
}

void mergesort(int l, int r)
{
	if (l != r)
	{
		mergesort(l, mid);
		mergesort(mid+1, r);
		merge(l, r);
	} 
}

int main()
{
	int i, t, n;
	scanf("%d", &t);
	while(t --)
	{
		scanf("%d", &n);
		for (i = 1; i <= n; i ++)
			scanf("%d", &a[i]);
		sum = 0;
		mergesort(1, n);
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
