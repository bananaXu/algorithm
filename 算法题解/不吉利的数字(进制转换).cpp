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
{
	int x, y, sum;
	bool lucky;
	while (~scanf("%d", &x)) 
	{
		if (!x)
		{
			printf("Unlucky\n");
			continue;
		}
		lucky = true;
		y = x;
		while (y) // 输入含0或者输入就是0, 
		{
			if (!(y%10))
			{
				lucky = false;
				break;
			}
			y /= 10;
		}
		if (!lucky)
		{
			printf("Unlucky\n");
			continue;
		}
		y = 1; sum = 0;
		while (x) // 将此数从9进制转换为10进制 
		{
			sum += x%10*y;
			y *= 9;
			x /= 10;
		}
		printf("%d\n", sum);
	}
	return 0;
}
/*
不吉利的数字
时间限制：1000 ms  |  内存限制：65535 KB
难度：1
描述
 一些普通的数字在很多人眼里是不吉利。如数字4，谐音“死”，所以很多地方都没有带4的数字：比如新校区澡堂衣柜编号及没有4；再如数字13，在西方人眼中代表着坏运气，也是不吉利的数字，13不出远门，楼层不设第13层等等。

假如某些人认为0是不吉利的数字，并且在他们以后的生活中，记录数据都在不在使用含有0的自然数。

他们记录数的序列是1,2,3,4,5,6,7,8,9,11,12,13,14,15,16,17,18,19,21,22.......n，由于不使用数字0，他们记录的数和我们实际使用的自然数有一定的差别，如他们的11，实际就是第10个数，21就是第19个数，以此类推。。。   

现在给你一个数n,请判断在不不含0的序列中的，如果在，求n是第几个数，不在，输出Unlucky。

Hint：  105,10523等等，都是含有0的

输入
有多组测试数据<5000
每组数据占一行，每行有一个数n（0<=n<=1000000）。
以EOF结尾
输出
每组输出占一行，如果n在不含0的序列中，输出是第几个。如果不在不含0的序列中，输出Unlucky；
样例输入
11
9
21
10
样例输出
10
9
19
Unlucky
*/
