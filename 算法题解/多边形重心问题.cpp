#include <iostream>
#include <cstdio>
#include <cmath>
#include <stack>
using namespace std;

struct Node
{
	double x;
	double y;
}a[1005];

int n;
double s, cp;

void area()
{
	int i;
	double tem;
	s = (a[n].x*a[1].y-a[1].x*a[n].y);
	cp = (a[1].x+a[n].x+a[1].y+a[n].y)*s;
	for (i = 2; i <= n; i ++)
	{
		tem = (a[i-1].x*a[i].y-a[i-1].y*a[i].x);
		s += tem;
		cp += tem*(a[i-1].x+a[i].x+a[i-1].y+a[i].y);
	}
	s = abs(s);
	cp = abs(cp);
	s /= 2;
	if (s != 0)
		cp /= 6*s;
}

int main()
{
	int i, t;
	cin >> t;
	while (t --)
	{
		cin >> n;
		for (i = 1; i <= n; i ++)
		{
			cin >> a[i].x >> a[i].y;
		}
		area();
		printf("%.3f %.3f\n", s, cp);
	}
	return 0;
}
/*
描述
在某个多边形上，取n个点，这n个点顺序给出，按照给出顺序将相邻的点用直线连接， （第一个和最后一个连接），所有线段不和其他线段相交，但是可以重合，可得到一个多边形或一条线段或一个多边形和一个线段的连接后的图形； 
如果是一条线段,我们定义面积为0，重心坐标为（0,0）.现在求给出的点集组成的图形的面积和重心横纵坐标的和；
输入
第一行有一个整数0<n<11,表示有n组数据；
每组数据第一行有一个整数m<10000,表示有这个多边形有m个顶点；
输出
输出每个多边形的面积、重心横纵坐标的和，小数点后保留三位；
样例输入
3
3
0 1
0 2
0 3
3
1 1
0 0
0 1
4
1 1
0 0
0 0.5
0 1
样例输出
0.000 0.000
0.500 1.000
0.500 1.000
*/
