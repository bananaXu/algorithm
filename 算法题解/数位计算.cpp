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

int a[21];

ll getsum(ll x, ll k)
{
	ll sum, t, y, pre;
	t = k; y = 1; sum = 0;
	while (y <= x)
	{
		pre =x%t/y;
		sum += x/t*y*a[k-1]+(x%y+1)*pre+a[pre-1]*y;
		t *= k;
		y *= k;
	}
	return sum;
}

int main()
{
	ll l, r, k, i;
	a[0] = 0;
	for (i = 1; i <= 20; i ++)
		a[i] = i+a[i-1];
	while (~scanf("%lld%lld%lld", &l, &r, &k))
		printf("%lld\n", getsum(r, k)-getsum(l-1, k));
	return 0;
}
/*
��λ����
ʱ�����ƣ�1000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�3
����
�ó������С�������ֺܸ���Ȥ�����ڼ��㷽��Ķ������С�����������������һ�����⣺
��������[L,R]���������ĸ���λ֮�ͣ�������϶��Ѳ����㣬��ô�����������������k
���Ʊ�ʾ�µĸ���λ֮���أ����ܰ�����
����
����������ݣ�������10000�飩.
ÿ������������L,R,k��0<=L<=R<10^15,k<=20).
���
���������.
��������
1 4 3
2 3 3
�������
6
3
*/
