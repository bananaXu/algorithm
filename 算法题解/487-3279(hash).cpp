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
#define MOD 100000

class hash
{
public:
	void init();
	bool find(int x);
	void put(int x);
	void output();
private:
	int num[M], head[M], key[M], next[M], a[M];
	int index, index1;
};

void hash::init()
{
	memset(head, -1, sizeof(head));
	memset(num, 0, sizeof(num));
	index = 0;
	index1 = 0;
}

bool hash::find(int x)
{
	int t = x%MOD;
	for (int i = head[t]; i != -1; i = next[i])
	{
		if (key[i] == x)
		{
			if (num[i] == 1)
				a[index1 ++] = x;
			num[i] ++;
			return true;
		}
	}
	return false;
}

void hash::put(int x)
{
	if (find(x))
		return;
	int t = x%MOD;
	key[index] = x;
	num[index] = 1;
	next[index] = head[t];
	head[t] = index ++;
}

void hash::output()
{
	sort(a, a+index1);
	for (int i = 0; i < index1; i ++)
	{
		int t = a[i]%MOD;
		for (int j = head[t]; j != -1; j = next[j])
		{
			if (key[j] == a[i])
			{
				printf("%.3d-%.4d %d\n", a[i]/10000, a[i]%10000, num[j]);
				break;
			}
		}
	}
}

int getint(char s)
{
	int t;
	if (s < 'Q')
		t = s-'A';
	else
		t = s-'A'-1;
	return t/3+2;
}

int getInt(char s[])
{
	int sum = 0;
	for (int i = 0; i < strlen(s); i ++)
	{
		if (s[i] == '-')
			continue;
		int t;
		if (isalpha(s[i]))
			t = getint(s[i]);
		else
			t = s[i]-'0';
		sum = sum*10+t;
	}
	return sum;
}

int main()
{
	int n;
	scanf("%d", &n);
	hash h;
	h.init();
	while (n --)
	{
		char s[50];
		scanf("%s", &s);
		h.put(getInt(s));
	}
	h.output();
	return 0;
}
/*
487-3279
题意：
A, B, and C map to 2 
D, E, and F map to 3 
G, H, and I map to 4 
J, K, and L map to 5 
M, N, and O map to 6 
P, R, and S map to 7 
T, U, and V map to 8 
W, X, and Y map to 9 
给n串字符串，将其转换为电话号码，将数量大于二的电话号码按字典序输出
样例输入
12
4873279
ITS-EASY
888-4567
3-10-10-10
888-GLOP
TUT-GLOP
967-11-11
310-GINO
F101010
888-1200
-4-8-7-3-2-7-9-
487-3279
样例输出
310-1010 2
487-3279 4
888-4567 3 
*/
