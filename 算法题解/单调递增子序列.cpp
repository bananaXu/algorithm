#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f
int a[100005];

int main()
{
	int n, i, x, p, len;
	while (~scanf("%d",&n))
	{
		a[0] = INF;
		len = 0;
		for (i = 1; i <= n; i ++)
		{
			cin >> x;
			if (x > a[len])
				a[++ len] = x;
			else
			{
				p = lower_bound(a, a+len+1, x)-a;
			 	a[p] = x;
			}
		}
		printf ("%d\n", len+1);
	}
	return 0;
}
