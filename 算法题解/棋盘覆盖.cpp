#include <iostream>
using namespace std;

int a[100];

int main()
{
	int i, j, t, n, len;
	cin >> t;
	while (t --)
	{
		cin >> n;
		len = 1;
		a[1] = 1;
		for (i = 1; i <= n-1; i ++)
		{
			for (j = 1; j <= len; j ++)
			{
				a[j] <<= 2;
			}
			for (j = 1; j <= len; j ++)
			{
				if (j == len && a[j] >= 10)
				{
					a[len+1] = a[len]/10;
					a[len] %= 10;
					len ++;
				}
				else
				{
					a[j+1] += a[j]/10;
					a[j] %= 10;
				}
			}
			a[1] += 1;
		}
		for (i = len; i >= 1; i --)
			cout << a[i];
		cout << endl;
	}
	return 0;
}
/*
描述
在一个2k×2k（1<=k<=100）的棋盘中恰有一方格被覆盖，如图1（k=2时），现用一缺角的2×2方格（图2为其中缺右下角的一个），去覆盖2k×2k未被覆盖过的方格，求需要类似图2方格总的个数s。如k=1时，s=1;k=2时，s=5

输入
第一行m表示有m组测试数据；
每一组测试数据的第一行有一个整数数k;
输出
输出所需个数s;
样例输入
3
1
2
3
样例输出
1
5
21
*/
