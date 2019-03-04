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

#define M 1000000

struct EDGE
{
	int next;
	int i; 
	int v;
	bool isleaf;
}edge[M];

int head[M];
int I, T;

void init()
{
	memset(head, -1, sizeof(head));
	I = T = 0;
}

bool insert(char s[])
{
	int len = strlen(s);
	int t = 0;
	for (int i = 0; i < len; i ++)
	{
		bool find = false;
		for (int j = head[t]; j != -1; j = edge[j].next)
		{
			if (edge[j].v == s[i]-'0')
			{
				find = true;
				t = edge[j].i;
				if (edge[j].isleaf)
					return true;
				break;
			}
		}
		if (!find)
		{
			for (int j = i; j < len; j ++)
			{
				edge[I].v = s[j]-'0';
				edge[I].next = head[t];
				edge[I].isleaf = false;
				edge[I].i = ++ T;
				head[t] = I ++;
				t = T;
			}
			edge[I-1].isleaf = true;
			return false;
		}
	}
	return true;
} 

int main()
{
	int t, n;
	scanf("%d", &t);
	while (t --)
	{
		scanf("%d", &n);
		char s[15];
		bool find = false;
		init();
		while (n --)
		{
			scanf("%s", &s);
			if (!find)
			{
				if (insert(s))
					find = true;
			}
		}
		if (find)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
} 
// 思路：静态建立字典树 
/*
描述
Given a list of phone numbers, determine if it is consistent in the sense that no number is the prefix of another. Let's say the phone catalogue listed these numbers:

Emergency 911
Alice 97 625 999
Bob 91 12 54 26
In this case, it's not possible to call Bob, because the central would direct your call to the emergency line as soon as you had dialled the first three digits of Bob's phone number. So this list would not be consistent.

输入
The first line of input gives a single integer, 1 ≤ t ≤ 10, the number of test cases. Each test case starts with n, the number of phone numbers, on a separate line, 1 ≤ n ≤ 100000. Then follows n lines with one unique phone number on each line. A phone number is a sequence of at most ten digits.
输出
For each test case, output "YES" if the list is consistent, or "NO" otherwise.
样例输入
2
3
911
97625999
91125426
5
113
12340
123440
12345
98346
样例输出
NO
YES
*/
