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

#define MAX(a, b) a > b ? a : b

int main()
{
	int i, j, t, n, m, x, Max;
	int a[50005];
	int p[50005];
	vector <int> iv;
	vector <int>::iterator it;
	scanf("%d", &t);
	while (t --)
	{
		scanf("%d", &n);
		memset(a, 0, (n+1)*sizeof(int));
		for (i = 1; i <= n; i ++)
		{
			scanf("%d", &m);
			for (j = 1; j <= m; j ++)
			{
				scanf("%d", &x);
				iv.push_back(x);
			}
			for (j = 1; j <= m; j ++)
			{
				it = iv.begin(); x = 0;
				while (*it != j) 
				{
					it ++;
					x ++;
				}
				a[i] += x;
				iv.erase(it);
			} // 先用贪心求每个班用时 
		}
		p[0] = -1; Max = 0;
		for (i = n; i >= 1; i --)
		{
			if (a[i] >= p[Max]) // 用log2(n)求最长不降子序列 
			{
				p[++ Max] = a[i];
				continue;
			}
			x = upper_bound(p+1, p+Max+1, a[i])-p;
			p[x] = a[i];
		}
		printf("%d\n", Max);
	}
	return 0;
}
/*
冬季长跑
时间限制：5000 ms  |  内存限制：65535 KB
难度：4
描述
为了增强大学生的身体素质，校长决定进行冬季长跑。有N个班级要参加冬季长跑，班级的编号从1到N。
听说这个消息之后学生们马上都集中到体育场上。但是，由于学生们来的匆忙，所以并不是按照学号排列的。
这样很混乱，所以要让他们调整位置按学号排列。为了防止调整过程出现混乱，校长要求，
每个班级每次只能找相邻的两个人交换位置。我们认为每次交换都需要花费10秒时间。
当然，每个班级都会采取最快的方案交换完毕，在整理好队列后就立即出发。由于每个班级要整理队列的时间不同，
所以校长决定要将长跑的N个班级分成若干小组，每个小组中的班级利用一条跑道。在每个跑道上的班级必须满足，
前面的班级的编号小于后面的班级的编号。在调整队列之前，我们的校长想知道，最少需要用到多少条跑道。
注意：同时出发的两个班级不可以在同一条跑道上。 

样例Hint

说明：班级1、2、3调整所需时间分别为0s、30s、10s，所以至少需要两条跑道，有两种可能：1、2共用一条跑道，
3单独一条；或者1、3共用一条跑道，2单独一条。 

输入
一个整数T表示测试组数。

对于每组测试数据：

首先、一个整数N代表班级的个数。

然后、后面有N行，每行代表一个班级。每行由一个整数Mi和后面的Mi个整数。其中Mi是班级i的人数，
后面的Mi是未排队之前的班级i的学号队列，范围1~Mi。
输出
对于每组数据，输出一个整数K，代表最少的跑道数。每组输出各占一行。


数据范围：
1 <= T <= 10
1 <= N <= 50000
1 <= Mi<= 20
样例输入
1
3
3 1 2 3
3 3 2 1
3 2 1 3 
样例输出
2
*/
