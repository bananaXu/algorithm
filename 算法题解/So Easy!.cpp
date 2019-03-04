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

/*
思路：
由于(a-1)^2< b < a^2,所以a-sqrt(b)<1, (a-sqrt(b))^n<1
而(a+sqrt(b))^n+(a-sqrt(b))^n多项式展开相加后为整数
所以Sn = (a+sqrt(b))^n+(a-sqrt(b))^n
Sn+1 = (a+sqrt(b))^n*(a+sqrt(b))+(a-sqrt(b))^n*(a-s	qrt(b))
     = 2*aSn-(a^2-b)Sn-1
转换成矩阵相乘
Sn 	  Sn-1    * 	2a 		1
0     0				b-a^2	0
题目就成了求快速矩阵幂 
*/

void MULITI(ll a[2][2], ll b[2][2], int m)
{
	ll c[2][2];
	c[0][0] = a[0][0]*b[0][0]%m+a[0][1]*b[1][0]%m;
	c[0][1] = a[0][0]*b[0][1]%m+a[0][1]*b[1][1]%m;
	c[1][0] = a[1][0]*b[0][0]%m+a[1][1]*b[1][0]%m;
	c[1][1] = a[1][0]*b[0][1]%m+a[1][1]*b[1][1]%m;
	a[0][0] = c[0][0]%m; a[0][1] = c[0][1]%m;
	a[1][0] = c[1][0]%m; a[1][1] = c[1][1]%m;
}

int main()
{
	int a, b, n, m;
	ll p[2][2], q[2][2]; 
	while (~scanf("%d%d%d%d", &a, &b, &n, &m))
	{
		p[0][0] = 2*a%m; 			 p[0][1] = 1;
		p[1][0] = ((b-a*a)%m+m)%m;	 p[1][1] = 0;
		q[0][0] = (2*a*a%m+2*b%m)%m; q[0][1] = 2*a%m;
		q[1][0] = q[1][1] = 1;
		if (n == 1)
		{
			printf("%d\n", q[0][1]);
			continue;
		}
		n -= 2;
		while (n)
		{
			if (n&1)
				MULITI(q, p, m);
			MULITI(p, p, m);
			n >>= 1;
		}
		printf("%d\n", q[0][0]);
	}
	return 0;
}
/*
描述
A sequence Sn is defined as:
Sn = [(a+sqrt(b))^n](向上取整)%m
Where a, b, n, m are positive integers.┌x┐is the ceil of x. For example, ┌3.14┐=4. You are to calculate Sn.
You, a top coder, say: So easy!
输入
There are several test cases, each test case in one line contains four positive integers: a, b, n, m. Where 0< a, m < 2^15, (a-1)^2< b < a^2, 0 < b, n < 2^31.
The input will finish with the end of file.
输出
For each the case, output an integer Sn.
样例输入
2 3 1 2013
2 3 2 2013
2 2 1 2013
样例输出
4
14
4
*/
