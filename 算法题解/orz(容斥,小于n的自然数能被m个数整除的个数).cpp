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
#include <cfloat>
using namespace std;

typedef long long ll;

int Gcd(int a, int b)
{
	if (a < b)
		swap(a, b);
	while (b)
	{
		a = a%b;
		if (a < b)
			swap(a, b);
	}
	return a;
}

int BitCount(unsigned int n) // n��������1�ĸ��� 
{ 
    n = (n &0x55555555) + ((n >>1) &0x55555555) ; 
    n = (n &0x33333333) + ((n >>2) &0x33333333) ; 
    n = (n &0x0f0f0f0f) + ((n >>4) &0x0f0f0f0f) ; 
    return n%255; 
}

int main()
{
	int i, j;
	ll n, m, sum, t; 
	int a[15];
	int b[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
	while (~scanf("%lld%lld", &n, &m))
	{
		n --;
		for (i = 1; i <= m; i ++)
			scanf("%d", &a[i]);
		sum = 0;
		for (i = 1; i <= b[m]-1; i ++) // �ö����Ʊ�ʾʹ�õ����������ݳ⣬�����ӣ�ż���� 
		{
			t = 1;
			for (j = 0; j < m; j ++)
			{
				if (i&b[j])
					t *= a[j+1]/Gcd(t, a[j+1]); // t��ʾ�ܱ���Щ����������С������ 
			}
			if (BitCount(i)&1) // �������Ϊ���� 
				sum += n/t;
			else
				sum -= n/t;
		}
		printf("%lld\n", sum);
	}
	return 0;
}
/*
orz
ʱ�����ƣ�1000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�4
����
Now you get a number N, and a M-integers set, you should find out how many integers which are small than N,
that they can divided exactly by any integers in the set. For example, N=12, and M-integer set is {2,3}, so 
there is another set {2,3,4,6,8,9,10}, all the integers of the set can be divided exactly by 2 or 3. As a 
result, you just output the number 7
����
There are a lot of cases. For each case, the first line contains two integers N and M. 
The follow line contains the M integers, and all of them are different from each other. 
0<N<2^31,0<M<=10, and the M integer are non-negative and won��t exceed 20
���
For each case, output the number
��������
12 2
2 3
�������
7
*/
