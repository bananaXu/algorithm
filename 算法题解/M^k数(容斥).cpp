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

#define EPS 1e-8
typedef long long ll;

int a[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
// 2^60大于10^18
// n^(1/p)为1~n中p次方的个数
// 利用容斥定理，求出所有素数次方的数的和，减去两两相乘次方的，再加上三个相乘次方的.... 
// 由于四个素数相乘必大于60，三个相乘中只有2*3*5和2*3*7小于60
// 所以只需求单个素数、两两相乘和2*3*5和2*3*7 
int main()
{
	ll i, j, k, n, sum, t;
	while(~scanf("%lld", &n))
	{
		sum = 1;
		for (i = 0; i <= 16; i ++)
		{
			t = (ll)(pow(double(n), 1.0/a[i])+EPS);
			if (t == 1)
				break;
			sum += t-1;
		} 
		for (i = 0; i <= 9; i ++)
		{
			for (j = i+1; j <= 10; j ++)
			{
				if (a[i]*a[j] < 60)
				{
					t = (ll)(pow(double(n), 1.0/(a[i]*a[j]))+EPS);
					if (t == 1)
						break;
					sum -= t-1;
				}
			}
		}
		t = (ll)(pow(double(n), 1.0/(30))+EPS);
		sum += t-1;
		t = (ll)(pow(double(n), 1.0/(42))+EPS);
		sum += t-1;
		printf("%lld\n", sum);
	}
	return 0;
} 
/*
M^k数
时间限制：1000 ms  |  内存限制：65535 KB
难度：4
描述
给你一个数n，请算出1～n之间有多少个整数能表示为M^k(k>1，m，k都是正整数)形式的个数。
输入
每行一个整数n（1<=n<=10^18)。
输出
输出1～n符合条件的数的个数。
样例输入
4
36
1000000000000000000
样例输出
2
9
1001003332
*/

