#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

string s1, s2;
int dp[1005][1005];

int unionlong()
{
	int i, j, k;
	int len1 = s1.length();
	int len2 = s2.length();
	int len = 0;
	memset(dp, 0, sizeof(dp));
	for (i = 1; i <= len1; i ++)
	{
		for (j = 1; j <= len2; j ++)
		{
			if (s1[i-1] == s2[j-1])
				dp[i][j] = dp[i-1][j-1]+1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[len1][len2];
}

int main()
{
	int t, k;
	cin >> t;
	while (t --)
	{
		cin >> s1 >> s2;
		k = unionlong();
		cout << k << endl;
	}
	return 0;
}
/*
描述
咱们就不拐弯抹角了，如题，需要你做的就是写一个程序，得出最长公共子序列。
tip：最长公共子序列也称作最长公共子串(不要求连续)，英文缩写为LCS（Longest Common Subsequence）。其定义是，一个序列 S ，如果分别是两个或多个已知序列的子序列，且是所有符合此条件序列中最长的，则 S 称为已知序列的最长公共子序列。
输入
第一行给出一个整数N(0<N<100)表示待测数据组数
接下来每组数据两行，分别为待测的两组字符串。每个字符串长度不大于1000.
输出
每组测试数据输出一个整数，表示最长公共子序列长度。每组结果占一行。
样例输入
2
asdf
adfsd
123abc
abc123abc
样例输出
3
6
*/
