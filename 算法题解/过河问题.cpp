#include <iostream>
#include <algorithm>
using namespace std;

#define min(a, b) a < b ? a : b

int main()
{
	int a[1005];
	int i, t, num, spend;
	cin >> t;
	while (t --)
	{
		cin >> num;
		for (i = 1; i <= num; i ++)
		{
			cin >> a[i];
		}
		sort(a+1, a+num+1);
		spend = 0;
		for (i = num; i > 3; i -= 2)
		{
			// 两种方案
			// 1.最快的和最慢的过河，最快的回来，最快的和第二慢的过河，最快的回来
			// 2.最快的和第二快的过河，最快的回来，最慢的和第二慢的过河，第二快的回来 
			spend += min(a[1]+(a[2]<<1)+a[i], (a[1]<<1)+a[i-1]+a[i]);
		}
		// 最后剩下三种情况，剩一个人或两个人直接过去，剩三个人，最快的送两次电筒 
		if (i == 1 || i == 2)
		{
			spend += a[i];
		}
		else
		{
			spend += a[1]+a[2]+a[3];
		}
		cout << spend << endl;
	}
	return 0;
}
/*
描述
在漆黑的夜里，N位旅行者来到了一座狭窄而且没有护栏的桥边。如果不借助手电筒的话，
大家是无论如何也不敢过桥去的。不幸的是，N个人一共只带了一只手电筒，而桥窄得只
够让两个人同时过。如果各自单独过桥的话，N人所需要的时间已知；而如果两人同时过桥，
所需要的时间就是走得比较慢的那个人单独行动时所需的时间。问题是，如何设计一个方案，
让这N人尽快过桥。 
输入
第一行是一个整数T(1<=T<=20)表示测试数据的组数
每组测试数据的第一行是一个整数N(1<=N<=1000)表示共有N个人要过河
每组测试数据的第二行是N个整数Si,表示此人过河所需要花时间。(0<Si<=100)
输出
输出所有人都过河需要用的最少时间
样例输入
1
4
1 2 5 10
样例输出
17
*/ 
