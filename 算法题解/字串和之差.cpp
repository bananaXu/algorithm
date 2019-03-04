#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <cmath>
#include <vector> 
#include <queue>
#include <ctype.h>
using namespace std;

#define INF 0x3f3f3f3f
#define MIN(a, b) a < b ? a : b
#define MAX(a, b) a > b ? a : b

int a[1000005];

int main()
{
	int t, i, n, x, min, max;
	scanf("%d", &t);
	while (t --)
	{
		scanf("%d", &n);
		a[0] = 0;
		min = INF;
		for (i = 1; i <= n; i ++)
		{
			scanf("%d", &x);
			a[i] = x+a[i-1]; // a[i]����ǰn��� 
			min = MIN(min, abs(x)); // �ҵ�����������С�� 
			min = MIN(min, abs(a[i])); // ��ǰn����С�� 
		}
		sort(a+1, a+n+1); // a[i]-a[j]Ϊsum[j+1..i] 
		if (min)
		{
			for (i = 2; i <= n; i ++)
				min = MIN(min, a[i]-a[i-1]); // ��i��j�����С�� 
		}
		if ((a[1]^a[n]) < 0) // a[1]��a[n]��� 
			max = abs(a[n]-a[1]);
		else // a[1]��a[n]ͬ��
			max = MAX(abs(a[1]), abs(a[n]));
		printf("%d\n", max-min);
	}
	return 0;
}
/*
�ִ���֮��
ʱ�����ƣ�3000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�4
����
����һ������{a1,a2,a3,a4����an},ѡ��һ�������ǿ������У�ʹ�����еľ���ֵmax�����ѡ��һ���ǿ������У����һ�����е�ѡ���޹أ���ʹ�����еľ���ֵmin��С�����max��min�Ĳ�ֵ��
����
��һ����һ������m��m<15)��ʾ�������ݵ�������
ÿ�����ݵ�һ����һ������ n��n<1000000),��ʾ�������Ԫ�صĸ�����������һ����n������x(-100<x<100)��
���
���max��min�Ĳ�ֵ��max-min).ÿ���������ռһ�С�
��������
2
4
-1 1 3 2
5
2 3 -2 4 1
�������
6
7
*/
