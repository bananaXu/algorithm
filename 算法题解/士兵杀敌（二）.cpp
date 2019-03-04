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

int bit[MAX];
int n, m, x, y;
char c[10];

int lowbit(int x)
{
	return x&-x;
}

int sum(int i)
{
	int s = 0;
	while(i > 0)
	{
		s += bit[i];
		i -= lowbit(i);
	}
	return s;
}

void add(int i, int x)
{
	while(i <= n)
	{
		bit[i] += x;
		i += lowbit(i);
	}
}

void init()
{ 
	int i, j, t;
	for(i = n; i >= 1; i --) 
	{ 
		t = 0; 
		for(j = i-lowbit(i)+1; j <= i; j ++) 
		t += bit[j]; 
		bit[i] = t; 
	} 
} 

int main()
{
	int i, t;
	scanf("%d%d", &n, &m);
	for(i=1;i<=n;i++)
	{
		scanf("%d", &t);
		add(i, t);
	}
	while (m --)
	{
		scanf("%s%d%d", &c, &x, &y);
		if(c[0] == 'A') 
			add(x, y);
		else 
			printf("%d\n", sum(y)-sum(x-1));
	}
	return 0;
}
/*
����
�Ͻ���������N��ʿ�����ֱ���1��N����Щʿ����ɱ����������֪�ġ�

С�����Ͻ������µľ�ʦ���Ͻ���������֪����m�ŵ���n��ʿ������ɱ�������������С�����ش��Ͻ����ɡ�

�Ͻ�����ĳ��ѯ��֮��ʿ��i������ɱ��q�ˣ�֮���Ͻ�����ѯ�ʵ�ʱ����Ҫ���ǵ�������ɱ������

����
ֻ��һ���������
��һ������������N,M������N��ʾʿ���ĸ���(1<N<1000000)��M��ʾָ���������(1<M<100000)
����һ����N��������ai��ʾ��i��ʿ��ɱ����Ŀ��(0<=ai<=100)
����M��ÿ����һ��ָ�����ָ�������һ���ַ���������������������һ���ַ�����������ַ���QUERY���ʾ�Ͻ��������˲�ѯ�������������������m,n����ʾ��ѯ����ʼ����ֹʿ����ţ�������ַ���ADD����������������I,A(1<=I<=N,1<=A<=100),��ʾ��I��ʿ������ɱ����ΪA.
���
����ÿ�β�ѯ�����һ������R��ʾ��m��ʿ������n��ʿ������ɱ������ÿ�����ռһ��
��������
5 6
1 2 3 4 5
QUERY 1 3
ADD 1 2
QUERY 1 3
ADD 2 3
QUERY 1 2
QUERY 1 5
�������
6
8
8
20
*/ 
