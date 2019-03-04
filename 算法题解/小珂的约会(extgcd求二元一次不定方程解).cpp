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
    小珂和小明在网上认识了，他们聊得很开心，于是觉得很有必要见一面。他们约定在湖边见面，但是他们为了验证彼此是否有缘分，决定不告诉对方的位置，只是约定随机的到某个柳树下面等待，看对方是否出现，如果没有出现就去下一个柳树下等待，看能不能遇到对方。

 他们出发前商量好了行走的方向，并且一直沿着一同一个方向围着湖走，只有他们同时到达同一棵树下的时候他们才能够认出对方(在树下停留的时间可以忽略)。

假设他们都是每一分钟停一下，小珂可以一分钟走过a棵树，小明可以一分钟走过b棵树。他们同时从某一个位置开始走（这两个位置可以不同），问他们能否相遇，如果能相遇最短时间是多少

输入
第一行有一个整数 0<n<100,接下来每行有5个整数x,y,a,b,l 分别表示小珂开始走的树的编号(编号从0到l-1)，小明开始走的树的编号，小珂一分钟走过几棵树，小明一分钟走过几棵树，树的总数目。其中其中x≠y <= 2000000000，0 <a、b <= 2000000000，0 < L <= 2100000000。
输出
一共输出n行，如果永远不可能相遇，就输出“Impossible”，否则就输出他们需要多少分钟才能相遇。
样例输入
1
1 2 3 4 5
样例输出
4
*/
