#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX(a, b) a > b ? a : b

struct REC
{
	int w;
	int h;
}rec[1005];

bool cmp(REC a, REC b)
{
	if (a.w < b.w)
		return true;
	if (a.w == b.w)
		return a.h < b.h;
	return false;
}

int main()
{
	int t, i, j, n, x, y, max;
	int dp[1005];
	cin >> t;
	while (t --)
	{
		cin >> n;
		for (i = 1; i <= n; i ++)
		{
			cin >> x >> y;
			if (x > y) // ������ת���ɸ߱ȿ���������� 
			{
				swap(x, y);
			}
			rec[i].w = x;
			rec[i].h= y;
		}
		sort(rec+1, rec+n+1, cmp); // �����ΰ�������
		memset(dp, 0, sizeof(dp));
		max = 0;
		for (i = 1; i <= n; i ++)
		{	// �������ͬ��ֹͣ 
			for (j = 1; j < i && rec[i].w != rec[j].w; j ++)
			{
				if (rec[i].h > rec[j].h)
				{
					dp[i] = MAX(dp[i], dp[j]+1);
				}
			}
			max = MAX(max, dp[i]);
		}
		cout << max+1 << endl;
	} 
	return 0;
}
/*
����
��n�����Σ�ÿ�����ο�����a,b����������ʾ���Ϳ�����X(a,b)����Ƕ���ھ���Y(c,d)�е��ҽ���a<c,b<d����b<c,a<d���൱����תX90�ȣ������磨1,5������Ƕ���ڣ�6,2���ڣ�������Ƕ���ڣ�3,4���С����������ѡ�������ܶ�ľ����ų�һ�У�ʹ�ó����һ���⣬ÿһ�����ζ�����Ƕ������һ�������ڡ�
����
��һ����һ��������N(0<N<10)����ʾ��������������
ÿ��������ݵĵ�һ����һ��������n����ʾ������������к��о��εĸ���(n<=1000)
����n�У�ÿ����������a,b(0<a,b<100)����ʾ���εĳ��Ϳ�
���
ÿ��������ݶ����һ��������ʾ�����������ľ�����Ŀ��ÿ�����ռһ��
��������
1
10
1 2
2 4
5 8
6 10
7 9
3 1
5 8
12 10
9 7
2 2
�������
5
*/ 
