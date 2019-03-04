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

typedef long long ll;

int main()
{
	int t;
	scanf("%d", &t);
	while (t --)
	{
		int n;
		int p[7];
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++)
			scanf("%d", &p[i]);
		double sum = 0;
		for (int i = 1; i <= n; i ++)
		{
			double t = 1;
			for (int j = 1; j <= n; j ++)
			{
				if (i == j)
					continue;
				t = t*(n+1-j)/(i-j);
			}
			sum += t*p[i];
		}
		printf("%lld\n", (ll)sum);
	}
	return 0;
}
/*
找规律
时间限制：1000 ms  |  内存限制：65535 KB
难度：4
描述
大家一定见过这种题目：给你一些数请找出这些数之间的规律，写出下一个满足该规律的数。

比如：2 5 10 17 26，则可以看出这些数符合n*n+1这个通项公式，则下一个数为37。

这种通项公式不只一个，所以答案是不唯一的。但如果已知了N个数，且已知其通项公式是一个次数小于N的多项式，则答案就唯一确定了。

现在给你一个数列，请找出规律并求出其下一个数为多少？

输入
第一行是一个整数T表示测试数据的组数(T<=20)
每组测试数据的第一行是一个整数N（1<=N<=5)
随后的一行有N个整数,表示该数列已知了的N个整数(这N个整数的值都不大于1000)。
输出
输出符合规律的下一个数
样例输入
2
2
1 2
5
2 5 10 17 26
样例输出
3
37
*/
