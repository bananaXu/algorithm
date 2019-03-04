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

int getsum(int x)
{
	int i;
	int sum = 0;
	for (i = 1; i <= x; i *= 10)
	{
		sum += x/i/10*i; // x/i/10*i*10�д�λ����1�ĸ��� 
		if (x/i%10 == 1)
			sum += x%i+1; // �����λΪ1����ô���ϴ�0��ʼ��x%i�ĸ��� 
		else if (x/i%10 > 1)
			sum += i;  // �����λ����1����ô����i�� 
	}
	return sum;
}

int main()
{
	int a, b;
	while (1)
	{
		scanf("%d%d", &a, &b);
		if (!a && !b)
			break;
		if (a > b)
			swap(a, b);
		printf("%d\n", getsum(b)-getsum(a-1));
	}
	return 0;
} 
/*
1�ĸ���
ʱ�����ƣ�1000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�3
����
����������a��b,��������Ǽ����1��a��b֮����ֵĴ���,����˵�����a=1024,b=1032����ôa��b֮��������ǣ�
1024 1025 1026 1027 1028 1029 1030 1031 1032
����10��1��������Щ���С�
����
���벻�ᳬ��500�С�ÿһ����������a��b��a��b�ķ�Χ��0 <= a, b <= 100000000����������0ʱ�������������0����Ϊ����������
���
����ÿһ�������a��b�����һ����������1���ֵĸ�����
��������
1 10
44 497
346 542
0 0
�������
2
185
40
*/
