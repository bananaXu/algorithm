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

int sum[80][80];
int cutl[5], cutr[5];
int n, m;

bool legal(int num, int v)
{
	for (int i = 1; i <= 4; i ++)
	{
		int x = cutl[i-1], y = cutr[num-1], x1 = cutl[i], y1 = cutr[num];
		if (sum[x1][y1]+sum[x][y]-sum[x1][y]-sum[x][y1] < v)
			return false;
	}
	return true;
}

bool rcut(int num, int v)
{
	if (num == 4)
		return legal(4, v);
	for (int i = cutr[num-1]+1; i <= m-4+num; i ++)
	{
		cutr[num] = i;
		if (legal(num, v))
		{ 
			if (rcut(num+1, v))
				return true;
			break;
		}
	}
	return false;
}

bool lcut(int num, int v)
{
	if (num == 4)
	{
		if (sum[cutl[4]][m]-sum[cutl[3]][m] > (v<<2))
			return rcut(1, v);
		return false;
	}
	for (int i = cutl[num-1]+1; i <= n-4+num; i ++)
	{
		cutl[num] = i;
		if (sum[n][m]-sum[i][m] <= (4-num)*(v<<2))
			return false;
		if (sum[cutl[num]][m]-sum[cutl[num-1]][m] >= (v<<2) && lcut(num+1, v))
			return true;
	}
	return false;
}

int search(int l, int r)
{
	if (l == r)
		return l;
	cutl[4] = n;
	cutr[4] = m;
	int mid = (l+r)>>1;
	if (lcut(1, mid+1))
		return search(mid+1, r);
	else
		return search(l, mid);
}

int main()
{
//	freopen("./in.txt", "r", stdin);
//	freopen("./out.txt", "w", stdout);
	while (~scanf("%d%d", &n, &m))
	{
		char s[80];
		for (int i = 1; i <= n; i ++)
		{
			scanf("%s", &s);
			for (int j = 1; j <= m; j ++)
			{
				int t = s[j-1]-'0';
				sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+t;
			}
		}
		printf("%d\n", search(0, sum[n][m]>>4));
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
/*
牛牛和 15 个朋友来玩打土豪分田地的游戏，牛牛决定让你来分田地，地主的田地可以看成是一个矩形，每个位置有一个价值。分割田地的方法是横竖各切三刀，分成 16 份，作为领导干部，牛牛总是会选择其中总价值最小的一份田地， 作为牛牛最好的朋友，你希望牛牛取得的田地的价值和尽可能大，你知道这个值最大可以是多少吗？
输入描述:
每个输入包含 1 个测试用例。每个测试用例的第一行包含两个整数 n 和 m（1 <= n, m <= 75），表示田地的大小，接下来的 n 行，每行包含 m 个 0-9 之间的数字，表示每块位置的价值。
输出描述:
输出一行表示牛牛所能取得的最大的价值。
示例1
输入
4 4
3332
3233
3332
2323
输出
2
*/
//1468 
