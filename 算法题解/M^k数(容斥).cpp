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

#define EPS 1e-8
typedef long long ll;

int a[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
// 2^60����10^18
// n^(1/p)Ϊ1~n��p�η��ĸ���
// �����ݳⶨ��������������η������ĺͣ���ȥ������˴η��ģ��ټ���������˴η���.... 
// �����ĸ�������˱ش���60�����������ֻ��2*3*5��2*3*7С��60
// ����ֻ���󵥸�������������˺�2*3*5��2*3*7 
int main()
{
	ll i, j, k, n, sum, t;
	while(~scanf("%lld", &n))
	{
		sum = 1;
		for (i = 0; i <= 16; i ++)
		{
			t = (ll)(pow(double(n), 1.0/a[i])+EPS);
			if (t == 1)
				break;
			sum += t-1;
		} 
		for (i = 0; i <= 9; i ++)
		{
			for (j = i+1; j <= 10; j ++)
			{
				if (a[i]*a[j] < 60)
				{
					t = (ll)(pow(double(n), 1.0/(a[i]*a[j]))+EPS);
					if (t == 1)
						break;
					sum -= t-1;
				}
			}
		}
		t = (ll)(pow(double(n), 1.0/(30))+EPS);
		sum += t-1;
		t = (ll)(pow(double(n), 1.0/(42))+EPS);
		sum += t-1;
		printf("%lld\n", sum);
	}
	return 0;
} 
/*
M^k��
ʱ�����ƣ�1000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�4
����
����һ����n�������1��n֮���ж��ٸ������ܱ�ʾΪM^k(k>1��m��k����������)��ʽ�ĸ�����
����
ÿ��һ������n��1<=n<=10^18)��
���
���1��n�������������ĸ�����
��������
4
36
1000000000000000000
�������
2
9
1001003332
*/

