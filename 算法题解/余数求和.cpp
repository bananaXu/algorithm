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

typedef long long ll;
#define MIN(a, b) a < b ? a : b

int main()
{
	ll i, n, A1, An, k, l, r, t, sum;
	// ���Է�������ȵ�����£������ʵȲ����У�����Ϊ�� 
	// ö���̣���һ�����µĵȲ�������� 
	while (~scanf("%lld%lld", &n, &k))
	{
		sum = 0;
		t = (int)sqrt(k);
		if (n >= k)
		{
			sum += (n-k)*k;
			for (i = 1; i <= t; i ++) // �ȼ���n��Ϊ1~sqrt(n)�� 
			{	
				l = k/(i+1)+1;
				r = k/i; 
				A1 = k%l;
			 	An = k%r;
				sum += (A1+An)*(r-l+1)/2;
			} 
			for (i = r-1; i >= 1; i --) // ����δ�������Ϊsqrt(n)���ϵ� 
				sum += k%i;
		}
		else
		{
			for (i = 1; i <= t; i ++) // �ȼ���n��Ϊ1~sqrt(n)�� 
			{
				l = k/(i+1)+1;
				r = k/i;
				if (l <= n)
				{
					r = MIN(r, n);
					A1 = k%l;
				 	An = k%r;
					sum += (A1+An)*(r-l+1)/2;
				}
			} 
			for (i = MIN(r-1, n); i >= 1; i --) // ���n�ǳ�Сֱ�Ӵ�n��ʼ 
				sum += k%i; 
		} 
		printf("%lld\n", sum);
	}
	return 0;
}
/*
����������n��k�������sum(k%i)(iΪ1~n)��ֵ��
*/
