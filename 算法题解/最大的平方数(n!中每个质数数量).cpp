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

// 5000000的下一个质数为终点，超过5000000的质数只可能出现一次 
#define M 5000050
#define MOD 1000000007 
typedef long long ll;

ll v;
int a[M+5] = {0};
int b[348515]; // 通过测试得到5000000以内质数个数 

int main()
{
	ll i, j, k, n, x, y, muli, num, pre_num;
	k = 0;
	int z = (int)sqrt(M); 
	for (i = 2; i <= M; i ++) // 将M以内的质数放入b数组 
	{
		if (a[i])
			continue;
		b[++ k] = i;
		if (i <= z)
		{
			for (j = i*i; j <= M; j += i)
			{
				a[j] = 1;
			}
		}
	}
	while (1)
	{   // 质数的数量一定是单调不增的 
		// 将相同数量的质数先相乘，再进行快速幂 
		scanf("%lld", &n);
		if (!n)
			break;
		pre_num = 0; // 上一个质数的数量 
		v = muli = 1;
		for (i = 1; b[i] <= n && i <= k; i ++)
		{
			x = n;
			y = b[i];
			num = 0; // 此质数的数量 
			while(x)
			{
				num += x/y;
				x /= y;
			}
			if (num&1)
				num --;
			if (num == pre_num) // 如果与上一个质数数量相同，先相乘 
				muli = muli*b[i]%MOD;
			else // 如果与上一个质数数量不同，计算上个数量所有质数的pre_num次方 
			{
				while (pre_num)
				{
					if (pre_num&1)
					{
						v = v*muli%MOD;
					}
					muli = muli*muli%MOD;
					pre_num >>= 1;
				}
				pre_num = num;
				muli = b[i];
			}
			if (!num)
		 		break;
		}
		printf("%d\n", v);
	}
	return 0;
} 
/*
最大的平方数
时间限制：3000 ms  |  内存限制：65535 KB
难度：5
描述
给你一个n，请在1～n之间任意选取若干个数字，每个数字最多能选一次，请把你选取的数字相乘，
要求这个乘积必须为一个平方数，那么请就算出最大的符合条件的乘积，并对1000000007取余。
输入
每行一个数字n（1<=n<=10000000)，以一个0结束。
输出
输出答案，每个结果占一行。
样例输入
4
9348095
6297540
0
样例输出
4
177582252
644064736
*/
