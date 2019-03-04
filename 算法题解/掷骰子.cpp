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

int main()
{	// ��1~10�����ӿ����������������� 
	int a[11][65] = {0};
	int i, j, k;
	for (i = 1; i <= 6; i ++)
		a[1][i] = 1;
	for (i = 2; i <= 10; i ++)
	{
		for (j = 1; j <= 6; j ++)
		{
			for (k = i-1; k <= 6*(i-1); k ++)
			{
				a[i][j+k] += a[i-1][k];
			}
		}
	}
	int t, m, n;
	double sum;
	int b[60];
	scanf("%d", &t);
	while (t --)
	{
		scanf("%d%d", &m, &n);
		if (n == 1 && m > 6)
		{
			printf("1.000000\n");
			continue;
		}
		if (m == 1 && n > 6)
		{
			printf("0.000000\n");
			continue;
		}	
		memset(b, 0, sizeof(b));
		sum = 0.0;
		b[n] = a[n][n];
		for (i = n+1; i <= 6*n; i ++)
			b[i] = b[i-1]+a[n][i];
		for (i = m; i <= 6*m; i ++)
		{
			if (i <= n)
				continue;
			if (b[i-1] && a[m][i])
				sum += (1.0*a[m][i]/pow(6.0, m))*(1.0*b[i-1]/pow(6.0, n));
			else if(a[m][i])
				sum += 1.0*a[m][i]/pow(6.0, m);
		}
		printf("%.6f\n", sum);
	}
	return 0;
}
/*
������
ʱ�����ƣ�3000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�4
����
С����m�����ӣ�С����n�����ӡ�ÿһ�����Ӷ��Ǳ�׼�������ӡ����Ƿֱ������Լ������ӣ����С���ĵ����ʹ���С��ʤ������С��ʤ����С��ʤ���ĸ��ʡ�
����
��T�����ݡ�ÿ������һ�У�m��n���ÿո������1 <= m, n <= 10
���
����ÿһ�����ݣ����С����ʤ�ĸ��ʡ�ÿ�����ռһ�У����������뷨����ȷ��С�������6λ��
��������
1
1 1 
�������
0.416667
*/
