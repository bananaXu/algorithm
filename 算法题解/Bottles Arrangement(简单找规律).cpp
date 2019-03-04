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

int main()
{
	int i, n, m;
	while (~scanf("%d%d", &m, &n))
	{
		printf("%d\n", ((m<<1)-(n>>1)+1)*(n>>1)+m-(n>>1));
	}
	return 0;
}
/*
m行n列
每列为1~m
一行两个相邻数之间差不能大于1
找出满足这样的矩阵中行的和最大的一行中最小的那个值 
例 3*3 
1 2 3
2 1 1
3 3 2
最小为8
规律为
m*n
m m-1 m-2 ...m-n/2
m m-1 m-2 ...m-n/2+1
*/
