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

int a[9][9];

struct Point
{
	Point(){};
	Point(int a, int b) {x = a; y = b;}
	int x;
	int y;
};

Point nextPoint(int x, int y)
{
	if (y < 8)
		return Point(x, y+1);
	return Point(x+1, 0);
}

bool ok(int x, int y, int val)
{
	int i, j;
	for (i = 0; i <= 8; i ++)
	{
		if (a[x][i] == val)
			return false;
	 	if (a[i][y] == val)
	 		return false;
	}
	for (i = x/3*3; i <= x/3*3+2; i ++)
	{
		for (j = y/3*3; j <= y/3*3+2; j ++)
		{
			if (a[i][j] == val)
				return false;
		}
	}
	return true;
}

bool find(int x, int y)
{
	int i, j;
	Point p;
	if (x == 8 && y == 8)
	{
		if (!a[x][y])
		{
			bool f = false;
			for (i = 1; i <= 9; i ++)
			{
				if (ok(x, y, i))
				{
					f = true;
					a[x][y] = i;
					break;
				}
			}
			if (!f)
				return false;
		}
		for (i = 0; i < 9; i ++)
		{
			for (j = 0; j < 9; j ++)
				printf("%d ", a[i][j]);
			printf("\n");
		}
		return true;
	}
	if (a[x][y])
	{
		p = nextPoint(x, y);
		return find(p.x, p.y);
	}
	for (i = 1; i <= 9; i ++)
	{
		if (ok(x, y, i))
		{
			a[x][y] = i;
			p = nextPoint(x, y);
			if (find(p.x, p.y))
				return true;
			a[x][y] = 0;
		}
	}
	return false;
}

int main()
{
	
	int i, j, n;
	scanf("%d", &n);
	while (n --)
	{
		for (i = 0; i < 9; i ++)
		{
			for (j = 0; j < 9; j ++)
				scanf("%d", &a[i][j]); 
		}
		find(0, 0);
	}
	return 0;
} 
/*
2
0 5 0 6 0 1 0 0 0
0 0 7 0 9 0 0 2 0
3 0 0 0 0 4 0 0 1
9 0 0 0 0 0 1 3 0
0 0 8 0 5 0 7 0 0
0 2 6 0 0 0 0 0 8
7 0 0 9 0 0 0 0 5
0 9 0 0 4 0 3 0 0
0 0 0 2 0 8 0 1 0
0 0 5 3 0 0 0 0 0
8 0 0 0 0 0 0 2 0
0 7 0 0 1 0 5 0 0
4 0 0 0 0 5 3 0 0
0 1 0 0 7 0 0 0 6
0 0 3 2 0 0 0 8 0
0 6 0 5 0 0 0 0 9
0 0 4 0 0 0 0 3 0
0 0 0 0 0 9 7 0 0
*/
