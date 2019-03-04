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

int a[105][60];

void calc(int i, int muli, int div)
{
	int len = a[i-1][0];
	int mod = 0;
	for (int j = len; j > 0 ; j --)
	{
		a[i][j] = mod*10+a[i-1][j]*muli;
		mod = a[i][j]%div;
		a[i][j] /= div;
	}
	for (int j = 1; j <= len; j ++)
	{
		if (j == len && a[i][j] > 9)
			len ++;
		a[i][j+1] += a[i][j]/10;
		a[i][j] %= 10;
	}
	a[i][0] = len;
}

int main()
{
	memset(a, 0 , sizeof(a));
	a[1][0] = a[1][1] = 1;
	for (int i = 2; i <= 100; i ++)
	{
		calc(i, (i<<2)-2, i+1);
	}
	while (1)
	{
		int n;
		scanf("%d", &n);
		if (n == -1)
			break;
		for (int i = a[n][0]; i >= 1; i --)
			printf("%d", a[n][i]);
		printf("\n");
	}
	return 0;
} 
