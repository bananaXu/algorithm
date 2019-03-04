#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <cmath>
#include <vector> 
#include <queue>
#include <ctype.h>
#include <map>
#include <cfloat>
using namespace std;

struct Fra
{
	Fra(int m, int n) {x = m; y = n;}
	int x;
	int y;
	bool operator <(const Fra &a)const {return x*a.y < y*a.x;}
};

struct Point
{
	int l;
	int r;
	int val;
	bool operator <(const Point &a)const {return val < a.val;}
}point[5005];

int father[505];

int findfather(int x)
{
	while (father[x] != x) x = father[x];
	return x;
}

int Gcd(int x, int y)
{
	if (x < y)
		swap(x, y);
	while (y)
	{
		x %= y;
		if (x < y)
			swap(x, y);
	}
	return x;
}

int main()
{
	int i, j, n, m, t, S, T;
	scanf("%d", &t);
	while (t --)
	{
		scanf("%d%d", &n, &m);
		for (i = 1; i <= m; i ++)
			scanf("%d%d%d", &point[i].l, &point[i].r, &point[i].val);
		sort(point+1, point+m+1); // 将所有边依据速度按从小到大排序 
		scanf("%d%d", &S, &T);
		Fra MinFra(1, 0); // 最小的分数，初始化为1/0 
		for (i = m; i >= 1; i --) // 按从大到小速度的边来寻找将起点和终点并到一个集合 
		{
			int Max = point[i].val;
			for (j = 1; j <= n; j ++) // 初始化每个点的祖先节点 
				father[j] = j;
			for (j = i; j >= 1; j --) // 从当前边往下找 
			{
				int Min = point[j].val;
				Fra nowFra(Max, Min);
				if (MinFra < nowFra) // 此时的速度过小，最大速度/最小速度过大 
					break;
				int fl = findfather(point[j].l), fr = findfather(point[j].r);
				if (fl != fr) // 如果这条边连的两个点不在一个集合，将他们合并 
				{
					father[fl] = fr;
					if (findfather(S) == findfather(T)) // 合并后起点和终点连通 
					{
						if (nowFra < MinFra) // 此句废话，懒得删 
						{
							MinFra = nowFra;
							break;
						}
					}
				}
			}
		}
	 	int x = MinFra.x, y = MinFra.y;
		if (y == 0) // 并未找到连通S，T的路 
			printf("IMPOSSIBLE\n");
		else if (x%y)
		{
			int GCD = Gcd(x, y);
			printf("%d/%d\n", x/GCD, y/GCD);
		}	
		else
			printf("%d\n", x/y);
	}
	return 0;
}
/*
最舒适的路线
时间限制：5000 ms  |  内存限制：65535 KB
难度：5
描述
异形卵潜伏在某区域的一个神经网络中。其网络共有N个神经元（编号为1,2,3,…,N），这些神经元由M条通道连接着。两个神经元之间可能有多条通道。异形卵可以在这些通道上来回游动，但在神经网络中任一条通道的游动速度必须是一定的。当然异形卵不希望从一条通道游动到另一条通道速度变化太大，否则它会很不舒服。

现在异形卵聚居在神经元S点，想游动到神经元T点。它希望选择一条游动过程中通道最大速度与最小速度比尽可能小的路线，也就是所谓最舒适的路线。

输入
第一行： K 表示有多少组测试数据。 
接下来对每组测试数据：
第1行: N M
第2~M+1行： Xi Yi Vi (i=1,…..,M)
表示神经元Xi 到神经元Yi之间通道的速度必须是Vi
最后一行： S T ( S ? T )

【约束条件】
2≤K≤5 1<N≤500 0<M≤5000 1≤ Xi, Yi , S , T ≤N 0< Vi <30000，
Vi是整数。数据之间有一个空格。
输出
对于每组测试数据，输出一行：如果神经元S到神经元T没有路线，输出“IMPOSSIBLE”。否则输出一个数，表示最小的速度比。如果需要，输出一个既约分数。
样例输入
2
3 2
1 2 2
2 3 4
1 3
3 3
1 2 10
1 2 5
2 3 8
1 3
样例输出
2
5/4
*/
