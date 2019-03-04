#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define MAX 1000005
#define Max(a, b) a > b ? a : b

struct NODE
{
	int i;
	int val;
}node[MAX];

int bit[MAX];
int j, n;
int imap[MAX];

int lowbit(int x)
{
	return x&(-x);
}

long long getsum(int i)
{
	long long s = 0;
	while(i > 0)
	{
		s += bit[i];
		i -= lowbit(i);
	}
	return s;
}

void add(int i, int x)
{
	while(i <= j)
	{
		bit[i] += x;
		i += lowbit(i);
	}
}

bool cmp(NODE a, NODE b)
{
	return a.val < b.val;
}

int main()
{
	int i, t, x;
	long long sum;
	scanf("%d", &t);
	while(t --)
	{
		scanf("%d", &n);
		for (i = 1; i <= n; i ++)
		{
			node[i].i = i;
			scanf("%d", &node[i].val);
		}
		sort(node+1, node+n+1, cmp);	
		j = 1;
		imap[node[1].i] = 1;
		for (i = 2; i <= n; i ++)
		{
			if (node[i].val != node[i-1].val)
				j ++;
			imap[node[i].i] = j;
		}
		memset(bit, 0, (j+1)*sizeof(int));
		sum = 0;
		for (i = 1; i <= n; i ++)
		{
			add(imap[i], 1);
			sum += i-getsum(imap[i]);
		}
		printf("%lld\n", sum);
	}
	return 0;
}
/*
����
��һ�������У����һ������ǰ��λ�����С˳���෴����ǰ��������ں����������ô���Ǿͳ�Ϊһ������һ������������������ͳ�Ϊ������е���������
���ڣ�����һ��N��Ԫ�ص����У������жϳ������������Ƕ��١�
���� 1 3 2 ������������1��
����
��һ������һ������T��ʾ�������ݵ�������1<=T<=5)
ÿ��������ݵ�ÿһ����һ������N��ʾ�����й���N��Ԫ�أ�2��=N��=1000000��
����һ�й���N������Ai(0<=Ai<1000000000)����ʾ�����е�����Ԫ�ء�
���ݱ�֤�ڶ�����������У�����10������Ĳ����������ֻ��һ�顣
���
��������е�������
��������
2
2
1 1
3
1 3 2
�������
0
1
*/
