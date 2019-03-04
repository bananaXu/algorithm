#include <iostream>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Point
{
	int x;
	int y;
}p[105], sta[105];

// 向量叉乘 
int muliti(Point p1, Point p2, Point p0)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

// 每个点以p[0]为基准逆时针排序 
bool cmp(Point a, Point b)
{
	if (muliti(a, b, p[0]) > 0)
		return 1;
	if (muliti(a, b, p[0]) == 0 && abs(a.x-p[0].x) < abs(a.x-p[0].x))
		return 1;
	return 0;
}
 
bool cmp1(Point a, Point b)
{
	if (a.x < b.x)
		return true;
	if (a.x == b.x && a.y < b.y)
		return true;
	return false;
}

int main()
{
	int t, i, n, k, top;
	cin >> t;
	while (t --)
	{
		cin >> n;
		for (i = 0; i < n; i ++)
			cin >> p[i].x >> p[i].y;
		k = 0;
		// 选择y坐标最小中的最左边的点为p[0] 
		for (i = 1; i < n; i ++)
			if (p[i].y < p[k].y || (p[i].y == p[k].y && p[i].x < p[k].x))
				k = i;
		swap(p[0], p[k]);
		sort(p+1, p+n, cmp);
		sta[0] = p[0];
		sta[1] = p[1];
		sta[2] = p[2];
		top = 2;
		for (i = 3; i < n; i ++)
		{
			// 点向右拐，则上个点出栈 
			while(top > 1 && muliti(p[i], sta[top], sta[top-1]) >= 0)
			 	top--;
			sta[++ top] = p[i];
		}
		sort (sta, sta+top+1, cmp1);
		for (i = 0; i <= top; i ++)
			cout << sta[i].x << " " << sta[i].y << endl;
	}
	return 0;
}
/*
圈水池
时间限制：3000 ms  |  内存限制：65535 KB
难度：4
描述
有一个牧场，牧场上有很多个供水装置，现在牧场的主人想要用篱笆把这些供水装置圈起来，以防止不是自己的牲畜来喝水，各个水池都标有各自的坐标，现在要你写一个程序利用最短的篱笆将这些供水装置圈起来！（篱笆足够多，并且长度可变）
输入
第一行输入的是N,代表用N组测试数据（1<=N<=10）
第二行输入的是m,代表本组测试数据共有m个供水装置（3<=m<=100）
接下来m行代表的是各个供水装置的横纵坐标
输出
输出各个篱笆经过各个供水装置的坐标点，并且按照x轴坐标值从小到大输出，如果x轴坐标值相同，再安照y轴坐标值从小到大输出
样例输入
1
4
0 0
1 1
2 3
3 0
样例输出
0 0
2 3
3 0
*/
