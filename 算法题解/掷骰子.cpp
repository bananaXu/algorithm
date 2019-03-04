#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <cmath>
#include <vector> 
#include <queue>
#include <ctype.h>
using namespace std;

int main()
{	// 将1~10的骰子可能数量打表，再算概率 
	int a[11][65] = {0};
	int i, j, k;
	for (i = 1; i <= 6; i ++)
		a[1][i] = 1;
	for (i = 2; i <= 10; i ++)
	{
		for (j = 1; j <= 6; j ++)
		{
			for (k = i-1; k <= 6*(i-1); k ++)
			{
				a[i][j+k] += a[i-1][k];
			}
		}
	}
	int t, m, n;
	double sum;
	int b[60];
	scanf("%d", &t);
	while (t --)
	{
		scanf("%d%d", &m, &n);
		if (n == 1 && m > 6)
		{
			printf("1.000000\n");
			continue;
		}
		if (m == 1 && n > 6)
		{
			printf("0.000000\n");
			continue;
		}	
		memset(b, 0, sizeof(b));
		sum = 0.0;
		b[n] = a[n][n];
		for (i = n+1; i <= 6*n; i ++)
			b[i] = b[i-1]+a[n][i];
		for (i = m; i <= 6*m; i ++)
		{
			if (i <= n)
				continue;
			if (b[i-1] && a[m][i])
				sum += (1.0*a[m][i]/pow(6.0, m))*(1.0*b[i-1]/pow(6.0, n));
			else if(a[m][i])
				sum += 1.0*a[m][i]/pow(6.0, m);
		}
		printf("%.6f\n", sum);
	}
	return 0;
}
/*
掷骰子
时间限制：3000 ms  |  内存限制：65535 KB
难度：4
描述
小明有m个骰子，小红有n个骰子。每一个骰子都是标准六面骰子。他们分别掷出自己的骰子，如果小明的点数和大，则小明胜；否则小红胜。求小明胜利的概率。
输入
有T组数据。每组数据一行，m和n，用空格隔开。1 <= m, n <= 10
输出
对于每一组数据，输出小明获胜的概率。每组输出占一行，用四舍五入法，精确到小数点后面6位。
样例输入
1
1 1 
样例输出
0.416667
*/
