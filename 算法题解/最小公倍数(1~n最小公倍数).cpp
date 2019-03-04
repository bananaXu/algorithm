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

int a[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

void getm(int n)
{
	int i, j, t ,len;
	int b[50] = {0};
	b[0] = 1;
	len = 0;
	for (i = 0; a[i] <= n; i ++)
	{
		t = (int)(log(n+0.0001)/log(a[i]));
		t = (int)pow(1.0*a[i], t);
		for (j = 0; j <= len; j ++)
		{
			b[j] *= t;
		}
		for (j = 0; j <= len; j ++)
		{
			if (b[j] > 9)
			{
				b[j+1] += b[j]/10;
				b[j] %= 10; 
				if (j == len)
					len ++;
			}
		}
	}
	for (i = len; i >= 0; i --)
		printf("%d", b[i]);
	printf("\n");
}

int main()
{
	int n;
	while(~scanf("%d", &n))
	{
		getm(n);
	}
	return 0;
}
/*
最小公倍数
时间限制：1000 ms  |  内存限制：65535 KB
难度：3
描述
为什么1小时有60分钟，而不是100分钟呢？这是历史上的习惯导致。
但也并非纯粹的偶然：60是个优秀的数字，它的因子比较多。
事实上，它是1至6的每个数字的倍数。即1,2,3,4,5,6都是可以除尽60。

我们希望寻找到能除尽1至n的的每个数字的最小整数m.
输入
多组测试数据（少于500组）。
每行只有一个数n(1<=n<=100).
输出
输出相应的m。
样例输入
2
3
4
样例输出
2
6
12
*/
