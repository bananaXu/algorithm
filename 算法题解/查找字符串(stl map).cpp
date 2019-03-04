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
#include <map>
#include <cfloat>
using namespace std;

void f(int n, int m)
{
	map <string, int> sim;
	char a[16];
	string s;
	int i;
	getchar();
	for (i = 1; i <= n; i ++)
	{
		gets(a);
		s = a;
		sim[a] ++;
	}
	while (m --)
	{
		gets(a);
		s = a;
		printf("%d\n", sim[s]);
	}
}

int main()
{
	
	int t, n, m;
	scanf("%d", &t);
	while (t --)
	{
		scanf ("%d%d", &n, &m);
		f(n, m);
	}
	return 0;
} 
/*
查找字符串
时间限制：1000 ms  |  内存限制：65535 KB
难度：3
描述
小明得到了一张写有奇怪字符串的纸，他想知道一些字符串出现了多少次，但这些字符串太多了，
他想找你帮忙，你能帮他吗？输入字符包括所有小写字母、‘@’、‘+’。

输入
第一行包含一个整数T（T<=100).表示测试数据组数。
接下来每组数据第一行包含两个整数n，m(n，m<100000),分别表示有n个字符串，小明要问你m次。
接下来n行，每行包含一个字符串，长度不大于15。
接下来m行，每行包含一个字符串，表示小明要问该串出现的次数。
输出
输出每组小明询问数串出现的次数。
样例输入
1
5 3
hello
it@is+so@easy
hello
ibelieveicanac
hello
hello
icannotacit
Giveup
样例输出
3
0
0
*/
