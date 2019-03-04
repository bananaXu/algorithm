#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

// 能量守恒 
//(ai-1, ai, ai+1) (ai-1+ai, -ai, ai+ai+1)
//S1=ai-1 S1’=ai-1+ai
//S2=ai-1+ai S2’=ai-1
//S3=ai-1+ai+ai+1 S3’=ai-1+ai+ai+1
//很容易看出S3=S3’，(S1,S2)=(S2’,S1’)。也就是说把(S1,S2,S3)中的S1和S2交换
//位置就能得到(S1’,S2’,S3’)。
//稍微推广一下：设Si=a1+a2+…+ai，对(ai-1, ai, ai+1)操作本质上和交换Si-1, Si
//是等价的。（因为Si-2是固定不变的）
int main()
{
	int i, n, t;
	int a[1005];
	int b[1005];
	scanf("%d", &t);
	while (t --)
	{
		scanf("%d", &n);
		a[0] = b[0] = 0;
		for (i = 1; i <= n; i ++)
		{
			scanf("%d", &a[i]);
			a[i] += a[i-1];
		}
		for (i = 1; i <= n; i ++)
		{
			scanf("%d", &b[i]);
			b[i] += b[i-1];
		}
		if (a[n] != b[n])
		{
			printf("No\n");
			continue;
		}
		sort(a+1, a+n+1);
		sort(b+1, b+n+1);
		for (i = 1; i <= n-1; i ++)
		{
			if (a[i] != b[i])
			{
				printf("No\n");
				break;
			}
		}
		if (i == n)
			printf("Yes\n");
	}
	return 0;
}
/*
描述
有一个数列a1,a2,a3...an,每次可以从中任意选三个相邻的数ai-1 ,ai , ai+1 ,进行如下操作（此操作称为“对ai进行操作”）

(ai-1,ai,ai+1)->(ai-1+ai,-ai,ai+ai+1)

给定初始和目标序列，是否能通过以上操作，将初始序列转换成为目标序列？例如，初始序列(1 6 9 4 2 0)目标序列（7 -6 19 2 -6 6)可经过如下操作：

 (1 6 9 4 2 0)->( 1 6 13 -4 6 0)->(1 6 13 2 -6 6)->(7 -6 19 2 -6 6)

请你判断给定的初始状态和目标状态，输出Yes（能够转换）或No（不能转换）

输入
第一行是一个正整数N,表示测试数据的组数。(N<=100)
每组测试数据的第一行是一个整数M(3<=M<=1000),表示该组测试数据的起始状态与结束状态都有M个数。
每组测试数据的第二行是M个整数Ai(-1000<=Ai<=1000)，表示起始状态。
每组测试数据的第三行是M个整数Bi(-1000<=Bi<=1000),表示终止状态。
输出
如果能够转换，输出Yes
如果不能转换，输出No
样例输入
2
3
1 2 3
1 3 2
6
1 6 9 4 2 0
7 -6 19 2 -6 6
样例输出
No
Yes
*/
