#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a < b ? a : b

int n, x, y;
int k[100005];
int mm[100005][20], mi[100005][20];
// rmp算法
// dp[i][j]表示k[i]到k[i+(2^j)-1]的最值 
void rmq_isit()  
{  
	int i, j;
    for(i = 1; i <= n; i++)  
        mm[i][0] = mi[i][0] = k[i];  
    for(j = 1; (1<<j) <= n; j++)  
    {  
        for(i = 1; i+(1<<j)-1 <= n; i ++)  
        { 
            mm[i][j] = MAX(mm[i][j-1], mm[i+(1<<(j-1))][j-1]);  
            mi[i][j] = MIN(mi[i][j-1], mi[i+(1<<(j-1))][j-1]);  
        }  
    }  
}

int rmq(int l,int r)  
{  
    int k = 0;  
    k = (int)(log(y-x+1.0)/log(2.0));
    int ans1 = MAX(mm[l][k], mm[r-(1<<k)+1][k]);  
    int ans2 = MIN(mi[l][k], mi[r-(1<<k)+1][k]);  
    return ans1-ans2;  
}  

int main()
{
	int i, j, q;
	scanf("%d%d", &n, &q);
	for (i = 1; i <= n; i ++)
		scanf("%d", &k[i]);
	rmq_isit();
	for (i = 1; i <= q; i ++)
	{
		scanf("%d%d", &x, &y);
		printf("%d\n", rmq(x, y));
	}
	return 0;
} 
/*
描述
南将军统率着N个士兵，士兵分别编号为1~N,南将军经常爱拿某一段编号内杀敌数最高的人与杀敌数最低的人进行比较，计算出两个人的杀敌数差值，用这种方法一方面能鼓舞杀敌数高的人，另一方面也算是批评杀敌数低的人，起到了很好的效果。
所以，南将军经常问军师小工第i号士兵到第j号士兵中，杀敌数最高的人与杀敌数最低的人之间军功差值是多少。
现在，请你写一个程序，帮小工回答南将军每次的询问吧。
注意，南将军可能询问很多次。
输入
只有一组测试数据
第一行是两个整数N,Q，其中N表示士兵的总数。Q表示南将军询问的次数。(1<N<=100000,1<Q<=1000000)
随后的一行有N个整数Vi(0<=Vi<100000000)，分别表示每个人的杀敌数。
再之后的Q行，每行有两个正正数m,n，表示南将军询问的是第m号士兵到第n号士兵。
输出
对于每次询问，输出第m号士兵到第n号士兵之间所有士兵杀敌数的最大值与最小值的差。
样例输入
5 2
1 2 6 9 3
1 2
2 4
样例输出
1
7
*/
