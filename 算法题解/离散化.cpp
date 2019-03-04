#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
	int val;
	int index;
};

bool cmp(node a, node b)
{
	return a.val < b.val;
}

int main()
{
	int i, n;
	cin >> n;
	node *arr = new node[n+1];
	int *a = new int[n+1];
	for (i = 1; i <= n; i ++)
	{
		cin >> arr[i].val;
		arr[i].index = i;
	}
	sort(arr+1, arr+n+1, cmp);
	for (i = 1; i <= n; i ++)
	{
		a[arr[i].index] = i;
	}
	for (i = 1; i <= n; i ++)
	{
		cout << arr[i].index << " " << arr[i].val << endl;
	}
	free(arr);
	free(a);
	return 0;
}
/*
10
156 25 478 66 99 41 316 55 11 514 
*/
