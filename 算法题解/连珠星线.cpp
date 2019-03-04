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

#define M 1005
#define INF 0x3f3f3f3f

int a[M][2];

int main()
{
	int t;
	scanf("%d", &t);
	while (t --)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++)
			scanf("%d%d", &a[i][0], &a[i][1]);
		int num = 0, sum = 0;
		for (int i = 1; i < n; i ++)
		{
			double d[M];
			for (int j = i+1; j <= n; j ++)
			{
				if (a[i][1] == a[j][1])
					d[j] = INF-1;
				else
					d[j] = 1.0*(a[i][0]-a[j][0])/(a[i][1]-a[j][1]);
			}
			sort(d+i+1, d+n+1);
			int num = 1;
			for (int j = i+2; j <= n; j ++)
			{
				if (abs(d[j]-d[j-1]) < 1e-8)
					num ++;
				else
				{
					if (num == 2)
						sum ++;
					num = 1;
				}
			}
			if (num == 2)
				sum ++;
		}
		printf("%d\n", sum);
	}
}
/*
��������
ʱ�����ƣ�1000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�5
����
zycСʱ����ʱ��ῴ��ҹ��������Ƿ�����������˼��һЩ��ѧ���⣨������ѧ���Ǻǣ���

���涨������������������ϵ�������ͬһ��ֱ���ϣ��������ֱ��Ϊ�������ߡ�

���ڣ������������һ����������ǹ����˶������������ߡ�

����
��һ������һ������T��ʾ�������ݵ�����(1<=T<=5)
ÿ��������ݵĵ�һ����һ������N(1<=N<=1000),��ʾ�������N�����ǡ�
����N��ÿ������������xi,yi(0<=xi,yi<=10000)����ʾһ�����ǵ����ꡣ���ݱ�֤�����������ǲ���ӵ����ȫ��ͬ������
���
����ÿ�����ݣ�����������ߵ�������ÿ��������ݵ������ռһ�С�
��������
2
3
1 2
1 3
1 4
5
0 1
1 2
2 3
2 4
4 8 
�������
1
2
*/
