#include <iostream>
#include <algorithm>
using namespace std;

int a[10];
int used[10];
int n, m;

void GetPermutation(int pos)
{
	int i;
	if (pos == m+1)
	{
		for (i = 1; i <= m; i ++)
			cout << a[i];
		cout << endl;
	}
	// 回溯 
	for (i = 1; i <= n; i ++)
	{
		if (!used[i])
		{
			used[i] = 1;
			a[pos] = i;
			GetPermutation(pos+1);
			used[i] = 0;
		}
	}
}

int main()
{
	int i, t;
	cin >> t;
	while (t --)
	{
		cin >> n >> m;
		for (i = 1; i <= 9; i ++)
		{
			used[i] = 0;
			a[i] = i;
		}
		GetPermutation(1);
	}
	return 0;
}
/*
描述
小明十分聪明，而且十分擅长排列计算。比如给小明一个数字5，他能立刻给出1-5按字典序的全排列，如果你想为难他，在这5个数字中选出几个数字让他继续全排列，那么你就错了，他同样的很擅长。现在需要你写一个程序来验证擅长排列的小明到底对不对。
输入
第一行输入整数N（1<N<10）表示多少组测试数据，
每组测试数据第一行两个整数 n m (1<n<9,0<m<=n)
输出
在1-n中选取m个字符进行全排列，按字典序全部输出,每种排列占一行，每组数据间不需分界。如样例
样例输入
2
3 1
4 2
样例输出
1
2
3
12
13
14
21
23
24
31
32
34
41
42
43
*/
