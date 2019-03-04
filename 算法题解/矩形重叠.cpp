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

#define M 55
#define MAX(a, b) a > b ? a : b

/*
������
�غϵĲ��ֶ�������һ����ԭ�����ε�ĳ��x�����ĳ��y�������
ö�����п��ܵĵ�
����Щ��Ϊ������һ����Ϊ1�������Σ����ж��ٸ����θ��Ǹ�������
������ľ�����Ŀ���� 
*/

int main()
{
	int n;
	scanf("%d", &n);
	set <int> x, y;
	set <int>::iterator itx, ity;
	int x1[M], x2[M], y1[M], y2[M];
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", &x1[i]); 
		x.insert(x1[i]);
	}
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", &y1[i]); 
		y.insert(y1[i]);
	}
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", &x2[i]); 
		x.insert(x2[i]);
	}
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", &y2[i]); 
		y.insert(y2[i]);
	}
	int Max = 0;
	for (itx = x.begin(); itx != x.end(); itx ++)
	{
		for (ity = y.begin(); ity != y.end(); ity ++)
		{
			int X = *itx, Y = *ity, num = 0;
			for (int i = 1; i <= n; i ++)
			{
				if (X >= x1[i] && X+1 <= x2[i] && Y >= y1[i] && Y+1 <= y2[i])
					num ++;
			}
			Max = MAX(Max, num);
		}
	} 
	printf("%d\n", Max);
	return 0;
}
/*
ƽ������n������, ��i�����ε����½�����Ϊ(x1[i], y1[i]), ���Ͻ�����Ϊ(x2[i], y2[i])��
����������߶�������й�����������Ϊ�������໥�ص���(�����Ǳ߽�ͽ���)��
��������ƽ�����ص������������ĵط�,�ж��ٸ������໥�ص���

��������:
����������С�
��һ�а���һ������n(2 <= n <= 50), ��ʾ���εĸ�����
�ڶ��а���n������x1[i](-10^9 <= x1[i] <= 10^9),��ʾ���½ǵĺ����ꡣ
�����а���n������y1[i](-10^9 <= y1[i] <= 10^9),��ʾ���½ǵ������ꡣ
�����а���n������x2[i](-10^9 <= x2[i] <= 10^9),��ʾ���Ͻǵĺ����ꡣ
�����а���n������y2[i](-10^9 <= y2[i] <= 10^9),��ʾ���Ͻǵ������ꡣ


�������:
���һ��������, ��ʾ���ĵط��ж��ٸ������໥�ص�,������ζ��������ص�,���1��

��������1:
2
0 90
0 90
100 200
100 200

�������1:
2
*/
