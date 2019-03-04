#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

long long a[65];
int b[50]; 
long long sum;

/*
操作1 可以从0 0 1 变到 1 1 0 
操作2 可以从1 1 0 变到 0 0 1
所以1,2可逆
等价于Fn = F(n-1)+F(n-2)
把一个数分成若干不邻的Fib 数的和，称之为Fibonacci 分解
而任意自然数n 的Fibonacci 分解唯一
设不大于n 最大Fib 数是Fp
1.p为奇数 
最大为F(p-1)+F(p-3)+...+F(2) = F(p-1)+F(p-2)-1 = Fp-1 < n
1.p为偶数 
最大为F(p-1)+F(p-3)+...+F(1) = F(p-1)+F(p-2)-1 = Fp-1 < n
所以Fp必包含在解中
...依次分解 
*/

void GetFb()
{
	int i;
	a[0] = 0;
	a[1] = 1;
	for (i = 2; i <= 62; i ++)
		a[i] = a[i-1]+a[i-2];
} 

int main()  
{  
	int t, n, i, len, x;
	scanf("%d", &t);
	GetFb();
	while(t --)
	{
		scanf("%d", &n);
		memset(b, 0, sizeof(b));
		len = 2*log(double(n))/log(3.0)+5;
		i = 1;
		while(n)
		{
			scanf("%d", &x);
			if (x)
			{
				b[1] = x;
				n -= b[1];
				while(n)
				{
					scanf("%d", &b[++ i]);
					n -= b[i];
				}
			}
		}
		i += len;
		x = i;
		sum = 0;
		for (i = len+1; i <= x; i ++)
			sum += a[i]*b[i-len];
		len = upper_bound(a, a+63, sum)-a;
		i = len-1;
		x = 0;
		memset(b, 0, sizeof(b));
		while(sum)
		{
			if (sum >= a[i])
			{
				sum -= a[i];
				b[++ x] = 1;
			}
			else
				++ x;
			i --;
		}
		while (!b[x]) x --;
		for (i = x; i >= 1; i --)
			printf("%d ", b[i]);
		printf("\n");
	}
    return 0;  
}
/*
描述
有一列无限长的格子里面(左右侧棋盘格子数均可无限延伸)，某些格子里面放了棋子。如果某个格子里面有多于一颗棋子，就可以拿走这一颗，并且在这个格子的左边两个格子里面各放一颗。 
 
如果连续两个格子里面都有棋子，可以分别在两个格子里面各拿走一颗，并且在它们右边的格子里面放一颗。

现在的任务是： 
给定初始状态，要求使用以上操作，使得： 
1、每个格子至多只有1颗棋子 
2、没有相邻的两个格子都有棋子。 
简单的说，就是无法继续操作下去了！ 

输入
第一行给出N(0<N<=100),表示有N组测试数据
随后的每组测试数据的第一行给出棋子个数M(0<M<=10000)
接下来一行给出棋子摆放方法，0表示该格子没有棋子，其他数字表示相应格子有该数目的棋子。(有棋子的棋盘格子的总跨度不超过20)
输出
输出最终棋盘摆放方法，每组测试数据占一行。
从第一个有棋子的格子开始输出。
样例输入
2
4
0 0 1 0 0 2 0 0 1
3
0 0 0 0 0 3
样例输出
1 0 1 0 1
1 0 0 0 1

2
10000
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 9999
10000
9999 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1

1 0 0 1 0 1 0 1 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 1 0 1 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 1
1 0 0 1 0 1 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 1 0 1 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 1
*/
