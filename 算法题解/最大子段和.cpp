#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define INF 0x3f3f3f3f
int a[1000005];

int GetMaxS(int n)
{
	int i, Max, sum;
	Max = -INF;
	sum = 0;
	for (i = 1; i <= n; i ++)
	{
		sum += a[i]; 
		if (sum > Max)
			Max = sum;
		if (sum < 0)
			sum = 0; 
	}
	return Max;
}

int main()
{
	int i, n, t;
	cin >> t;
	while (t --)
	{
		cin >> n;
		for (i = 1; i <= n; i ++)
			scanf("%d", &a[i]);
		cout << GetMaxS(n) << endl;
	}
} 
