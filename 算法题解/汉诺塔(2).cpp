#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

/*
思路：容易得知(1~n)金片移动到另一个针上需要2^n次，
那么(1~n)从x1移动到第t个针加上(1~n-1)从x2(n-1所在位置)移动到x1上。。即为所求 
*/

int main()
{
	int a[35];
	int step[35];
	int i, t, n, x, sum;
	step[1] = 1;
	for (i = 2; i <= 32; i ++)
		step[i] = step[i-1]<<1;
	scanf("%d", &t);
	while (t --)
	{
		scanf("%d", &n);
		sum = 0;
		for (i = 1; i <= n; i ++)
			scanf("%d", &a[i]);
		x = 3;
		for (i = n; i >= 1; i --)
		{
			if (x != a[i])
			{
				sum += step[i];
				x = 6-x-a[i];
			}
		}
		printf ("%d\n", sum);
	}
	return 0;
}
/*
描述
汉诺塔的规则这里就不再多说了，详见题目：汉诺塔（一）

现在假设规定要把所有的金片移动到第三个针上，给你任意一种处于合法状态的汉诺塔，你能计算出从当前状态移动到目标状态所需要的最少步数吗？

输入
第一行输入一个整数N，表示测试数据的组数(0<N<20)
每组测试数据的第一行是一个整数m表示汉诺塔的层数(0<m<32)，随后的一行有m个整数Ai,表示第i小的金片所在的针的编号。（三根针的编号分别为1，2，3）
输出
输出从当前状态所所有的金片都移动到编号为3的针上所需要的最少总数
样例输入
2
3
1 1 1
3
1 1 3
样例输出
7
3
*/
