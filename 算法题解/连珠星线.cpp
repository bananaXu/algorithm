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

#define M 1005
#define INF 0x3f3f3f3f

int a[M][2];

int main()
{
	int t;
	scanf("%d", &t);
	while (t --)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++)
			scanf("%d%d", &a[i][0], &a[i][1]);
		int num = 0, sum = 0;
		for (int i = 1; i < n; i ++)
		{
			double d[M];
			for (int j = i+1; j <= n; j ++)
			{
				if (a[i][1] == a[j][1])
					d[j] = INF-1;
				else
					d[j] = 1.0*(a[i][0]-a[j][0])/(a[i][1]-a[j][1]);
			}
			sort(d+i+1, d+n+1);
			int num = 1;
			for (int j = i+2; j <= n; j ++)
			{
				if (abs(d[j]-d[j-1]) < 1e-8)
					num ++;
				else
				{
					if (num == 2)
						sum ++;
					num = 1;
				}
			}
			if (num == 2)
				sum ++;
		}
		printf("%d\n", sum);
	}
}
/*
连珠星线
时间限制：1000 ms  |  内存限制：65535 KB
难度：5
描述
zyc小时候有时候会看着夜空里的星星发呆，他是在思索一些数学问题（不是哲学，呵呵）。

他规定：如果三个或三个以上的星星在同一条直线上，则称这条直线为连珠星线。

现在，请你帮他计算一下满天的星星构成了多少条连珠星线。

输入
第一行输入一个整数T表示测试数据的组数(1<=T<=5)
每组测试数据的第一行是一个整数N(1<=N<=1000),表示天空中有N个星星。
随后的N行每行有两个整数xi,yi(0<=xi,yi<=10000)，表示一个星星的坐标。数据保证任意两个星星不会拥有完全相同的坐标
输出
对于每组数据，输出连珠星线的条数。每组测试数据的输出独占一行。
样例输入
2
3
1 2
1 3
1 4
5
0 1
1 2
2 3
2 4
4 8 
样例输出
1
2
*/
