#include <iostream>
#include <queue>
using namespace std;

int n, r;
int a[10];
int used[10] = {0};

void GetPermutation(int x)
{
	int i;
	if (x == r+1)
	{
		for (i = 1; i <= r; i ++)
			cout << a[i];
		cout << endl;
		return;
	}
	for (i = a[x-1]; i >= 1; i --)
	{
		if (!used[i])
		{
			a[x] = i;
			used[i] = 1;
			GetPermutation(x+1);
			used[i] = 0;
		}
	}
}

int main()
{
	cin >> n >> r;
	a[0] = n;
	GetPermutation(1);
	return 0;
} 
/*
描述
找出从自然数1、2、... 、n（0<n<10）中任取r(0<r<=n)个数的所有组合。
输入
输入n、r。
输出
按特定顺序输出所有组合。
特定顺序：每一个组合中的值从大到小排列，组合之间按逆字典序排列。
样例输入
5 3
样例输出
543
542
541
532
531
521
432
431
421
321
*/
