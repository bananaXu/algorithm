#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <cmath>
#include <vector> 
#include <ctype.h>
using namespace std;

int s[30];

int getsum(int x)
{
	int i, sum, t;
	sum = 0; i = -1;
	if (!x)
		return 0;
	t = ++ x;
	while ((s[++ i]>>1) <= x)
	{
		if (s[i]&x)
		{
			sum += x&(s[i]-1);
			t &= t-1;
		}
		sum += t>>1;
	}
	return sum;
}

int main()
{
	int i, a, b;
	scanf("%d%d" ,&a, &b);
	s[0] = 1;
	for (i = 1; i <= 29; i ++)
	{
		s[i] = s[i-1]<<1;
	}
	printf("%d\n", getsum(b)-getsum(a-1));
	return 0;
} 
/*
整数中的1
时间限制：3000 ms  |  内存限制：10000 KB
难度：4
描述
给出两个非负32位整型范围内的数a,b，请输出闭区间[a,b]内所有数二进制中各个位的1的总个数。
输入
一行，给出两个整形数a,b(0<=a<=b<=150000000)，空格分隔。
输出
一行，输出结果
样例输入
1 2
样例输出
2
*/
