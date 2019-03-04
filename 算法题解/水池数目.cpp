#include <iostream>
#include <queue>
using namespace std;

struct Node
{
	int l;
	int r;
};
int a[105][105];

int main()
{
	int i, j, k, t, m, n, x, y, num;	
	int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	queue <Node> iq;
	Node p, q;
	cin >> t;
	while (t --)
	{
		cin >> m >> n;
		num = 0;
		for (i = 1; i <= m; i ++)
		{
			for (j = 1; j <= n; j ++)
				cin >> a[i][j];
		}
		for (i = 1; i <= m; i ++)
		{
			for (j = 1; j <= n; j ++)
			{
				if (a[i][j])
				{
					num ++;
					q.l = i;
					q.r = j;
					iq.push(q);
					{
						while (!iq.empty())
						{
							q = iq.front();
							iq.pop();
							a[q.l][q.r] = 0;
							for (k = 0; k <= 3; k ++)
							{
								x = dir[k][0]+q.l;
								y = dir[k][1]+q.r;
								if (x > 0 && y > 0 && x <= m && y <= n && a[x][y])
								{
									p.l = x;
									p.r = y;
									iq.push(p);
								}
							}
						}
					}
				}
			}
		}
		cout << num << endl;
	}
	return 0;
}
/*
描述
南阳理工学院校园里有一些小河和一些湖泊，现在，我们把它们通一看成水池，假设有一张我们学校的某处的地图，这个地图上仅标识了此处是否是水池，现在，你的任务来了，请用计算机算出该地图中共有几个水池。
输入
第一行输入一个整数N，表示共有N组测试数据
每一组数据都是先输入该地图的行数m(0<m<100)与列数n(0<n<100)，然后，输入接下来的m行每行输入n个数，表示此处有水还是没水（1表示此处是水池，0表示此处是地面）
输出
输出该地图中水池的个数。
要注意，每个水池的旁边（上下左右四个位置）如果还是水池的话的话，它们可以看做是同一个水池。
样例输入
2
3 4
1 0 0 0 
0 0 1 1
1 1 1 0
5 5
1 1 1 1 0
0 0 1 0 1
0 0 0 0 0
1 1 1 0 0
0 0 1 1 1
样例输出
2
3
*/
