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

#define M 5005
#define MIN(a, b) a < b ? a : b 
#define MAX(a, b) a > b ? a : b 

int main()
{
	int t;
	scanf("%d", &t);
	getchar();
	while (t --)
	{
		char s[M], c[M<<1];
		int a[M<<1]; // 记录该字符在原字符串中位置 
		gets(s);
		int index = 0;
		for (int i = 0; i < strlen(s); i ++)
		{
			if (isalpha(s[i]))
			{
				c[++ index] = '#';
				c[++ index] = toupper(s[i]);
				a[index] = i;
			}
		}
		// 将字符串前后以及每个字符之间添加#，保证子串为奇数，然后将字符串加上不同的头尾，防止越界 
		c[0] = '*'; c[++ index] = '#'; c[++ index] = '.'; 
		int Rad[M<<1];
		int Max = 0;
		Rad[0] = 0;
		for (int i = 1, j = 0, k = 0; i < index; i += k)
		{
			while (c[i-j-1] == c[i+j+1]) j ++;
			Rad[i] = j;
			if (j > Rad[Max]) // 子串开头结尾一定是#，所以可以知道半径越大子串长度一定最长 
				Max = i;
			for (k = 1; k <= j && Rad[i-k] != Rad[i]-k; k ++)
				Rad[i+k] = MIN(Rad[i-k], Rad[i]-k);
			j = MAX(0, Rad[i]-k);
		}
		int l = a[Max-Rad[Max]+1], r = a[Max+Rad[Max]-1]; // 计算在原字符串中位置 
		for (int i = l; i <= r; i ++)
			printf("%c", s[i]);
		printf("\n");
	}
	return 0;
} 
/*
最长回文子串
时间限制：1000 ms  |  内存限制：65535 KB
难度：4
描述
输入一个字符串，求出其中最长的回文子串。子串的含义是：在原串连续出现的字符串片段。回文的含义是：正着看和倒着看是相同的，如abba和abbebba。在判断是要求忽略所有的标点和空格，且忽略大小写，但输出时按原样输出（首尾不要输出多余的字符串）。输入字符串长度大于等于1小于等于5000，且单独占一行(如果有多组答案，输出第一组)。
输入
输入一个测试数据n（1<=n<=10）；
随后有n行，每行有一个字符串。
输出
输出所要求的回文子串。
样例输入
1
Confuciuss say:Madam,I'm Adam.
样例输出
Madam,I'm Adam
*/
