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

#define M 100005

struct P
{
	int x, y;
	bool operator <(const P &a)const {return y > a.y;}
}p[M];

struct S
{
	int v, i, x;
}s[M];

int Search(int x, int l, int r)
{
	if (l == r)
		return x >= p[l].x ? l : l+1;
	int mid = ((l+r)>>1);
	if (x < p[mid].x)
		return Search(x, mid+1, r);
	return Search(x, l, mid);
}

bool cmp1(const S &a, const S &b)
{
	return a.v < b.v;
}

bool cmp2(const S &a, const S &b)
{
	return a.i < b.i;
}

int main()
{
	int n, m;
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
		scanf("%d%d", &p[i].x, &p[i].y);
	sort(p+1, p+n+1);
	int Index = 1;
	for (int i = 2, t = p[1].x; i <= n; i ++)
	{
		if (p[i].x < t)
		{
			p[++ Index] = p[i];
			t = p[i].x;
		}
	}
	p[Index+1].x = p[Index+1].y = 0;
	for (int i = 1; i <= m; i ++)
	{
		scanf("%d", &s[i].v);
		s[i].i = i;
	}
	sort(s+1, s+m+1, cmp1);
	for (int i = 1, t = Index; i <= m; i ++)
	{
		t = Search(s[i].v, 1, t);
		s[i].x = p[t].y;
	}
	sort(s+1, s+m+1, cmp2);
	for (int i = 1; i <= m; i ++)
		printf("%d\n", s[i].x);
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
/*
为了找到自己满意的工作，牛牛收集了每种工作的难度和报酬。牛牛选工作的标准是在难度不超过自身能力值的情况下，牛牛选择报酬最高的工作。在牛牛选定了自己的工作后，牛牛的小伙伴们来找牛牛帮忙选工作，牛牛依然使用自己的标准来帮助小伙伴们。牛牛的小伙伴太多了，于是他只好把这个任务交给了你。 
输入描述:
每个输入包含一个测试用例。
每个测试用例的第一行包含两个正整数，分别表示工作的数量N(N<=100000)和小伙伴的数量M(M<=100000)。
接下来的N行每行包含两个正整数，分别表示该项工作的难度Di(Di<=1000000000)和报酬Pi(Pi<=1000000000)。
接下来的一行包含M个正整数，分别表示M个小伙伴的能力值Ai(Ai<=1000000000)。
保证不存在两项工作的报酬相同。


输出描述:
对于每个小伙伴，在单独的一行输出一个正整数表示他能得到的最高报酬。一个工作可以被多个人选择。

输入例子1:
3 3 
1 100 
10 1000 
1000000000 1001 
9 10 1000000000

输出例子1:
100 
1000 
1001为了找到自己满意的工作，牛牛收集了每种工作的难度和报酬。牛牛选工作的标准是在难度不超过自身能力值的情况下，牛牛选择报酬最高的工作。在牛牛选定了自己的工作后，牛牛的小伙伴们来找牛牛帮忙选工作，牛牛依然使用自己的标准来帮助小伙伴们。牛牛的小伙伴太多了，于是他只好把这个任务交给了你。 
输入描述:
每个输入包含一个测试用例。
每个测试用例的第一行包含两个正整数，分别表示工作的数量N(N<=100000)和小伙伴的数量M(M<=100000)。
接下来的N行每行包含两个正整数，分别表示该项工作的难度Di(Di<=1000000000)和报酬Pi(Pi<=1000000000)。
接下来的一行包含M个正整数，分别表示M个小伙伴的能力值Ai(Ai<=1000000000)。
保证不存在两项工作的报酬相同。


输出描述:
对于每个小伙伴，在单独的一行输出一个正整数表示他能得到的最高报酬。一个工作可以被多个人选择。

输入例子1:
3 3 
1 100 
10 1000 
1000000000 1001 
9 10 1000000000

输出例子1:
100 
1000 
1001
*/
