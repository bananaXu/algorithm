#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int i, j, m, len;
	int a[20000] = {0};
	a[1] = 1;
	len = 1;
	cin >> m;
	for (i = 2; i <= m; i ++)
	{
		for (j = 1; j <= len; j ++)
			a[j] *= i;
		for (j = 1; j <= len; j ++)
		{
			if (j == len && a[j] >= 10)
				len ++;
			a[j+1] += a[j]/10;
			a[j] %= 10;
		}
	}
	for (i = len; i >= 1; i --)
		cout << a[i];
	cout << endl;
	return 0;
} 
