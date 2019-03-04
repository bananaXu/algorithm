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

int getsum(int x)
{
	int i;
	int sum = 0;
	for (i = 1; i <= x; i *= 10)
	{
		sum += x/i/10*i; // x/i/10*i*10中此位出现1的个数 
		if (x/i%10 == 1)
			sum += x%i+1; // 如果此位为1，那么加上从0开始到x%i的个数 
		else if (x/i%10 > 1)
			sum += i;  // 如果此位大于1，那么加上i个 
	}
	return sum;
}

int main()
{
	int a, b;
	while (1)
	{
		scanf("%d%d", &a, &b);
		if (!a && !b)
			break;
		if (a > b)
			swap(a, b);
		printf("%d\n", getsum(b)-getsum(a-1));
	}
	return 0;
} 
/*
1的个数
时间限制：1000 ms  |  内存限制：65535 KB
难度：3
描述
给你两个数a和b,你的任务是计算出1在a和b之间出现的次数,比如说，如果a=1024,b=1032，那么a和b之间的数就是：
1024 1025 1026 1027 1028 1029 1030 1031 1032
则有10个1出现在这些数中。
输入
输入不会超过500行。每一行有两个数a和b，a和b的范围是0 <= a, b <= 100000000。输入两个0时程序结束，两个0不作为输入样例。
输出
对于每一对输入的a和b，输出一个数，代表1出现的个数。
样例输入
1 10
44 497
346 542
0 0
样例输出
2
185
40
*/
