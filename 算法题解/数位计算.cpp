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
#include <cfloat>
using namespace std;

typedef long long ll;

int a[21];

ll getsum(ll x, ll k)
{
	ll sum, t, y, pre;
	t = k; y = 1; sum = 0;
	while (y <= x)
	{
		pre =x%t/y;
		sum += x/t*y*a[k-1]+(x%y+1)*pre+a[pre-1]*y;
		t *= k;
		y *= k;
	}
	return sum;
}

int main()
{
	ll l, r, k, i;
	a[0] = 0;
	for (i = 1; i <= 20; i ++)
		a[i] = i+a[i-1];
	while (~scanf("%lld%lld%lld", &l, &r, &k))
		printf("%lld\n", getsum(r, k)-getsum(l-1, k));
	return 0;
}
/*
数位计算
时间限制：1000 ms  |  内存限制：65535 KB
难度：3
描述
擅长计算的小明对数字很感兴趣，关于计算方面的都很在行。不过现在他遇到了一个难题：
他想区间[L,R]内所有数的各个位之和，我想这肯定难不倒你，那么如果让你求所有数在k
进制表示下的各个位之和呢？你能帮他吗？
输入
多组测试数据（不超过10000组）.
每行有三个数字L,R,k（0<=L<=R<10^15,k<=20).
输出
输出所求结果.
样例输入
1 4 3
2 3 3
样例输出
6
3
*/
