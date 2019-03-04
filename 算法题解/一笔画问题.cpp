#include <iostream>
#include <cstring>
using namespace std;

int father[1005];

int FindFather(int x)
{
	while (x != father[x]) x = father[x];
	return x;
}
// 如果一个图是连通的并且奇度点为0或者2，则这个图能被一笔画出，否则不能 
int main()
{
	int i, t, n, m, l, r, num, f;
	int a[1005];
	bool connect;
	cin >> t;
	while (t --)
	{
		cin >> n >> m;
		num = 0;
		memset(a, 0, sizeof(a));
		for (i = 1; i <= n; i ++)
			father[i] = i;
		for (i = 1; i <= m; i ++)
		{
			cin >> l >> r;
			// 并查集将l, r合并 
			father[FindFather(l)] = FindFather(r);
			// 记录点的度数 
			a[l] ++;
			a[r] ++;
		}
		connect = true;
		f = FindFather(1);
		for (i = 2; i <= n; i ++)
		{
			if (FindFather(i) != f)
			{
				connect = false;
				break;
			}
		}
		if (connect) // 如果是连通的 
		{
			for (i = 1; i <= n; i ++)
			{
				if (a[i]&1)
					num ++;
				if (num > 2)
					break;
			}
			if (num == 0 || num == 2)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		else
			cout << "No" << endl;
	}
	return 0;
}
/*
描述
zyc从小就比较喜欢玩一些小游戏，其中就包括画一笔画，他想请你帮他写一个程序，判断一个图是否能够用一笔画下来。

规定，所有的边都只能画一次，不能重复画。

 

输入
第一行只有一个正整数N(N<=10)表示测试数据的组数。
每组测试数据的第一行有两个正整数P,Q(P<=1000,Q<=2000)，分别表示这个画中有多少个顶点和多少条连线。（点的编号从1到P）
随后的Q行，每行有两个正整数A,B(0<A,B<P)，表示编号为A和B的两点之间有连线。
输出
如果存在符合条件的连线，则输出"Yes",
如果不存在符合条件的连线，输出"No"。
样例输入
2
4 3
1 2
1 3
1 4
4 5
1 2
2 3
1 3
1 4
3 4
样例输出
No
Yes
*/
