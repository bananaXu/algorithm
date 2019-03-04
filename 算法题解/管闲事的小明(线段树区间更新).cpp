#include <iostream>
#include <set>
using namespace std;

#define mid ((l+r)>>1)
#define lson i<<1, l, mid
#define rson i<<1|1, mid+1, r
int a[10005];

void init(int i, int l, int r)
{
	a[i] = r-l+1;
	if (l == r)
		return;
	init(lson);
	init(rson);
}
//线段树，区间更新 
void insert(int i, int l, int r, int x, int y) 
{
	if (!a[i])
		return;
	if (l == x && r == y)
	{
		a[i] = 0;
		return;
	}
	if (y <= mid)
		insert(lson, x, y);
	else if(x > mid)
		insert(rson, x, y);
	else
	{
		insert(lson, x, mid);
		insert(rson, mid+1, y);
	}
	a[i] = a[i<<1]+a[i<<1|1];
}

int main()
{  
	int i, t, n, m, l, r;
	cin >> t;
	while(t --)
	{
		cin >> n >> m;
		init(1, 0, n);
		for (i = 1; i <= m; i ++)
		{
			cin >> l >> r;
			insert(1, 0, n, l, r);
		}
		cout << a[1] << endl;
	}
	return 0;
}
/*
描述
某校大门外长度为L的马路上有一排树，每两棵相邻的树之间的间隔都是1米。我们可以把马路看成一个数轴，马路的一端在数轴0的位置，另一端在L的位置；数轴上的每个整数点，即0，1，2，……，L，都种有一棵树。
　　由于马路上有一些区域要用来建地铁。这些区域用它们在数轴上的起始点和终止点表示。　　已知任一区域的起始点和终止点的坐标都是整数，区域之间可能有重合的部分。现在要把这些区域中的树（包括区域端点处的两棵树）移走。聪明的小明干了一件又一件事，他觉得这个很有意思，就想用计算机来帮助建筑工人统计这些树，现在任务来了，计算将这些树都移走后，马路上还有多少棵树。
输入
第一行是一个整数N表示有N组测试数据（1<=N<=100)
每组测试数据的第一行有两个整数：L（1 <= L <= 10000）和 M（1 <= M <= 100），L代表马路的长度，M代表区域的数目，L和M之间用一个空格隔开。接下来的M行每行包含两个不同的整数，用一个空格隔开，表示一个区域的起始点和终止点的坐标。 


输出
输出包括一行，这一行只包含一个整数，表示马路上剩余的树的数目。

样例输入
1
500 3
150 300
100 200
470 471
样例输出
298
*/
