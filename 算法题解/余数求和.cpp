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

typedef long long ll;
#define MIN(a, b) a < b ? a : b

int main()
{
	ll i, n, A1, An, k, l, r, t, sum;
	// 可以发现商相等的情况下，余数呈等差数列，公差为商 
	// 枚举商，将一个商下的等差数列求和 
	while (~scanf("%lld%lld", &n, &k))
	{
		sum = 0;
		t = (int)sqrt(k);
		if (n >= k)
		{
			sum += (n-k)*k;
			for (i = 1; i <= t; i ++) // 先计算n商为1~sqrt(n)的 
			{	
				l = k/(i+1)+1;
				r = k/i; 
				A1 = k%l;
			 	An = k%r;
				sum += (A1+An)*(r-l+1)/2;
			} 
			for (i = r-1; i >= 1; i --) // 加上未计算的商为sqrt(n)以上的 
				sum += k%i;
		}
		else
		{
			for (i = 1; i <= t; i ++) // 先计算n商为1~sqrt(n)的 
			{
				l = k/(i+1)+1;
				r = k/i;
				if (l <= n)
				{
					r = MIN(r, n);
					A1 = k%l;
				 	An = k%r;
					sum += (A1+An)*(r-l+1)/2;
				}
			} 
			for (i = MIN(r-1, n); i >= 1; i --) // 如果n非常小直接从n开始 
				sum += k%i; 
		} 
		printf("%lld\n", sum);
	}
	return 0;
}
/*
给你两个数n，k，请求出sum(k%i)(i为1~n)的值。
*/
