#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <cmath>
#include <vector> 
#include <queue>
#include <set>
#include <ctype.h>
#include <map>
#include <cfloat>
using namespace std;

typedef pair<int, int> lp;
vector <lp> v;

int a[9][9];

bool legal(int x, int y, int v)
{
	for (int i = x/3*3; i <= x/3*3+2; i ++)
	{
		for (int j = y/3*3; j <= y/3*3+2; j ++)
			if (a[i][j] == v)
				return false;
	}
	for (int i = 0; i < 9; i ++)
		if (a[x][i] == v || a[i][y] == v)
			return false;
	return true; 
}

bool dfs(int num)
{
	if (num == v.size())
		return true;
	int x = v[num].first, y = v[num].second;
	for (int i = 1; i <= 9; i ++)
	{	
		if (legal(x, y, i))
		{
			a[x][y] = i;
			if (dfs(num+1))
				return true;
			a[x][y] = 0;
		}
	}
	return false;
}

int main()
{
	for (int i = 0; i < 9; i ++)
	{
		for (int j = 0; j < 9; j ++)
		{
			cin >> a[i][j];
			if (!a[i][j])
				v.push_back(make_pair(i, j));
		}
	}
	dfs(0);
	for (int i = 0; i < 9; i ++)
	{
		for (int j = 0; j < 9; j ++)
		{
			if (j != 8)
				cout << a[i][j] << " ";
			else
				cout << a[i][j] << endl;
		}
	}
	return 0;
}
