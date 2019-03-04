#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <cmath>
#include <vector> 
#include <queue>
#include <set>
#include <ctype.h>
#include <map>
#include <cfloat>
using namespace std;

#define M 105
#define N 12 

/*
算法思想：
先用树状数组求原序列顺序对
然后求出每个模糊数字在每个点所增加的顺序对 
再用dfs加剪枝算所有序列是否满足，超过k就剪枝 
*/

struct NotIn
{
	int v;
	int num[N];
}notin[N];

int n, k, SUM;
int a[M], b[M], ex[M], notid[N];

int lowbit(int x)
{
	return x&-x;
}

void add(int x, int v)
{
	while (x <= n)
	{
		a[x] += v;
		x += lowbit(x);
	}
}

int getsum(int x)
{
	int sum = 0;
	while (x)
	{
		sum += a[x];
		x -= lowbit(x);
	}
	return sum;
}

int getnum(int x, int y)
{
 	int sum = 0;
	for (int i = 1; i < notid[y]; i ++)
	{
		if (b[i] && notin[x].v > b[i])
			sum ++;
	}
	for (int i = notid[y]+1; i <= n; i ++)
	{
		if (b[i] && b[i] > notin[x].v)
			sum ++;
	}
	return sum;
}

void dfs(int t, int T, int sum, int Max)
{
	if(t == T+1)
	{
		if (sum == Max)
			SUM ++;
		return;
	}
	if (sum > Max)
		return;
	for (int i = t; i <= T; i ++)
	{
		swap(notin[i], notin[t]);
		int x = 0;
		for (int j = 1; j < t; j ++)
		{
			if (notin[t].v > notin[j].v)
				x ++;
		}
		dfs(t+1, T, sum+notin[t].num[t]+x, Max);
		swap(notin[i], notin[t]);
	}
} 

int main()
{
	while (cin >> n >> k)
	{
		int sum = 0;
		int I = 0;
		for (int i = 1; i <= n; i ++)
		{
			cin >> b[i];
			ex[b[i]] = 1;
			if (b[i])
			{
				add(b[i], 1);
				sum += getsum(b[i]-1);
			}
			else
	 			notid[++ I] = i;
		}
		I = 0;
		for (int i = 1; i <= n; i ++)
		{
			if (!ex[i])
				notin[++ I].v = i;
		}
		for (int i = 1; i <= I; i ++)
		{
			for (int j = 1; j <= I; j ++)
				notin[i].num[j] = getnum(i, j);
		}
		SUM = 0;
		dfs(1, I, 0, k-sum);
		cout << SUM << endl;
	}
	return 0;
}
/*
题目描述
牛牛的作业薄上有一个长度为 n 的排列 A，这个排列包含了从1到n的n个数，但是因为一些原因，其中有一些位置（不超过 10 个）看不清了，但是牛牛记得这个数列顺序对的数量是 k，顺序对是指满足 i < j 且 A[i] < A[j] 的对数，请帮助牛牛计算出，符合这个要求的合法排列的数目。
输入描述:
每个输入包含一个测试用例。每个测试用例的第一行包含两个整数 n 和 k（1 <= n <= 100, 0 <= k <= 1000000000），接下来的 1 行，包含 n 个数字表示排列 A，其中等于0的项表示看不清的位置（不超过 10 个）。
输出描述:
输出一行表示合法的排列数目。
示例1
输入
5 5
4 0 0 2 0
输出
2
*/ 
