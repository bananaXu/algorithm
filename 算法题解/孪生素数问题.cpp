#include <iostream>
#include <vector>
using namespace std;

int a[1000005] = {0};

int main()
{
	int i, j, m, t, pre, num;
	pre = num = 0;
	for (i = 2; i <= 1000000; i ++)
	{
		if (!a[i])
		{
			if (pre+2 == i)
				a[i] = ++ num;
			else
				a[i] = a[pre];
			for (j = i+i; j <= 1000000; j += i)
				a[j] = 1;
			pre = i;
		}
		else
			a[i] = a[pre];
	}
	a[2] = 0;
	cin >> t;
	while (t --)
	{
		cin >> m;
		cout << a[m] << endl;
	}
	return 0;
}
/*
描述
写一个程序，找出给出素数范围内的所有孪生素数的组数。一般来说，孪生素数就是指两个素数距离为2，近的不能再近的相邻素数。有些童鞋一看到题就开始写程序，不仔细看题，咱们为了遏制一下读题不认真仔细的童鞋，规定，两个素数相邻为1的也成为孪生素数。
输入
第一行给出N(0<N<100)表示测试数据组数。
接下来组测试数据给出m，表示找出m之前的所有孪生素数。
(0<m<1000000)
输出
每组测试数据输出占一行，该行为m范围内所有孪生素数组数。
样例输入
1
14
样例输出
4
*/ 
