#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

#define INF 0x3f3f3f3f
#define MAX(a, b) a > b ? a : b

int b[105];

int getmax(int n)
{
	int i, sum, max;
	max = -INF;
	sum = b[1];
	for (i = 2; i <= n; i ++)
	{
		if (sum > max)
			max = sum;
		if (sum < 0)
			sum = 0;
		sum += b[i];
	}
	if (sum > max)
		max = sum;
	return max;
}

// 将多列加起来再求最长子段和 
int main()
{
	int t, m, n, i, j, k, max;
	int a[105][105];
	scanf("%d", &t);
	while (t --)
	{
		cin >> m >> n;
		for (i = 1; i <= m; i ++)
		{
			for (j = 1; j <= n; j ++)
			{
				cin >> a[i][j];
			}
		}
		max = -INF;
		for (i = 1; i <= m; i ++)
		{
			memset(b, 0, sizeof(b));
			for (j = i; j <= m; j ++)
			{
				for (k = 1; k <= n; k ++)
				{
					b[k] += a[j][k];
				}
				max = MAX(max, getmax(n));
			}
		}
		printf("%d\n", max);
	}
	return 0;
}
/*
描述
给定一个由整数组成二维矩阵（r*c），现在需要找出它的一个子矩阵，使得这个子矩阵内的所有元素之和最大，并把这个子矩阵称为最大子矩阵。 
例子：
0 -2 -7 0 
9 2 -6 2 
-4 1 -4 1 
-1 8 0 -2 
其最大子矩阵为：

9 2 
-4 1 
-1 8 
其元素总和为15。 

输入
第一行输入一个整数n（0<n<=100）,表示有n组测试数据；
每组测试数据：
第一行有两个的整数r，c（0<r,c<=100），r、c分别代表矩阵的行和列；
随后有r行，每行有c个整数；
输出
输出矩阵的最大子矩阵的元素之和。
样例输入
1
4 4
0 -2 -7 0 
9 2 -6 2 
-4 1 -4 1 
-1 8 0 -2 
样例输出
15
*/
