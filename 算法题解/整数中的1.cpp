#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <cmath>
#include <vector> 
#include <ctype.h>
using namespace std;

int s[30];

int getsum(int x)
{
	int i, sum, t;
	sum = 0; i = -1;
	if (!x)
		return 0;
	t = ++ x;
	while ((s[++ i]>>1) <= x)
	{
		if (s[i]&x)
		{
			sum += x&(s[i]-1);
			t &= t-1;
		}
		sum += t>>1;
	}
	return sum;
}

int main()
{
	int i, a, b;
	scanf("%d%d" ,&a, &b);
	s[0] = 1;
	for (i = 1; i <= 29; i ++)
	{
		s[i] = s[i-1]<<1;
	}
	printf("%d\n", getsum(b)-getsum(a-1));
	return 0;
} 
/*
�����е�1
ʱ�����ƣ�3000 ms  |  �ڴ����ƣ�10000 KB
�Ѷȣ�4
����
���������Ǹ�32λ���ͷ�Χ�ڵ���a,b�������������[a,b]���������������и���λ��1���ܸ�����
����
һ�У���������������a,b(0<=a<=b<=150000000)���ո�ָ���
���
һ�У�������
��������
1 2
�������
2
*/
