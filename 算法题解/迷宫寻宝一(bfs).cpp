#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct ROOM
{
	int x;
	int y;
	char type;
}room[25][25];

int m, n;
int r[5];
queue <ROOM> qu;
int dir[4][2] = {{0, 1},{0, -1},{-1, 0},{1, 0}};
int OC[25][25]; // open:1, close:2, else:0

bool CanCross(int x, int y)
{
	if (room[x][y].type == 'X')
		return false;
	if (room[x][y].type >= 'A' && room[x][y].type <= 'E')
		return false;
	return true;
}

bool CanReach(int x, int y)
{
	int i, a, b;
	for (i = 0; i < 4; i ++)
	{
		a = dir[i][0]+x;
		b = dir[i][1]+y;
		if (a >= 1 && b >= 1 && a <= m && b <= n &&
		    CanCross(a, b) && OC[a][b])
  			return true; 
	}
	return false;
}

void Close(int x, int y)
{
	int i, j, k, a, b, z;
	for (i = 0; i < 4; i ++)
	{
		a = dir[i][0]+x;
		b = dir[i][1]+y;
		if (a >= 1 && b >= 1 && a <= m && b <= n && !OC[a][b] && CanCross(a, b))
 		{
		 	if (room[a][b].type >= 'a' && room[a][b].type <= 'e')
		 	{
		 		z = room[a][b].type-'a';
	 			r[z] --;
	 			if (!r[z]) // 如果获得全部钥匙，将对应门换为'.'，如果能从之前的路到达，加入队列中 
	 			{
		 			for (j = 1; j <= m; j ++)
		 			{
		 				for (k = 1; k <= n; k ++)
				 		{
			 				if (room[j][k].type == z+'A')
			 				{
				 				room[j][k].type = '.';
				 				if (CanReach(j, k))
				 				{
				 					qu.push(room[j][k]);
				 					OC[j][k] = 1;
				 				}
				 			}
			 			}
				 	}
	 			}
	 		}
	 		qu.push(room[a][b]);
	 		OC[a][b] = 1;
		}
	}
}

bool getout(int a, int b)
{
	ROOM x;
	while (!qu.empty())
		qu.pop();
	OC[a][b] = 1;
	qu.push(room[a][b]); // 从s开始 
	memset(OC, 0, sizeof(OC));
	while (!qu.empty()) 
	{
		x = qu.front();
		if (x.type == 'G')
			return true;
		qu.pop();
		OC[x.x][x.y] = 2;
		Close(x.x, x.y); // 将与x相连(能到达且没到达过的点)的点加入，并close x点 
	}
	return false;
}

int main()
{
	int i, j, x, y;
	bool O;
	while (1)
	{
		cin >> m >> n;
		if (m == 0 && n == 0)
			break;
		memset(r, 0, sizeof(r));
		for (i = 1; i <= m; i ++)
		{
			for (j = 1; j <= n; j ++)
			{
				cin >> room[i][j].type;
				room[i][j].x = i;
				room[i][j].y = j;
				if (room[i][j].type >= 'a' && room[i][j].type <= 'e')
				{
					r[room[i][j].type-'a'] ++;
				}
				if (room[i][j].type == 'S')
				{
					x = i;
					y = j;
				}
			}
		}
		O = getout(x, y);
		if (O)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
/*
描述
一个叫ACM的寻宝者找到了一个藏宝图，它根据藏宝图找到了一个迷宫，这是一个很特别的迷宫，迷宫里有N个编过号的门（N<=5)，它们分别被编号为A,B,C,D,E.为了找到宝藏，ACM必须打开门，但是，开门之前必须在迷宫里找到这个打开这个门所需的所有钥匙（每个门都至少有一把钥匙），例如：现在A门有三把钥匙，ACM就必须找全三把钥匙才能打开A门。现在请你编写一个程序来告诉ACM，他能不能顺利的得到宝藏。

 

输入
输入可能会有多组测试数据（不超过10组）。
每组测试数据的第一行包含了两个整数M,N(1<N,M<20)，分别代表了迷宫的行和列。接下来的M每行有N个字符，描述了迷宫的布局。其中每个字符的含义如下：
.表示可以走的路
S:表示ACM的出发点
G表示宝藏的位置
X表示这里有墙，ACM无法进入或者穿过。
A,B,C,D,E表示这里是门，a,b,c,d,e表示对应大写字母的门上的钥匙。
注意ACM只能在迷宫里向上下左右四个方向移动。

最后，输入0 0表示输入结束。
输出
每行输出一个YES表示ACM能找到宝藏，输出NO表示ACM找不到宝藏。
样例输入
4 4 
S.X. 
a.X. 
..XG 
.... 
3 4 
S.Xa 
.aXB 
b.AG 
0 0
样例输出
YES 
NO

5 5
SXaXG
.X.X.
.X.X.
.X.XA
.....
5 5
aE..S
bXX.c
XX.CX
GBA.B
XXe.e
5 5
a...a
XX.XX
bXSXG
.XAXB
.....
5 5
.X.XG
Sa..A
.b.Xc
XX..B
bC...
5 5
.X.XG
Sb..B
.b.Xc
XX..B
bC...
0 0
*/
