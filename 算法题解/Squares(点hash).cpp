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

#define M 1005
#define MOD 1000

class hash
{
public:
	void init();
	bool find(int x, int y);
	void push(int x, int y);
private:
	int Key[M][2], Next[M], Head[M];
	int index;
};

void hash::init()
{
	index = 0;
	memset(Head, -1, sizeof(Head));
	memset(Key, 0, sizeof(Key));
}

bool hash::find(int x, int y)
{
	int t = abs(x+y)%MOD;
	for (int i = Head[t]; i != -1; i = Next[i])
	{
		if (Key[i][0] == x && Key[i][1] == y)
			return true;
	}
	return false;
}

void hash::push(int x, int y)
{
	int t = abs(x+y)%MOD;
	Key[index][0] = x;
	Key[index][1] = y;
	Next[index] = Head[t];
	Head[t] = index ++;
}

int main()
{
	int a[M][2];
	while (1)
	{
		int n;
		hash h;
		int sum = 0;
		h.init();
		scanf("%d", &n);
		if (n == 0)
			break;
		for (int i = 1; i <= n; i ++)
		{
			scanf("%d%d", &a[i][0], &a[i][1]);
			h.push(a[i][0], a[i][1]);
		}
		for (int i = 1; i <= n; i ++)
		{
			for (int j = i+1; j <= n; j ++)
			{
				int x1, y1, x2, y2;
		 		x1 = a[i][0]-(a[j][1]-a[i][1]);
				y1 = a[i][1]+(a[j][0]-a[i][0]);
				x2 = x1+a[j][0]-a[i][0];
				y2 = y1+a[j][1]-a[i][1];
				if (h.find(x1, y1) && h.find(x2, y2))
					sum ++;
			}
		}
		printf("%d\n", (sum>>1));
	}
	return 0;
}
// 思想：将所有点以哈希形式存储，遍历所有边，看是否能找到与其组成正方形的上方的那条边 
/*
题意：给定一些点，找出所有的正方形； 
4
1 0
0 1
1 1
0 0
9
0 0
1 0
2 0
0 2
1 2
2 2
0 1
1 1
2 1
4
-2 5
3 7
0 0
5 2
0
样例输出
1
6
1
*/
