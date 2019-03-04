#include <iostream>
using namespace std;

#define mid ((l+r)>>1)
#define lson i<<1, l, mid 
#define rson i<<1|1, mid+1, r 

int Max[1000] = {0};
int Sum[1000] = {0};

void init(int i, int l, int r) 
{
	if (l == r)
		return;
	init(lson);
	init(rson);
}

void update(int i, int l, int r, int p, int val)
{
	if (l == r)
	{
		Sum[i] = val;
		return;
	}
	if(p <= mid)
		update(lson, p, val);
	else
		update(rson, p, val);
	Sum[i] = Sum[i<<1]+Sum[i<<1|1];
	Max[i] = max(Max[i<<1], Max[i<<1|1]);
}

int GetMax(int i, int l, int r, int L, int R)
{
	if (l == L && r == R)
		return Max[i];
	if (R <= mid)
		return GetMax(lson, L, R);
	if (l > mid)
		return GetMax(rson, L, R);
	return max(GetMax(lson, L, R), GetMax(rson, L, R));
}

int GetSum(int i, int l, int r, int L, int R)
{	
	if (l == L && r == R)
		return Sum[i];
	if (R <= mid)
		return GetSum(lson, L, R);
	if (l > mid)
		return GetSum(rson, L, R);
	return GetSum(lson, L, R) + GetSum(rson, L, R);
}

int main()
{
	int i, l, r, p, num, val;
	cin >> l >> r >> num;
	init(1, l, r); // 初始化
 	for (i = 1; i <= num; i++)
 	{
	 	cin >> p >> num >> val;
 		update(1, l, r, p, val); // 更新节点 
 	}
 	int n, m;
 	cin >> n >> m;
 	cout << GetSum(1, l, r, n, m) << endl; // 获得总数 
 	cin >> n >> m;
 	cout << GetMax(1, l, r, n, m) << endl; // 获得最大值 
	return 0;
} 
