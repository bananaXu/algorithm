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

int a[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

void getm(int n)
{
	int i, j, t ,len;
	int b[50] = {0};
	b[0] = 1;
	len = 0;
	for (i = 0; a[i] <= n; i ++)
	{
		t = (int)(log(n+0.0001)/log(a[i]));
		t = (int)pow(1.0*a[i], t);
		for (j = 0; j <= len; j ++)
		{
			b[j] *= t;
		}
		for (j = 0; j <= len; j ++)
		{
			if (b[j] > 9)
			{
				b[j+1] += b[j]/10;
				b[j] %= 10; 
				if (j == len)
					len ++;
			}
		}
	}
	for (i = len; i >= 0; i --)
		printf("%d", b[i]);
	printf("\n");
}

int main()
{
	int n;
	while(~scanf("%d", &n))
	{
		getm(n);
	}
	return 0;
}
/*
��С������
ʱ�����ƣ�1000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�3
����
Ϊʲô1Сʱ��60���ӣ�������100�����أ�������ʷ�ϵ�ϰ�ߵ��¡�
��Ҳ���Ǵ����żȻ��60�Ǹ���������֣��������ӱȽ϶ࡣ
��ʵ�ϣ�����1��6��ÿ�����ֵı�������1,2,3,4,5,6���ǿ��Գ���60��

����ϣ��Ѱ�ҵ��ܳ���1��n�ĵ�ÿ�����ֵ���С����m.
����
����������ݣ�����500�飩��
ÿ��ֻ��һ����n(1<=n<=100).
���
�����Ӧ��m��
��������
2
3
4
�������
2
6
12
*/
