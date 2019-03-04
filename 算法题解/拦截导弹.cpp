#include <iostream>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

bool cmp(int a, int b)
{
	return a>b;
}

int main()
{
	int i, x, t, n, num, p;
	int a[25];
	cin >> t;
	while (t --)
	{
		cin >> n;
		num = 0;
		cin >> x;
		a[0] = x;
		for (i = 2; i <= n; i ++)
		{ 
			cin >> x;
			if (x < a[num])
				a[++ num] = x;
			else
			{
				p = lower_bound(a, a+num+1, x, cmp)-a;
				a[p] = x;
			}
		}
		cout << num+1 << endl;
	}
	return 0;
}
/*
2
8
389 207 155 389 299 170 158 65
3
88 34 65
*/
