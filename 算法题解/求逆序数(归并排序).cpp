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
#define mid ((l+r)>>1)

int a[MAX], b[MAX];
long long sum;

void merge(int l, int r)
{
	int i = l, j = mid+1, k = l;
	while (i <= mid && j <= r)
	{
		if (a[i] <= a[j])
			b[k ++] = a[i ++];
		else
		{
			sum += j-k;
			b[k ++] = a[j ++];
		}
	}
	while (i <= mid) b[k ++] = a[i ++];
	while (j <= r) b[k ++] = a[j ++];
	for (i = l; i <= r; i ++)
		a[i] = b[i];
}

void mergesort(int l, int r)
{
	if (l != r)
	{
		mergesort(l, mid);
		mergesort(mid+1, r);
		merge(l, r);
	} 
}

int main()
{
	int i, t, n;
	scanf("%d", &t);
	while(t --)
	{
		scanf("%d", &n);
		for (i = 1; i <= n; i ++)
			scanf("%d", &a[i]);
		sum = 0;
		mergesort(1, n);
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
