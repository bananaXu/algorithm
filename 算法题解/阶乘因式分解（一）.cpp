#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int t, m, n, sum;
	cin >> t;
	while (t --)
	{
		sum = 0;
		cin >> m >> n;
		while (m)
		{
			sum += m/n;
			m /= n;
		}
		cout << sum << endl;
	} 
	return 0;
}
/*
描述
给定两个数m,n,其中m是一个素数。

将n（0<=n<=10000）的阶乘分解质因数，求其中有多少个m。

输入
第一行是一个整数s（0<s<=100)，表示测试数据的组数
随后的s行, 每行有两个整数n，m。
输出
输出m的个数。
样例输入
2
100 5
16 2
样例输出
24
15
*/ 
