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

#define EPS 1e-8

struct MAP
{
	int n, m;
	int a[5][5];
}Map[5];

int t;
int a[15][15];

bool CanPut(int n, int m, int i, int j)
{
	for (int k = i; k < Map[n].n+i; k ++)
	{
		for (int l = j; l < Map[n].m+j; l ++)
		{
			if (k >= m || l >= m)
				return false;
			if (a[k][l] && Map[n].a[k-i][l-j])
				return false;
		}
	}
	return true;
}

bool Push(int n, int m)
{
	if (n == t)
	{
		for (int i = 0; i < m; i ++)
		{
			for (int j = 0; j < m; j ++)
				printf("%d", a[i][j]);
			printf("\n");
		}
		return true;
	}
	for (int i = 0; i < m; i ++)
	{
		for (int j = 0; j < m; j ++)
		{
			if (CanPut(n, m, i, j))
			{
				for (int k = i; k < Map[n].n+i; k ++)
				{
					for (int l = j; l < Map[n].m+j; l ++)	
						if (Map[n].a[k-i][l-j])
								a[k][l] = n+1;
				}
				if (Push(n+1, m))
					return true;
				for (int k = i; k < Map[n].n+i; k ++)
				{
					for (int l = j; l < Map[n].m+j; l ++)
						if (a[k][l] == n+1)
							a[k][l] = 0;
				}
			}
		}
	}
	return false;
}

void findREC(int num)
{
	if (num == 1)
	{
		printf("1\n");
		return;
	}
	int m = (int)(sqrt(num*1.0)+EPS);
	if (m*m != num)
	{
		printf("No solution possible\n");
		return;
	}
	if (!Push(0, m))
		printf("No solution possible\n");
}

int main()
{
	while (~scanf("%d", &t))
	{
		int n, m, num = 0;
		memset(a, 0, sizeof(a));
		for (int i = 0; i < t; i ++)
		{
			scanf("%d%d", &Map[i].n, &Map[i].m);
			for (int j = 0; j < Map[i].n; j ++)
			{
				char s[5];
				scanf("%s", &s);
				for (int k = 0; k < Map[i].m; k ++)
				{
					Map[i].a[j][k] = s[k]-'0';
					if (Map[i].a[j][k] == 1)
						num ++;
				}
			}
		}
		findREC(num);
	}
	return 0;
}
/*
输入
本题有多组数据。文件的第一行是一个整数n，表示图形的个数，范围从1到5。
接下来有n个部分，每个部分的第一行是2个整数i和j，表示下面的i行j列用来描述一个图形。图形用0和1表示，1表示图形占有这个位置，0表示不占有，中间没有空格。例如上图中图形A的描述是
2 3
111
101
所有图形的长与宽都不超过5。
根据图形给出的顺序给每个图形编号，从1开始，至多到5。
保证数据无多解情况。
输出
如果不能拼成一个正方形，就输出“No solution possible”；否则，输出一种拼的方案：一个正方形的数阵，每个位置上的数字是占有这个位置的图形的编号，中间没有空格。例如上面A、B、C、D的编号依次是1、2、3、4，那么就可以输出
1112
1412
3422
3442
样例输入
4
1 4
1111
1 4
1111
1 4
1111
2 3
111
001

5
2 2
11
11
2 3
111
100
3 2
11
01
01
1 3
111
1 1
1

样例输出
No solution possible
1133
1153
2223
2444
*/
