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

typedef long long ll;

ll extgcd(ll a, ll b, ll &x, ll &y)
{
	if (b == 0)
	{
		x = 1; y = 0;
		return a;
	}
	ll c = extgcd(b, a%b, y, x);
	y -= a/b*x;
	return c;
}

int main()
{
	int n;
	scanf("%d", &n);
	while (n --)
	{
		ll x, y, a, b, l;
		scanf("%lld%lld%lld%lld%lld", &x, &y, &a, &b, &l);
		ll x1, y1;
		ll t = extgcd(a-b, l, x1, y1);
		if (abs(x-y)%t != 0)
		{
			printf("Impossible\n");
			continue;
		}
		x1 *= (y-x)/t;
		l = abs(l/t);
		x1 = (x1%l+l)%l;
		printf("%lld\n", x1);
	}
	return 0;
} 
/*
    С���С����������ʶ�ˣ������ĵúܿ��ģ����Ǿ��ú��б�Ҫ��һ�档����Լ���ں��߼��棬��������Ϊ����֤�˴��Ƿ���Ե�֣����������߶Է���λ�ã�ֻ��Լ������ĵ�ĳ����������ȴ������Է��Ƿ���֣����û�г��־�ȥ��һ�������µȴ������ܲ��������Է���

 ���ǳ���ǰ�����������ߵķ��򣬲���һֱ����һͬһ������Χ�ź��ߣ�ֻ������ͬʱ����ͬһ�����µ�ʱ�����ǲ��ܹ��ϳ��Է�(������ͣ����ʱ����Ժ���)��

�������Ƕ���ÿһ����ͣһ�£�С�����һ�����߹�a������С������һ�����߹�b����������ͬʱ��ĳһ��λ�ÿ�ʼ�ߣ�������λ�ÿ��Բ�ͬ�����������ܷ�������������������ʱ���Ƕ���

����
��һ����һ������ 0<n<100,������ÿ����5������x,y,a,b,l �ֱ��ʾС�濪ʼ�ߵ����ı��(��Ŵ�0��l-1)��С����ʼ�ߵ����ı�ţ�С��һ�����߹���������С��һ�����߹�����������������Ŀ����������x��y <= 2000000000��0 <a��b <= 2000000000��0 < L <= 2100000000��
���
һ�����n�У������Զ�������������������Impossible������������������Ҫ���ٷ��Ӳ���������
��������
1
1 2 3 4 5
�������
4
*/
