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
#include <string>
using namespace std;

#define M 105

struct EDGE
{
	int r, next;
}edge[M*M];

bool a[60005], used[M];
int b[M], head[M], match[M];
int Index;

void insert(int l, int r)
{
	edge[Index].r = r;
	edge[Index].next = head[l];
	head[l] = Index ++;
}

bool Dfs_Match(int x) // dfs匈牙利匹配
{
	int i;
	for (i = head[x]; i != -1; i = edge[i].next)
	{
		int r = edge[i].r;
		if (!used[r]) // 不在交替路中
		{
			used[r] = 1;
			if (match[r] == -1 || Dfs_Match(match[r])) // 找到未匹配点，将路径反向
			{
				match[r] = x;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	for(int i = 4; i < 60000; i += 2)
		a[i] = true;
	for(int i = 3; i*i < 60000; i += 2)
	{
		if(!a[i])
		{
			for(int j = i*i; j < 60000; j += 2*i) 
				a[j] = true;
		}
	}
	int n;
	while (cin >> n)
	{
		memset(head, -1, sizeof(head));
		memset(match, -1, sizeof(match));
		Index = 0;
		for (int i = 1; i <= n; i ++)
			cin >> b[i];
		for (int i = 1; i <= n; i ++)
		{
			for (int j = i+1; j <= n; j ++)
			{
				if (!a[b[i]+b[j]])
				{
					if (b[i]&1)
						insert(i, j);
					else
						insert(j, i);
				}
			}
		}
		int sum = 0;
		for (int i = 1; i <= n; i ++)
		{
			memset(used, false, sizeof(used));
			if (Dfs_Match(i))
				sum ++;
		}
		cout << sum << endl;
	}
	return 0;
}
/*
题目描述
题目描述
若两个正整数的和为素数，则这两个正整数称之为“素数伴侣”，如2和5、6和13，它们能应用于通信加密。现在密码学会请你设计一个程序，从已有的N（N为偶数）个正整数中挑选出若干对组成“素数伴侣”，挑选方案多种多样，例如有4个正整数：2，5，6，13，如果将5和6分为一组中只能得到一组“素数伴侣”，而将2和5、6和13编组将得到两组“素数伴侣”，能组成“素数伴侣”最多的方案称为“最佳方案”，当然密码学会希望你寻找出“最佳方案”。
输入:
有一个正偶数N（N≤100），表示待挑选的自然数的个数。后面给出具体的数字，范围为[2,30000]。
输出:
输出一个整数K，表示你求得的“最佳方案”组成“素数伴侣”的对数。
 
输入描述:
输入说明
1 输入一个正偶数n
2 输入n个整数
输出描述:
求得的“最佳方案”组成“素数伴侣”的对数。
示例1
输入
4
2 5 6 13
输出
2
*/
