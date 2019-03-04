#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

#define INF 0x3f3f3f3f
#define MAX(a, b) a > b ? a : b

int b[105];

int getmax(int n)
{
	int i, sum, max;
	max = -INF;
	sum = b[1];
	for (i = 2; i <= n; i ++)
	{
		if (sum > max)
			max = sum;
		if (sum < 0)
			sum = 0;
		sum += b[i];
	}
	if (sum > max)
		max = sum;
	return max;
}

// �����м�����������Ӷκ� 
int main()
{
	int t, m, n, i, j, k, max;
	int a[105][105];
	scanf("%d", &t);
	while (t --)
	{
		cin >> m >> n;
		for (i = 1; i <= m; i ++)
		{
			for (j = 1; j <= n; j ++)
			{
				cin >> a[i][j];
			}
		}
		max = -INF;
		for (i = 1; i <= m; i ++)
		{
			memset(b, 0, sizeof(b));
			for (j = i; j <= m; j ++)
			{
				for (k = 1; k <= n; k ++)
				{
					b[k] += a[j][k];
				}
				max = MAX(max, getmax(n));
			}
		}
		printf("%d\n", max);
	}
	return 0;
}
/*
����
����һ����������ɶ�ά����r*c����������Ҫ�ҳ�����һ���Ӿ���ʹ������Ӿ����ڵ�����Ԫ��֮����󣬲�������Ӿ����Ϊ����Ӿ��� 
���ӣ�
0 -2 -7 0 
9 2 -6 2 
-4 1 -4 1 
-1 8 0 -2 
������Ӿ���Ϊ��

9 2 
-4 1 
-1 8 
��Ԫ���ܺ�Ϊ15�� 

����
��һ������һ������n��0<n<=100��,��ʾ��n��������ݣ�
ÿ��������ݣ�
��һ��������������r��c��0<r,c<=100����r��c�ֱ���������к��У�
�����r�У�ÿ����c��������
���
������������Ӿ����Ԫ��֮�͡�
��������
1
4 4
0 -2 -7 0 
9 2 -6 2 
-4 1 -4 1 
-1 8 0 -2 
�������
15
*/
