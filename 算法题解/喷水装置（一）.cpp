#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int i, n, t;
	double sum;
	double a[605];
	cin >> t;
	while (t --)
	{
		cin >> n;
		sum = 20.0;
		for (i = 1; i <= n; i ++)
		{
			cin >> a[i];
			a[i] = 2*sqrt(pow(a[i], 2)-1);
		}
		sort(a+1, a+n+1);
		for (i = n; i >= 1; i --)
		{
			sum -= a[i];
			if (sum <= 0)
				break;
		}
		cout << n-i+1 << endl;
	}
	return 0;
}
/*
描述
现有一块草坪，长为20米，宽为2米，要在横中心线上放置半径为Ri的喷水装置，每个喷水装置的效果都会让以它为中心的半径为实数Ri(0<Ri<15)的圆被湿润，这有充足的喷水装置i（1<i<600)个，并且一定能把草坪全部湿润，你要做的是：选择尽量少的喷水装置，把整个草坪的全部湿润。
输入
第一行m表示有m组测试数据
每一组测试数据的第一行有一个整数数n，n表示共有n个喷水装置，随后的一行，有n个实数ri，ri表示该喷水装置能覆盖的圆的半径。
输出
输出所用装置的个数
样例输入
2
5
2 3.2 4 4.5 6 
10
1 2 3 1 2 1.2 3 1.1 1 2
样例输出
2
5
*/
