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

/*
分析： 
y = k+1, x = t*(k+1)+k
y = k+2, x = t*(k+2)+k || x = t*(k+2)+k+1
y = k+3, x = t*(k+3)+k || x = t*(k+3)+k+1 || x = t*(k+3)+k+2
...
y = n, x = k, k+1, ... n-1
那么x/(k+t)*t+剩余的x%(k+t)中大于等于k的就是所求(k == 0时不包含k) 
*/

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	long long sum = 0;
	if (k == 0)
		sum = (long long)n*n;
	else
	{
		for (int i = 1; i <= n-k; i ++)
		{
			int t = n%(k+i);
			sum += n/(k+i)*i+(t >= k ? t-k+1 : 0);
		}
	}
	printf("%lld\n", sum);
	return 0;
}
/*
牛牛以前在老师那里得到了一个正整数数对(x, y), 牛牛忘记他们具体是多少了。
但是牛牛记得老师告诉过他x和y均不大于n, 并且x除以y的余数大于等于k。
牛牛希望你能帮他计算一共有多少个可能的数对。

输入描述:
输入包括两个正整数n,k(1 <= n <= 10^5, 0 <= k <= n - 1)。


输出描述:
对于每个测试用例, 输出一个正整数表示可能的数对数量。

输入例子1:
5 2

输出例子1:
7

例子说明1:
满足条件的数对有(2,3),(2,4),(2,5),(3,4),(3,5),(4,5),(5,3)
*/
