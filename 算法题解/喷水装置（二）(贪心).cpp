#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct Node
{
	double l;
	double r;
}node[10005];

bool cmp(Node a, Node b)
{
	return a.l < b.l;
}

// 应该从右向左使用贪心算法，这里写复杂了，简单，懒得改了 
int Find(int n, double w)
{
	int i, num;
	double x, Max;
	x = 0.0;
	num = 0;
	i = 1;
	while (1)
	{
		if (node[i].l > x) // 不能覆盖x位置 
			return 0;
		Max = 0.0;
		while(node[i].l <= x && i <= n) // 贪心找到能覆盖x并且能到达右边最远的点 
		{
			if (node[i].r == w)
				return num+1;
			if (i == n)
				return 0;
			if (node[i].r > Max)
				Max = node[i].r;
			i ++;
		}
		num ++;
		x = Max;
	}
}

int main()
{
	int i, n, t;
	double r, w, h, x, y;
	cin >> t;
	while (t --)
	{
		cin >> n >> w >> h;
		for (i = 1; i <= n; i ++)
		{
			cin >> x >> y;
			if (y < h/2.0) // 如果半径小于宽度一半，则是无用数据 
				node[i].l = node[i].r = 0;
			else
			{
				// 计算能覆盖的位置 
				r = sqrt(y*y-h*h/4.0);
				node[i].l = x-r >= 0 ? x-r : 0;
				node[i].r = x+r <= w ? x+r : w;
			}
		}
		// 以左边为基准排序  
		sort(node+1, node+n+1, cmp);
		cout << Find(n, w) << endl;
	}
	return 0;
}
/*
描述
有一块草坪，横向长w,纵向长为h,在它的橫向中心线上不同位置处装有n(n<=10000)个点状的喷水装置，每个喷水装置i喷水的效果是让以它为中心半径为Ri的圆都被润湿。请在给出的喷水装置中选择尽量少的喷水装置，把整个草坪全部润湿。
输入
第一行输入一个正整数N表示共有n次测试数据。
每一组测试数据的第一行有三个整数n,w,h，n表示共有n个喷水装置，w表示草坪的横向长度，h表示草坪的纵向长度。
随后的n行，都有两个整数xi和ri,xi表示第i个喷水装置的的横坐标（最左边为0），ri表示该喷水装置能覆盖的圆的半径。
输出
每组测试数据输出一个正整数，表示共需要多少个喷水装置，每个输出单独占一行。
如果不存在一种能够把整个草坪湿润的方案，请输出0。
样例输入
2
2 8 6
1 1
4 5
2 10 6
4 5
6 5
样例输出
1
2
*/
