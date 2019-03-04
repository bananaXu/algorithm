#include <iostream>
#include <cstdio>
using namespace std;

void Qsort(int a[], int x, int y, int v)
{
	int i, j;
	i = x;
	j = y;
	while(i < j)
	{
		while(a[i] <= a[x] && i < y) i ++;
		while(a[j] >= a[x] && j > x) j --;
		swap(a[i], a[j]);
	}
	swap(a[i], a[j]);
	swap(a[x], a[j]);
	if (j == v)
		printf("%d\n", a[j]);
	else if (v < j)
		Qsort(a, x, j-1, v);
	else
		Qsort(a, j+1, y, v);
}

int main()
{
	int t, m, i;
	int a[1005];
	scanf("%d", &t);
	while (t --)
	{
		scanf("%d", &m);
		for (i = 1; i <= m; i ++)
			scanf("%d", &a[i]);
		Qsort(a, 1, m, (m>>1)+1);
	}
	return 0;
}
