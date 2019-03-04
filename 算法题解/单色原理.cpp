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

/*
一个三角形是非单色三角形，那么必定有两个顶点所连接边的颜色不相同，
枚举每个顶点连接不同边的次数除以2，即为非单色三角形个数，用总三角形
个数减去非单色三角形个数，就是单色三角形个数 
*/

int main() 
{
	int n, m;
	scanf("%d", &n);
	while (n --)
	{
		scanf("%d", &m);
		int sum = 0;
		for (int i = 1; i <= m; i ++)
		{
			int x;
			scanf("%d", &x);
			sum += (m-1-x)*x;
		}
		sum = m*(m-1)*(m-2)/6-sum/2;
		printf("%d\n", sum);
	}
	return 0;
}
/*
单色原理
时间限制：3000 ms  |  内存限制：65535 KB
难度：4
描述
给定空间里的n个点，其中没有三点共线。每两个点之间都可以用红色和黑色线段连接。如果一个三角形的三条边同色，则称这个三角形是单色三角形。对于给定的红色线段的列表，希望你找出单色三角形个数。
输入
第一行有一个整数n（3<=n<=100）表示一共有n组测试数据，接下来每一组数据第一行有一个整数m（3<=m<=1000）,表示一共有m个顶点，接下来一行有m个数，表示第i（0<=i<m）个顶点的红色边个数。
输出
输出每组数据中一共有几个三角形是单色三角形，换行结束。
样例输入
1
3
1 1 2
样例输出
0
*/
