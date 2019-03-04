#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
#include <map>
using namespace std;
  
const int N = 35;  
const int INF = 0xffffff;  
const double eps = 1e-8;  
  
struct POINT  
{  
    double x, y;  
};  
  
struct LINE  
{  
    POINT a, b;  
} l[N];  
int n;  
  
double cross(POINT a, POINT b, POINT c)///根据正负判断三点是顺时针还是逆时针  
{  
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);  
}  
  
int Judge(POINT X, POINT Y)  
{  
    int ans = 0;  
    for(int i = 0; i < n; i ++)  
    {  
        if(cross(X, l[i].a, l[i].b) * cross(Y, l[i].a, l[i].b) < -eps)///判断两条线是否相交,即点X点Y在线l[i]的两侧，一个顺时针，一个逆时针，相乘小于0即在正方形区域一定相交  
            ans ++;  
    }  
    return ans;  
}  
  
int main()  
{  
    int T;  
    scanf("%d", &T);  
    while(T --)  
    {  
        scanf("%d", &n);  
        if(n == 0)  
        {  
            puts("1");  
            continue;  
        }  
        for(int i = 0; i < n; i ++)  
        {  
            scanf("%lf %lf %lf %lf", &l[i].a.x, &l[i].a.y, &l[i].b.x, &l[i].b.y);  
        }  
        POINT d;  
        scanf("%lf %lf", &d.x, &d.y);  
        int ans = INF;  
        for(int i = 0; i < n; i++)///枚举求墙的端点与宝藏构成的线与其它线相交的最少次数  
        {  
            ans = min(Judge(l[i].a, d), ans);  
            ans = min(Judge(l[i].b, d), ans);  
        }  
        printf("%d\n", ans + 1);///加1是边界的墙  
    }  
    return 0;  
} 
/*
描述
一个叫ACM的寻宝者找到了一个藏宝图，它根据藏宝图找到了一个迷宫，这是一个很特别的迷宫，迷宫是一100*100的个正方形区域，里面有很多墙，这些墙都是由一些直线构成的，如下图。

墙把迷宫分隔成很多藏宝室，任何两个藏宝室之间都没有门。

ACM现在准备用开凿设备在相邻两个藏宝室的墙中间凿开一个门，最终取出迷宫中的宝物。

但是，开凿门是一件很费力费时的工作，ACM想开凿尽量少的门取出宝物，现在请你写一个程序来帮助它判断一下最少需要开几个门吧。

输入
第一行输入一个正数N(N<10)表示测试数据组数
每组测试数据的第一行是一个整数n(0<=n<=30),代表了墙的个数，随后的n行里每行有四个整数x1,x2,y1,y2，这四个数分别是代表一个墙的两个端点的坐标。外围的正方形四个顶点固定在(0,0)(0,100)(100,0)(100,100)这四堵个墙不在上面的n个数里。注意，不能在两个线的交点处开凿门。
数据保证任意两个中间墙的交点不在四周的墙上。
输完所有的墙后，输入两个数，x,y（可能不是整数），表示宝藏的坐标。
输出
输出最少需要开凿的门的个数
样例输入
1
7 
20 0 37 100 
40 0 76 100 
85 0 0 75 
100 90 0 90 
0 71 100 61 
0 14 100 38 
100 47 47 100 
54.5 55.4 
样例输出
2
*/
