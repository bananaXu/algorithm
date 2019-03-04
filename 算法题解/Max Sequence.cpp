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

#define M 100005
#define INF 0x3f3f3f3f
#define MAX(a, b) a > b ? a : b

int a[M], dp1[M], dp2[M];

int main()
{
	int n;
	while (1)
	{
		scanf("%d", &n);
		if (!n)
			break;
		for (int i = 0; i < n; i ++)
			scanf("%d", &a[i]);
		int Max = -INF, sum = 0;
		for (int i = 0; i < n; i ++)
		{
			if (sum < 0)
				sum = a[i];
			else
				sum += a[i];
			Max = MAX(Max, sum);
			dp1[i] = Max;
		}
		Max = -INF;
		sum = 0;
		for (int i = n-1; i >= 0; i --)
		{
			if (sum < 0)
				sum = a[i];
			else
				sum += a[i];
			Max = MAX(Max, sum);
			dp2[i] = Max;
		}
		Max = -INF;
		for (int i = 0; i < n-1; i ++)
			Max = MAX(dp1[i]+dp2[i+1], Max);
		printf("%d\n", Max);
	}
	return 0;
}
// 题目大意：求数组两段加起来和最大，两段不能相交
/*
样例输入
5
-5 9 -5 11 20
0
样例输出
40
*/ 
