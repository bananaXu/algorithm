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

int a[25];

/*
算法思想：
先排序，如果前面的数能组成1~x
那么如果这个数大于x+1，那么一定不能组成x+1
如果这个数为t(1~x+1)那么一定能组成1~x+t内所有数 
*/ 

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	sort(a+1, a+n+1);
	int sum = 0;
	for (int i = 1; i <= n; i ++)
	{
		if (a[i] > sum+1)
			break;
		sum += a[i];
	}
	cout << sum+1 << endl;
	return 0;
}
/*
题目大意：
给一个数组，每个数最多用一次组成一个数，求不能组成的最小数字 
*/
