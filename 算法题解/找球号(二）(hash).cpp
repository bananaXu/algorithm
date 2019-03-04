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

#define M 1000005
#define MOD 1000000

int Key[M], head[M], Next[M];
int Index;

void init()
{
	Index = 0;
	memset(Key, 0, sizeof(Key));
	memset(head, -1, sizeof(head));
}

bool Find(int x)
{
	int t = abs(x)%MOD;
	for (int i = head[t]; i != -1; i = Next[i])
	{
		if (Key[i] == x) 
			return true;
	}
	return false;
}

void Push(int x)
{
	if (Find(x))
		return;
	int t = abs(x)%MOD;
	Key[Index] = x;
	Next[Index] = head[t];
	head[t] = Index ++;
}

int main()
{
	int n;
	init();
	scanf("%d", &n);
	while (n --)
	{
		int m;
		char s[10];
		scanf("%s%d", &s, &m);
		while (m --)
		{
			int x;
			scanf("%d", &x);
			if (s[0] == 'A')
				Push(x);
			else if (Find(x))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
} 
/*
找球号(二）
时间限制：1000 ms  |  内存限制：65535 KB
难度：5
描述
在某一国度里流行着一种游戏。游戏规则为：现有一堆球中，每个球上都有一个整数编号i(0<=i<=100000000),编号可重复，还有一个空箱子，现在有两种动作：一种是"ADD"，表示向空箱子里放m(0<m<=100)个球，另一种是"QUERY”，表示说出M(0<M<=100)个随机整数ki(0<=ki<=100000100),分别判断编号为ki 的球是否在这个空箱子中（存在为"YES",否则为"NO"），先答出者为胜。现在有一个人想玩玩这个游戏，但他又很懒。他希望你能帮助他取得胜利。
输入
第一行有一个整数n(0<n<=10000);
随后有n行;
每行可能出现如下的任意一种形式：
第一种：
一个字符串"ADD"，接着是一个整数m，随后有m个i；
第二种：
一个字符串"QUERY”，接着是一个整数M，随后有M个ki；

输出
输出每次询问的结果"YES"或"NO".
样例输入
2
ADD 5 34 343 54 6 2
QUERY 4 34 54 33 66
样例输出
YES
YES
NO
NO
*/
