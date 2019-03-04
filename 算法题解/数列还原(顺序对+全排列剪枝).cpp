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

#define M 105
#define N 12 

/*
�㷨˼�룺
������״������ԭ����˳���
Ȼ�����ÿ��ģ��������ÿ���������ӵ�˳��� 
����dfs�Ӽ�֦�����������Ƿ����㣬����k�ͼ�֦ 
*/

struct NotIn
{
	int v;
	int num[N];
}notin[N];

int n, k, SUM;
int a[M], b[M], ex[M], notid[N];

int lowbit(int x)
{
	return x&-x;
}

void add(int x, int v)
{
	while (x <= n)
	{
		a[x] += v;
		x += lowbit(x);
	}
}

int getsum(int x)
{
	int sum = 0;
	while (x)
	{
		sum += a[x];
		x -= lowbit(x);
	}
	return sum;
}

int getnum(int x, int y)
{
 	int sum = 0;
	for (int i = 1; i < notid[y]; i ++)
	{
		if (b[i] && notin[x].v > b[i])
			sum ++;
	}
	for (int i = notid[y]+1; i <= n; i ++)
	{
		if (b[i] && b[i] > notin[x].v)
			sum ++;
	}
	return sum;
}

void dfs(int t, int T, int sum, int Max)
{
	if(t == T+1)
	{
		if (sum == Max)
			SUM ++;
		return;
	}
	if (sum > Max)
		return;
	for (int i = t; i <= T; i ++)
	{
		swap(notin[i], notin[t]);
		int x = 0;
		for (int j = 1; j < t; j ++)
		{
			if (notin[t].v > notin[j].v)
				x ++;
		}
		dfs(t+1, T, sum+notin[t].num[t]+x, Max);
		swap(notin[i], notin[t]);
	}
} 

int main()
{
	while (cin >> n >> k)
	{
		int sum = 0;
		int I = 0;
		for (int i = 1; i <= n; i ++)
		{
			cin >> b[i];
			ex[b[i]] = 1;
			if (b[i])
			{
				add(b[i], 1);
				sum += getsum(b[i]-1);
			}
			else
	 			notid[++ I] = i;
		}
		I = 0;
		for (int i = 1; i <= n; i ++)
		{
			if (!ex[i])
				notin[++ I].v = i;
		}
		for (int i = 1; i <= I; i ++)
		{
			for (int j = 1; j <= I; j ++)
				notin[i].num[j] = getnum(i, j);
		}
		SUM = 0;
		dfs(1, I, 0, k-sum);
		cout << SUM << endl;
	}
	return 0;
}
/*
��Ŀ����
ţţ����ҵ������һ������Ϊ n ������ A��������а����˴�1��n��n������������ΪһЩԭ��������һЩλ�ã������� 10 �����������ˣ�����ţţ�ǵ��������˳��Ե������� k��˳�����ָ���� i < j �� A[i] < A[j] �Ķ����������ţţ��������������Ҫ��ĺϷ����е���Ŀ��
��������:
ÿ���������һ������������ÿ�����������ĵ�һ�а����������� n �� k��1 <= n <= 100, 0 <= k <= 1000000000������������ 1 �У����� n �����ֱ�ʾ���� A�����е���0�����ʾ�������λ�ã������� 10 ������
�������:
���һ�б�ʾ�Ϸ���������Ŀ��
ʾ��1
����
5 5
4 0 0 2 0
���
2
*/ 
