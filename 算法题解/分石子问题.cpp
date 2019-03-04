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

int main()
{
	int t;
	scanf("%d", &t);
	while (t --)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		int sum = 0;
		for (int i = 1; i <= n; i ++)
		{
			int x;
			scanf("%d", &x);
			sum ^= (x-1)/(m-1);
		}
		if (sum)
			printf("Win\n");
		else
			printf("Lose\n");
	}
	return 0;
}
/*
分石子问题
时间限制：2000 ms  |  内存限制：65535 KB
难度：6
描述
闲来无事，zyc发明了一种游戏，叫分石子游戏，初始有D堆石子，每堆石子的数量已知。

两个人轮流分石子，可以选取这D堆石子中的任意一堆，然后把选中的这堆石子分成M堆（每堆石子数量都必须大于0），现在石子的堆数将变成D+M-1堆，对方就可以在这D+M-1堆石子中任意选一堆分成M堆，依次分下去，直到某人无法执行这种操作时则无法执行操作的人输掉了这场游戏。

如果玩游戏的双方都非常聪明，现在给你一个初始状态，请你判断先分石子的人是会取胜还是会失败。

输入
第一行是一个整数T，表示测试数据的组数（T<=10)
每组测试数据的第一行是两个整数D,M(0<D<100,2<=M<=7)
随后的一行有D个正整数Ni(Ni<100),表示每堆石子的初始数量。
输出
如果先分石子的人获胜则输出Win
否则输出Lose
样例输入
2
1 3
5
2 3
5 6
样例输出
Win
Lose
*/
