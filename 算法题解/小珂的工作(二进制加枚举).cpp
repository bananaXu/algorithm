#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <cmath>
#include <ctype.h>
using namespace std;

#define MAX(a, b) a > b ? a : b
int n, m, Max, MaxNum;
int a[1007];
int b[17];

void GetMaxNum()
{
	int i, x, sum;
	x = sum = 0;
	for (i = 1; i <= Max; i ++)
	{
		x += 1<<(b[i]-1); // 将此时能够接受的病毒用二进制存储 
	}
	for (i = 1; i <= n; i ++)
	{
		if ((x|a[i]) == x) // 如果此牛奶没有接受病毒之外的病毒，则总数加一 
			sum ++;
	}
	MaxNum = MAX(MaxNum, sum);
}

void find(int x, int y)
{
	int i; // 枚举包含的病毒类型 
	if (x == Max+1) // 当病毒数量与最大承受数量相同时，计算能选择的奶牛数量 
	{
		GetMaxNum();
		return;
	}
	for (i = y; i <= m-Max+x; i ++)
	{
		b[x] = i;
		find(x+1, i+1);
	}
}

int main()
{
	int i, j, t, x, v;
	scanf("%d", &t);
	while (t --)
	{
		MaxNum = 0;
		scanf("%d%d%d", &n, &m, &Max);
		for (i = 1; i <= n; i ++)
		{
			scanf("%d", &x);
			a[i] = 0;
			for (j = 1; j <= x; j ++)
			{
				scanf("%d", &v);
				a[i] += 1<<(v-1); // 将牛奶包含的病毒用二进制存储 
			}
		}
		find(1, 1);
		printf("%d\n", MaxNum);
	}
	return 0;
} 
/*
小珂的工作
时间限制：1000 ms  |  内存限制：65535 KB
难度：4
描述
小珂有一个奶牛场，奶牛场最近在流行D（1<D<=15）种病毒，小珂的农场一共有N（1<N<=1000）只奶牛，含超过K（1<=K<=D）种病毒的牛奶不得不丢弃.(牛奶中含有奶牛身上的病毒)。现在希望你写一个程序，来确定一下一个桶里的最多可以包含多少头奶牛的牛奶。

输入
第一行一个整数M（1<M<=7）,表示有M组测试数据，接下来的M组数据的第一行有三个整数，N，D，K，分别表示奶牛的数量，病毒的总种类，最多一个桶中可以包含的病毒数量。接下来N行，第i行，第一个数 i1，表示第i头牛包含的病毒种类个数，随后i1个数，表示的是病毒种类的标号(默认对D个病毒尽心标号，从1到D )，如果i1 为0，表示第没有病毒。
输出
每组数据输出可以最多挤多少头牛（不换桶），换行结束。
样例输入
1
6 3 2
0
1 1
1 2
1 3
2 2 1
2 2 1
样例输出
5
*/
