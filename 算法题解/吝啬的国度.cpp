#include <iostream>
#include <cstring>
using namespace std;

struct Node
{
	int next;
	int r;
}node[300005];

int head[100005];
int pre[100005];
int I = 0;
int n, m;

void insert(int l, int r)
{
	node[I].r = r;
	node[I].next = head[l];
	head[l] = I ++;
}

void dfs(int x)
{
	int i, r;
	for (i = head[x]; i != -1; i = node[i].next)
	{
		r = node[i].r;
		if (!pre[r])
		{
			pre[r] = x;
			dfs(r);
		}
	}
}

int main()
{
	int i, t, l, r;
	cin >> t;
	while (t --)
	{
		cin >> n >> m;
		for (i = 1; i <= n; i ++)
		{
			pre[i] = 0;
			head[i] = -1;
		}
		for (i = 1; i < n; i ++)
		{
			cin >> l >> r;
			insert(l, r);
			insert(r, l);
		}
		dfs(m);
		pre[m] = -1; 
		for (i = 1; i <= n; i ++)
			cout << pre[i] << " ";
		cout << endl;
	}
	return 0;
}
/*
描述
在一个吝啬的国度里有N个城市，这N个城市间只有N-1条路把这个N个城市连接起来。现在，Tom在第S号城市，他有张该国地图，他想知道如果自己要去参观第T号城市，必须经过的前一个城市是几号城市（假设你不走重复的路）。
输入
第一行输入一个整数M表示测试数据共有M(1<=M<=5)组
每组测试数据的第一行输入一个正整数N(1<=N<=100000)和一个正整数S(1<=S<=100000)，N表示城市的总个数，S表示参观者所在城市的编号
随后的N-1行，每行有两个正整数a,b(1<=a,b<=N)，表示第a号城市和第b号城市之间有一条路连通。
输出
每组测试数据输N个正整数，其中，第i个数表示从S走到i号城市，必须要经过的上一个城市的编号。（其中i=S时，请输出-1）
样例输入
1
10 1
1 9
1 8
8 10
10 3
8 6
1 2
10 4
9 5
3 7
样例输出
-1 1 10 10 9 8 3 1 1 8
*/
