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
typedef long long ll;

struct node
{
	node *l, *r;
	ll val;
};

node *head;
int a[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536};

void init()
{
	head = new node;
	head->l = NULL;
	head->r = NULL;
}

void New(node *&p, int val)
{
	p->l = NULL;
	p->r = NULL;
	p->val = val;
}

void insert(int x)
{
	node *p = head;
	for (int i = 16; i >= 0; i --)
	{
		if (a[i]&x)
		{
			if (p->r != NULL)
				p = p->r;
			else
			{
				node *q = new node;
				New(q, 0);
				p->r = q;
				p = q;
			}
		}
		else
		{
			if (p->l != NULL)
				p = p->l;
			else
			{
				node *q = new node;
				New(q, 0);
				p->l = q;
				p = q;
			}
		}
		p->val ++;
	}
}

void del(node *p)
{
	node *q = p;
	if (p->l != NULL)
		del(p->l);
	if (p->r != NULL)
		del(p->r);
	delete q;
}

ll search(int x, int m)
{
	ll sum = 0;
	node *p = head;
	for (int i = 16; i >= 0 && p != NULL; i --)
	{
		if (a[i]&m)
		{
			if (a[i]&x)
				p = p->l;
			else
				p = p->r;
		}
		else
		{
			if (a[i]&x)
			{
				if (p->l != NULL)
					sum += p->l->val; 
				p = p->r;
			}
			else
			{
				if (p->r != NULL)
					sum += p->r->val;
				p = p->l;
			}
		}
	}
	return sum;
}

int v[100005];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	init();
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", &v[i]);
		insert(v[i]);
	}
	ll sum = 0;
	for (int i = 1; i <= n; i ++)
		sum += search(v[i], m);
	printf("%lld\n", (sum>>1));
	del(head);
	return 0;
}
/*
题目描述
给定整数m以及n各数字A1,A2,..An，将数列A中所有元素两两异或，共能得到n(n-1)/2个结果，请求出这些结果中大于m的有多少个。
输入描述:
第一行包含两个整数n,m. 

第二行给出n个整数A1，A2，...，An。

数据范围

对于30%的数据，1 <= n, m <= 1000

对于100%的数据，1 <= n, m, Ai <= 10^5
输出描述:
输出仅包括一行，即所求的答案
示例1
输入

3 10  
6 5 10
输出

2
*/
