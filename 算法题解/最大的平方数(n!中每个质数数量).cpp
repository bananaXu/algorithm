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

// 5000000����һ������Ϊ�յ㣬����5000000������ֻ���ܳ���һ�� 
#define M 5000050
#define MOD 1000000007 
typedef long long ll;

ll v;
int a[M+5] = {0};
int b[348515]; // ͨ�����Եõ�5000000������������ 

int main()
{
	ll i, j, k, n, x, y, muli, num, pre_num;
	k = 0;
	int z = (int)sqrt(M); 
	for (i = 2; i <= M; i ++) // ��M���ڵ���������b���� 
	{
		if (a[i])
			continue;
		b[++ k] = i;
		if (i <= z)
		{
			for (j = i*i; j <= M; j += i)
			{
				a[j] = 1;
			}
		}
	}
	while (1)
	{   // ����������һ���ǵ��������� 
		// ����ͬ��������������ˣ��ٽ��п����� 
		scanf("%lld", &n);
		if (!n)
			break;
		pre_num = 0; // ��һ������������ 
		v = muli = 1;
		for (i = 1; b[i] <= n && i <= k; i ++)
		{
			x = n;
			y = b[i];
			num = 0; // ������������ 
			while(x)
			{
				num += x/y;
				x /= y;
			}
			if (num&1)
				num --;
			if (num == pre_num) // �������һ������������ͬ������� 
				muli = muli*b[i]%MOD;
			else // �������һ������������ͬ�������ϸ���������������pre_num�η� 
			{
				while (pre_num)
				{
					if (pre_num&1)
					{
						v = v*muli%MOD;
					}
					muli = muli*muli%MOD;
					pre_num >>= 1;
				}
				pre_num = num;
				muli = b[i];
			}
			if (!num)
		 		break;
		}
		printf("%d\n", v);
	}
	return 0;
} 
/*
����ƽ����
ʱ�����ƣ�3000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�5
����
����һ��n������1��n֮������ѡȡ���ɸ����֣�ÿ�����������ѡһ�Σ������ѡȡ��������ˣ�
Ҫ������˻�����Ϊһ��ƽ��������ô���������ķ��������ĳ˻�������1000000007ȡ�ࡣ
����
ÿ��һ������n��1<=n<=10000000)����һ��0������
���
����𰸣�ÿ�����ռһ�С�
��������
4
9348095
6297540
0
�������
4
177582252
644064736
*/
