#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

#define mid ((l+r)>>1)
#define lson i<<1, l, mid 
#define rson i<<1|1, mid+1, r 

int n;
int poster[40005];
int posters[40005];
bool tree[160005];
map <int, int> im;

void init(int i, int l, int r)
{
	tree[i] = false;
	if (l == r)
		return;
	init(lson);
	init(rson);
}

bool update(int i, int l, int r, int m, int n)
{
	bool x, y;
	x = y = false;
	if (tree[i]) // 区间已覆盖 
		return false;
	if (l == m && r == n) // 未覆盖，将这个区间覆盖，并返回找到 
	{
		tree[i] = true;
		return true;
	}
	if (n <= mid)
	{
		x = update(lson, m, n);
	}
	else if (m > mid)
	{
		x = update(rson, m, n);
	}
	else
	{
		x = update(lson, m, mid);
		y = update(rson, mid+1, n);
	}
	if (tree[i<<1] && tree[i<<1|1]) // 如果更新后这个区间能够被左右加起来覆盖 
		tree[i] = true;
	return (x|y);
}

int main()
{
	int i, it, t, num;
	cin >> t;
	while (t --)
	{
		cin >> n;
		num = 0;
		for (i = 1; i <= n; i ++)
		{
			cin >> poster[i<<1] >> poster[i<<1|1];
		}
		for (i = 2; i <= (n<<1|1); i ++)
		{
			posters[i] = poster[i];
		}
		// 离散化 
		sort(poster+2, poster+(n<<1)+2);
		for (i = 2, it = 0; i <= (n<<1|1); i ++)
		{
			if (poster[i] != 2 && poster[i] == poster[i-1])
				continue;
			im[poster[i]] = ++ it;
		}
		// 初始化 
		init(1, 1, it);
		// 从后向前插入post，如果没有被之前全覆盖num++ 
		for (i = n; i >=1; i --)
		{
			if(update(1, 1, it, im[posters[i<<1]], im[posters[i<<1|1]]))
				num ++;
		}
		cout << num << endl; 
	}
	return 0;
}
/*
海报，后面会覆盖前面的，贴完后看有多少张没有完全被覆盖住的 
6
3
5 6
4 5
6 8
3
1 10
1 3
6 10
5
1 4
2 6
8 10
3 4
7 10
5
1 2
2 3
3 4
4 5
5 6
5
1 4
2 6
8 10
3 4
7 10
10
15 18
6 11
2 10
1 4
16 17
5 14
8 19
7 9
3 13
12 20

#include <iostream>
#include <set>
#include <map>
using namespace std;
 
#define mid ((l+r)>>1)
#define lson i<<1, l, mid
#define rson i<<1|1, mid+1, r
 
int n, Max;
int poster[40005];
bool tree[160005];
set <int> is;
set <int>::iterator it;
map <int, int> im;
 
void init(int i, int l, int r)
{
	tree[i] = false;
	if (l == r)
	return;
	init(lson);
	init(rson);
}
 
bool update(int i, int l, int r, int m, int n)
{
	bool x, y;
	x = y = false;
	if (tree[i]) // 区间已覆盖
		return false;
	if (l == m && r == n) // 未覆盖，将这个区间覆盖，并返回找到
	{
		tree[i] = true;
		return true;
	}
	if (n <= mid)
	{
		x = update(lson, m, n);
	}
	else if (m > mid)
	{
		x = update(rson, m, n);
	}
	else
	{
		x = update(lson, m, mid);
		y = update(rson, mid+1, n);
	}
	if (tree[i<<1] && tree[i<<1|1]) // 如果更新后这个区间能够被左右加起来覆盖
		tree[i] = true;
	return (x|y);
}
 
int main()
{
	int i, t, num;
	cin >> t;
	while (t --)
	{
		cin >> n;
		num = 0;
		// 输入并将点插入set容器
		for (i = 1; i <= n; i ++)
		{
			cin >> poster[i<<1] >> poster[i<<1|1];
		}
		for (i = 1; i <= n; i ++)
		{
			is.insert(poster[i<<1]);
			is.insert(poster[i<<1|1]);
		}
		// 离散化
		for (it = is.begin(), i = 1; it != is.end(); it ++, i ++)
		{
			im[*it] = i;
		}
		Max = i-1;
		// 初始化
		init(1, 1, Max);
		// 从后向前插入poster，如果没有被之前全覆盖num++
		for (i = n; i >=1; i --)
		{
			if(update(1, 1, Max, im[poster[i<<1]], im[poster[i<<1|1]]))
			num ++;
		}
		cout << num << endl;
	}
	return 0;
}
*/
