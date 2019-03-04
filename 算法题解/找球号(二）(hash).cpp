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
�����(����
ʱ�����ƣ�1000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�5
����
��ĳһ������������һ����Ϸ����Ϸ����Ϊ������һ�����У�ÿ�����϶���һ���������i(0<=i<=100000000),��ſ��ظ�������һ�������ӣ����������ֶ�����һ����"ADD"����ʾ����������m(0<m<=100)������һ����"QUERY������ʾ˵��M(0<M<=100)���������ki(0<=ki<=100000100),�ֱ��жϱ��Ϊki �����Ƿ�������������У�����Ϊ"YES",����Ϊ"NO"�����ȴ����Ϊʤ��������һ���������������Ϸ�������ֺ�������ϣ�����ܰ�����ȡ��ʤ����
����
��һ����һ������n(0<n<=10000);
�����n��;
ÿ�п��ܳ������µ�����һ����ʽ��
��һ�֣�
һ���ַ���"ADD"��������һ������m�������m��i��
�ڶ��֣�
һ���ַ���"QUERY����������һ������M�������M��ki��

���
���ÿ��ѯ�ʵĽ��"YES"��"NO".
��������
2
ADD 5 34 343 54 6 2
QUERY 4 34 54 33 66
�������
YES
YES
NO
NO
*/
