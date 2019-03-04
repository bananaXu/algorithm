#include <iostream>
#include <set>
#include <stack>
using namespace std;

int main()
{
	int i, a, v;
	int m, b;
	set <int> c;
	set <int>::iterator it;
	stack <int> d;
	c.insert(0);
	a = 1;
	for (i = 1; i <= 10; i ++)
	{
		a *= i;
		for (it = c.begin(); it != c.end(); it ++)
		{
			v = (*it)+a;
			if (v < 1000000)
				d.push(v);
		}
		while (!d.empty())
		{
			v = d.top();
			c.insert(v);
			d.pop();
		}
	}
	cin >> m;
	while (m --)
	{
		cin >> b;
		if (c.find(b) != c.end())
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
} 
/*
描述
给你一个非负数整数n，判断n是不是一些数（这些数不允许重复使用，且为正数）的阶
乘之和，如9=1！+2!+3!，如果是，则输出Yes，否则输出No；
输入
第一行有一个整数0<m<100,表示有m组测试数据；
每组测试数据有一个正整数n<1000000;
输出
如果符合条件，输出Yes，否则输出No;
*/