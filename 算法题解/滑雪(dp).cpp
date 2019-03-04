#include <iostream>
using namespace std;

#define MAX(a, b) a>b?a:b

int a[105][105];
int dis[105][105];
int Find[105][105];
int r, c;

int findDis(int x, int y)
{
	int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	int i, j, dx, dy, max;
	max = 0;
	Find[x][y] = 1;
	for (i = 0; i < 4; i ++)
	{
		dx = x+dir[i][0];
		dy = y+dir[i][1];
		if (dx > 0 && dy > 0 && dx <= r && dy <= c && a[x][y] > a[dx][dy])
		{
			if (!Find[dx][dy])
				dis[dx][dy] = findDis(dx, dy);
			max = MAX(dis[dx][dy]+1, max);
		}
	}
	return max;
}

int main()
{
	int i, j, max;
	cin >> r >> c;
	for (i = 1; i <= r; i ++)
	{
		for (j = 1; j <= c; j ++)
		{
			Find[i][j] = 0;
			cin >> a[i][j];
		}
	}
	max = 0;
	for (i = 1; i <= r; i ++)
	{
		for (j = 1; j <= c; j ++)
		{
			if (!Find[i][j])
				dis[i][j] = findDis(i, j);
		}
	}
	for (i = 1; i <= r; i ++)
	{
		for (j = 1; j <= c; j ++)
		{
			cout << dis[i][j] << " ";
			max = MAX(dis[i][j], max);
		}
		cout << endl;
	}
	cout << max << endl;
	return 0;
} 
/*
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
*/
/*
6 5
1 5 6 2 4
6 44 5 1 8
2 5 47 6 7
22 45 47 62 1
59 6 5 7 55
8 9 2 7 9
*/
