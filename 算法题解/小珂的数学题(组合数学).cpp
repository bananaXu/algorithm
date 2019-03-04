#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <cmath>
#include <ctype.h>
using namespace std;

int c(int m, int n)
{
	int i, j;
	int sum = 1;
	for (i = 1; i <= n; i ++)
	{
		sum = sum*(m-n+i)/i;
	}
	return sum;
} 

int main()
{
	char s[30];
	int i, j, l, sum;
	bool f;
	while (~scanf("%s", &s))
	{
		sum = 1;
		l = strlen(s)-1;
		f = true;
		if (l)
		{
			for (i = 1; i <= l; i ++)
			{
				if (s[i] <= s[i-1])
				{
					f = false;
					break;
				}
			}
		}
		if (!f)
		{
			printf("0\n");
		}
		else
		{
			for (i = 1; i <= l; i ++)
				sum += c(26, i);
			for (i = 0; i <= l; i ++)
			{
				for (j = 1; j <= s[i]-'a'-i; j ++)
					sum += c(25-i-j, l-i); 
			}
			printf("%d\n", sum);
		}
	}
	return 0;
}
/*
小珂的数学题
时间限制：1000 ms  |  内存限制：65535 KB
难度：3
描述
今天小珂在书上看到了一种数值表示方式，请你写一个程序帮助她迅速转化一下。题目信息如下：

         已知一种对应关系,从a开始按照字典序增加，字符串最长为5，遇到相同的或者后面的字符不比前面的大的字符串就不计数。

         a->1

         b->2

         ……

         ……

         z->26

ab->27

ac->28

……

……

vwxyz->83681

……

输入
会输入少于200行的数据，每一行有一个字符串。如果出现不符合规则的字符串（各个字符不是单调递增）的，输出0，否则输出它对应的数。（例如are 不合规则，对应输出0）
输出
输出每个结果，换行结束。
样例输入
a
z
cat
vwxyz
样例输出
1
26
0
83681

*/
