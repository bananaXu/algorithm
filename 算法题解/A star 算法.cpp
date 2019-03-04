#include <iostream>
#include <set>
using namespace std;
#define MAX 0x7fffffff/10

struct Node
{
	int x; // x���� 
	int y; // y���� 
	int IsPass; // �Ƿ��ܹ����� 0���ܣ�1������ 
	int fatherX; // ���ڵ�x���� 
	int fatherY; // ���ڵ�y���� 
	int close; // �Ƿ�ر� 1���ǣ�0���� 
	int g; // �������� 
	int h; // ���յ���� 
	bool operator<(const struct Node &m)const // ����<������������۵����� 
	{									      // g+h�͵����ȣ���ͬ�İ�h�͵��� 
		if (this->g+this->h < m.g+m.h)
			return true;
		else if (this->g+this->h > m.g+m.h)
			return false;
		else
			return this->h < m.h;
	}
};
Node **p = NULL; // ͼ�����е� 
int n, m; // ͼ�Ĵ�С 
multiset <Node>open;
multiset <Node>::iterator it;
void search()
{
	int *b = NULL;
	int i, x, y, x1, y1; // x,y��ǰ�����꣬x1,y1��ǰ���������� 
	int a[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // ���������ĸ����� 
	p[1][1].g = 0;
	open.insert(p[1][1]); // ���Ȳ���ԭ�� 
	while (!open.empty())
	{
		it = open.begin(); // ������С�ĵ� 
		x = (*it).x;
		y = (*it).y;
		if (x == n && y == m) // �����յ� 
			return;
		for (i = 0; i <= 3; i ++)
		{
			x1 = x+a[i][0];
			y1 = y+a[i][1];
			if (x1 > 0 && x1 <= n && y1 > 0 && y1 <= m && // �涨��Χ�� 
				!p[x1][y1].close && !p[x1][y1].IsPass && // δ�ر�����ͨ�� 
				p[x][y].g+1 < p[x1][y1].g) // С��ԭ·����ֵ 
			{
				p[x1][y1].g = p[x][y].g+1;
				p[x1][y1].fatherX = x;
				p[x1][y1].fatherY = y;
				open.insert(p[x1][y1]);
			}
		}
		p[x][y].close = 1;
		open.erase(it); // ע�⣬multisetʹ��ֵɾ�������ͬ��ȫɾ�� ������
		                // �õ�����ɾ�� 
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
	// ����n*m��С���¿ռ䣬���벢�洢ͼ�ϵĵ� 
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
	// ��������㵽�յ��·����δ���쳣���� 
	init(); // ��ʼ�� 
	search(); // Ѱ�����· 
	output(p[n][m]); // ���·�� 
	cout << p[n][m].g << endl; // ������� 
	freeAll(); // �ͷſ��ٵĿռ� 
	return 0;	
}
// �������� 
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
