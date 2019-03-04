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

typedef long long ll;
#define M 10005
#define MOD 10000

class hash
{
public:
	void init();
	bool Find(int x);
	void Push(int x);
	int GetSum(int x);
private:
	int Key[M], num[M], head[M], Next[M];
	int index;
};

void hash::init()
{
	index = 0;
	memset(Key, 0, sizeof(Key));
	memset(num, 0, sizeof(num));
	memset(head, -1, sizeof(head));
}

bool hash::Find(int x)
{
	int t = abs(x)%MOD;
	for (int i = head[t]; i != -1; i = Next[i])
	{
		if (Key[i] == x) 
		{
			num[i] ++;
			return true;
		}
	}
	return false;
}

void hash::Push(int x)
{
	if (Find(x))
		return;
	int t = abs(x)%MOD;
	Key[index] = x;
	Next[index] = head[t];
	num[index] ++;
	head[t] = index ++;
}

int hash::GetSum(int x)
{
	int t = abs(x)%MOD;
	int sum = 0;
	for (int i = head[t]; i != -1; i = Next[i])
	{
		if (x == Key[i])
			sum += num[i];
	}
	return sum;
}

int main()
{
	int a[105];
	for (int i = -50; i <= 50; i ++)
	{
		if (i < 0)
			a[i+50] = i*i*i;
		if (i > 0)
			a[i+49] = i*i*i;
	} 
	int t;
	scanf("%d", &t);
	while (t --)
	{
		int x1, x2, x3, x4, x5;
		scanf("%d%d%d%d%d", &x1, &x2, &x3, &x4, &x5);
		ll sum = 0;
		hash h;
		h.init();
		for (int i = 0; i < 100; i ++)
		{
			for (int j = 0; j < 100; j ++)
			{
				int t = x1*a[i]+x2*a[j];
				h.Push(t);
			}
		}
		for (int i = 0; i < 100; i ++)
		{
			for (int j = 0; j < 100; j ++)
			{
				for (int k = 0; k < 100; k ++)
				{
					int t = x3*a[i]+x4*a[j]+x5*a[k];
					sum += h.GetSum(-t);
				}
			}
		}
		printf("%lld\n", sum);
	}
	return 0;
}
/*
��ʽ
ʱ�����ƣ�1000 ms  |  �ڴ����ƣ�10000 KB
�Ѷȣ�5
����
�����µ�ʽ��a1*x13+a2*x23+a3*x33+a4*x43+a5*x53=0

x1,x2,x3,x4,x5����������[-50,50]֮�����������x1,x2,x3,x4,x5��������0.

�ʣ�����a1,a2,a3,a4,a5������£�x1,x2,x3,x4,x5���ж����ֿ��ܵ�ȡֵ��

����
��һ������һ������T(T<=10)��ʾ�������ݵ�������
ÿ��������ݶ�ֻ��һ�У���5������,�ֱ��ʾa1,a2,a3,a4,a5��(a1,a2,a3,a4,a5��������[-50,50]֮�䣩
���
����ÿ���������һ�У���ʾx1,x2,x3,x4,x5���ܵ�ȡֵ����
��������
1
37 29 41 43 47
�������
654
*/
