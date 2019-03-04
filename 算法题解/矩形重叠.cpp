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

#define M 55
#define MAX(a, b) a > b ? a : b

/*
分析：
重合的部分顶点坐标一定是原来矩形的某个x坐标和某个y坐标组成
枚举所有可能的点
用这些点为顶点造一个边为1的正方形，看有多少个矩形覆盖该正方形
求出最大的就是题目所求 
*/

int main()
{
	int n;
	scanf("%d", &n);
	set <int> x, y;
	set <int>::iterator itx, ity;
	int x1[M], x2[M], y1[M], y2[M];
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", &x1[i]); 
		x.insert(x1[i]);
	}
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", &y1[i]); 
		y.insert(y1[i]);
	}
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", &x2[i]); 
		x.insert(x2[i]);
	}
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", &y2[i]); 
		y.insert(y2[i]);
	}
	int Max = 0;
	for (itx = x.begin(); itx != x.end(); itx ++)
	{
		for (ity = y.begin(); ity != y.end(); ity ++)
		{
			int X = *itx, Y = *ity, num = 0;
			for (int i = 1; i <= n; i ++)
			{
				if (X >= x1[i] && X+1 <= x2[i] && Y >= y1[i] && Y+1 <= y2[i])
					num ++;
			}
			Max = MAX(Max, num);
		}
	} 
	printf("%d\n", Max);
	return 0;
}
/*
平面内有n个矩形, 第i个矩形的左下角坐标为(x1[i], y1[i]), 右上角坐标为(x2[i], y2[i])。
如果两个或者多个矩形有公共区域则认为它们是相互重叠的(不考虑边界和角落)。
请你计算出平面内重叠矩形数量最多的地方,有多少个矩形相互重叠。

输入描述:
输入包括五行。
第一行包括一个整数n(2 <= n <= 50), 表示矩形的个数。
第二行包括n个整数x1[i](-10^9 <= x1[i] <= 10^9),表示左下角的横坐标。
第三行包括n个整数y1[i](-10^9 <= y1[i] <= 10^9),表示左下角的纵坐标。
第四行包括n个整数x2[i](-10^9 <= x2[i] <= 10^9),表示右上角的横坐标。
第五行包括n个整数y2[i](-10^9 <= y2[i] <= 10^9),表示右上角的纵坐标。


输出描述:
输出一个正整数, 表示最多的地方有多少个矩形相互重叠,如果矩形都不互相重叠,输出1。

输入例子1:
2
0 90
0 90
100 200
100 200

输出例子1:
2
*/
