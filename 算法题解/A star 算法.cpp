#include <iostream>
#include <set>
using namespace std;
#define MAX 0x7fffffff/10

struct Node
{
	int x; // x坐标 
	int y; // y坐标 
	int IsPass; // 是否能够经过 0、能，1、不能 
	int fatherX; // 父节点x坐标 
	int fatherY; // 父节点y坐标 
	int close; // 是否关闭 1、是，0、否 
	int g; // 离起点估价 
	int h; // 离终点估价 
	bool operator<(const struct Node &m)const // 重载<运算符，按估价低排序 
	{									      // g+h低的最先，相同的按h低的先 
		if (this->g+this->h < m.g+m.h)
			return true;
		else if (this->g+this->h > m.g+m.h)
			return false;
		else
			return this->h < m.h;
	}
};
Node **p = NULL; // 图上所有点 
int n, m; // 图的大小 
multiset <Node>open;
multiset <Node>::iterator it;
void search()
{
	int *b = NULL;
	int i, x, y, x1, y1; // x,y当前点坐标，x1,y1当前点四周坐标 
	int a[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // 上下左右四个方向 
	p[1][1].g = 0;
	open.insert(p[1][1]); // 首先插入原点 
	while (!open.empty())
	{
		it = open.begin(); // 估价最小的点 
		x = (*it).x;
		y = (*it).y;
		if (x == n && y == m) // 到达终点 
			return;
		for (i = 0; i <= 3; i ++)
		{
			x1 = x+a[i][0];
			y1 = y+a[i][1];
			if (x1 > 0 && x1 <= n && y1 > 0 && y1 <= m && // 规定范围内 
				!p[x1][y1].close && !p[x1][y1].IsPass && // 未关闭且能通过 
				p[x][y].g+1 < p[x1][y1].g) // 小于原路径的值 
			{
				p[x1][y1].g = p[x][y].g+1;
				p[x1][y1].fatherX = x;
				p[x1][y1].fatherY = y;
				open.insert(p[x1][y1]);
			}
		}
		p[x][y].close = 1;
		open.erase(it); // 注意，multiset使用值删除会把相同的全删掉 ，所以
		                // 用迭代器删除 
	}
}

void output(Node x)
{
	if (x.x == 1 && x.y == 1)
		return;
	else
		output(p[x.fatherX][x.fatherY]);
	cout << "(" << x.fatherX << "," << x.fatherY << ")->"
		 << "(" << x.x << "," << x.y << ")" << endl;
}

void init()
{
	int i, j, x;
	cin >> n >> m; 
	// 开辟n*m大小的新空间，输入并存储图上的点 
	p = new Node*[n+1];
	p[0] = NULL;
	for (i = 1; i <= n; i ++)
	{
		p[i] = new Node[m+1];
	}
	for (i = 1; i <= n; i ++)
	{
		for (j = 1; j <= m; j ++)
		{
			cin >> x;
			p[i][j].IsPass = x;
			p[i][j].x = i;
			p[i][j].y = j; 
			p[i][j].close = 0;
			p[i][j].g = MAX;
			p[i][j].h = n+m-i-j;
		}
	}
}

void freeAll()
{
	int i;
	for (i = 0; i <= n; i ++)
	{
		free(p[i]);
	}
	free(p);
}

int main()
{
	// 必须有起点到终点的路径，未做异常处理 
	init(); // 初始化 
	search(); // 寻找最短路 
	output(p[n][m]); // 输出路径 
	cout << p[n][m].g << endl; // 输出条数 
	freeAll(); // 释放开辟的空间 
	return 0;	
}
// 测试数据 
/*
5 5
0 1 0 0 0
0 0 0 1 0
0 0 1 0 0
1 0 1 1 0
1 1 1 1 0
*/
/*
7 7
0 1 1 0 0 1 1
0 0 1 1 0 0 0
1 0 0 0 0 1 1
0 0 1 1 0 0 0
0 1 1 1 0 0 1
0 1 0 0 0 0 1
0 0 1 0 0 0 0
*/
/*
8 8
0 1 1 0 0 1 1 0
0 0 1 1 0 0 0 0
1 0 0 0 0 1 1 0
0 0 1 1 0 0 0 0
0 1 1 1 1 0 1 0
0 1 0 0 0 0 1 1
0 0 1 0 1 1 1 0
0 0 1 0 0 0 0 0
*/
