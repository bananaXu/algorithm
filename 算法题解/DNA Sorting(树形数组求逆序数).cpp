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

struct P
{
	int i;
	int v;
}a[105];

char s[105][55];
int n, m;
int t[5];

int lowbit(int x)
{
	return x&-x;
}

int add(int i)
{
	while (i <= 4)
	{
		t[i] ++;
		i += lowbit(i);
	}
}

int getsum(int i)
{
	int sum = 0;
	while (i)
	{
		sum += t[i];
		i -= lowbit(i);
	}
	return sum;
}

int getInt(char l)
{
	if (l == 'A')
		return 1;
	if (l == 'C')
		return 2;
	if (l == 'G')
		return 3;
	return 4;
}

int getnum(int x)
{
	int sum = 0;
	memset(t, 0, sizeof(t));
	for (int i = 0; i < strlen(s[x]); i ++)
	{
		int l = getInt(s[x][i]);
		add(l);
		sum += i+1-getsum(l);
	}
	a[x].i = x;
	a[x].v = sum;
}

bool cmp(P x, P y)
{
	if (x.v < y.v)
		return true;
	if (x.v > y.v)
		return false;
	return x.i < y.i; 
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i ++)
		scanf("%s", &s[i]);
	for (int i = 0; i < m; i ++)
		getnum(i);
	sort(a, a+m, cmp);
	for (int i = 0; i < m; i ++)
		printf("%s\n", s[a[i].i]);
	return 0;
}
