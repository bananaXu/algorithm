#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define INF 0x3f3f3f3f

struct Node
{
	int next;
	int r;
	int val;
}node[250005];

struct DIS
{
	int x;
	int d;
 	bool operator < (const DIS &a) const  
    {  
        return d > a.d;  
    } 
}dis;

int head[505]; 
int used[505]; // 已使用的点 
int Distance[505]; // 已使用的点到当前点的最小距离 
int I, m, n;

void insert(int l, int r, int val) // 边的插入 
{
	node[I].r = r;
	node[I].val = val;
	node[I].next = head[l];
	head[l] = I ++;
}

int GetDis()
{ 	// 最小生成树的优先队列优化 
	priority_queue <DIS> dp;
	int i, x, d, r, sum;
	sum = 0;
	dis.x = 1;
	dis.d = 0;
	dp.push(dis);
	while (!dp.empty())
	{
		dis = dp.top();
		dp.pop();
		x = dis.x;
		if (used[x]) continue; 
		used[x] = 1;
		sum += dis.d;
		for (i = head[x]; i != -1; i = node[i].next)
		{
			r = node[i].r;
			d = node[i].val;
			if (!used[r] && d < Distance[r]) // 未使用并且x点到当前点的距离小于之前的距离，则更新 
			{
				Distance[r] = d;
				dis.x = r;
				dis.d = d;
				dp.push(dis);
			}
		}
	}
	return sum;
}

int main()
{
	int i, t, l, r, val, x, Min;
	cin >> t;
	while (t --)
	{
		cin >> m >> n;
		I = 0;
		Min = INF;
		memset(head, -1, sizeof(head));
		memset(used, 0, sizeof(used));
		memset(Distance, INF, sizeof(Distance));
		for (i = 1; i <= n; i ++)
		{
			cin >> l >> r >> val;
			insert(l, r, val);
			insert(r, l, val);
		}
		for (i = 1; i <= m; i ++)
		{
			cin >> x;
			if (x < Min)
				Min = x;
		}
		cout << GetDis()+Min << endl;
	} 
	return 0;
}
/*
描述
南阳理工学院要进行用电线路改造，现在校长要求设计师设计出一种布线方式，该布线方式需要满足以下条件：
1、把所有的楼都供上电。
2、所用电线花费最少
输入
第一行是一个整数n表示有n组测试数据。(n<5)
每组测试数据的第一行是两个整数v,e.
v表示学校里楼的总个数(v<=500)
随后的e行里，每行有三个整数a,b,c表示a与b之间如果建铺设线路花费为c(c<=100)。（哪两栋楼间如果没有指明花费，则表示这两栋楼直接连通需要费用太大或者不可能连通）
随后的1行里，有v个整数,其中第i个数表示从第i号楼接线到外界供电设施所需要的费用。( 0<e<v*(v-1)/2 )
（楼的编号从1开始），由于安全问题，只能选择一个楼连接到外界供电设备。
数据保证至少存在一种方案满足要求。
输出
每组测试数据输出一个正整数,表示铺设满足校长要求的线路的最小花费。
样例输入
1
4 6
1 2 10
2 3 10
3 1 10
1 4 1
2 4 1
3 4 1
1 3 5 6
样例输出
4
*/
