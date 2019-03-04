#include <iostream>
#include <algorithm>
using namespace std;

int n;
int *a;
int *tree;

int lowbit(int k)
{
	return k&-k;
}

void add(int k, int num)
{
	while(k <= n)
	{
		tree[k] += num;
		k += lowbit(k);
	}
}

int getsum(int k)
{
	int sum = 0;
	while(k)
	{
		sum += tree[k];
		k -= lowbit(k);
	}
	return sum;
}

int main()
{
	int i, sum;
	cin >> n;
	a = new int[n+1];
	tree = new int[n+1];
	for (i = 1; i <= n; i ++)
	{
		cin >> a[i];
		tree[i] = 0;
	}
	sum = 0;
	for (i = 1; i <= n; i ++)
	{
		tree[a[i]] = 1;
		sum += getsum(a[i]);
	}
	cout << sum << endl;
	free(a);
	free(tree);
	return 0;
} 
// 5 2 5 4 3 1
// 6 5 4 2 1 6 3
