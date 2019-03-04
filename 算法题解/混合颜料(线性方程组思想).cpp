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

vector <int> v;

int getlen(int x)
{
	int t = (int)(log(x)/log(2)+1e-8);
	return (1<<t);
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	n --;
	int sum = 0;
	while (n > 0 && v[n])
	{
		int t = getlen(v[n]);
		for (int i = 0; i < n; i ++)
		{
			if (v[i]&t)
				v[i] ^= v[i+1];
		}
		sum ++;
		n --;
		v.pop_back();
		sort(v.begin(), v.end());
	}
	if (v[n])
		sum ++;
	cout << sum << endl;
	return 0;
}
/*
题目大意
给你n个数，从中选最少的数，能够异或出所有数 
算法思想：
先排序 
找出最大数最高位，将所有这一位为1的数异或比他大的一个数，就变成0了
然后最大的数无论怎么也不可能异或出其他数，将其删除，总数加一
直到最后只有一个数或者所有数都是0 
*/
