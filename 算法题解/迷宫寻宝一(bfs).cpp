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
	 			if (!r[z]) // ������ȫ��Կ�ף�����Ӧ�Ż�Ϊ'.'������ܴ�֮ǰ��·������������ 
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
	qu.push(room[a][b]); // ��s��ʼ 
	memset(OC, 0, sizeof(OC));
	while (!qu.empty()) 
	{
		x = qu.front();
		if (x.type == 'G')
			return true;
		qu.pop();
		OC[x.x][x.y] = 2;
		Close(x.x, x.y); // ����x����(�ܵ�����û������ĵ�)�ĵ���룬��close x�� 
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
����
һ����ACM��Ѱ�����ҵ���һ���ر�ͼ�������ݲر�ͼ�ҵ���һ���Թ�������һ�����ر���Թ����Թ�����N������ŵ��ţ�N<=5)�����Ƿֱ𱻱��ΪA,B,C,D,E.Ϊ���ҵ����أ�ACM������ţ����ǣ�����֮ǰ�������Թ����ҵ��������������������Կ�ף�ÿ���Ŷ�������һ��Կ�ף������磺����A��������Կ�ף�ACM�ͱ�����ȫ����Կ�ײ��ܴ�A�š����������дһ������������ACM�����ܲ���˳���ĵõ����ء�

 

����
������ܻ��ж���������ݣ�������10�飩��
ÿ��������ݵĵ�һ�а�������������M,N(1<N,M<20)���ֱ�������Թ����к��С���������Mÿ����N���ַ����������Թ��Ĳ��֡�����ÿ���ַ��ĺ������£�
.��ʾ�����ߵ�·
S:��ʾACM�ĳ�����
G��ʾ���ص�λ��
X��ʾ������ǽ��ACM�޷�������ߴ�����
A,B,C,D,E��ʾ�������ţ�a,b,c,d,e��ʾ��Ӧ��д��ĸ�����ϵ�Կ�ס�
ע��ACMֻ�����Թ��������������ĸ������ƶ���

�������0 0��ʾ���������
���
ÿ�����һ��YES��ʾACM���ҵ����أ����NO��ʾACM�Ҳ������ء�
��������
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
�������
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
