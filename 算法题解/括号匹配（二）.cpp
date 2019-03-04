#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

#define Min(a, b) a < b ? a : b
#define INF 0x3f3f3f3f

int GetMin(string s)
{
	int i, j, k, l;
	int len = s.length();
	int dp[105][105];
	// dp[i][j]代表s[i..j]里面最小添加数,显然dp[i][i]=1 
	for (i = 0; i < len; i ++)
	{
		dp[i][i] = 1;
	}
	// 如果s[i] == s[j] dp[i][j] = {MAX(dp[i+1][j-1], dp[i][k]+dp[k+1][j])(i<=k<j)} 
	// 如果s[i] ！= s[j] dp[i][j] = {MAX(dp[i][k]+dp[k+1][j])(i<=k<j)}
	// 由于dp[i][k]+dp[k+1][j]涉及到长度小于i-j的dp,所以以长度为第一层循环 
	for (l = 1; l < len; l ++)
	{
		for (i = 0; i+l < len; i ++)
		{
			j = i+l;
			if (s[i]+1 == s[j] || s[i]+2 == s[j])
				dp[i][j] = dp[i+1][j-1];
			else
				dp[i][j] = INF;
			for (k = i; k < j; k ++)
			{
				dp[i][j] = Min(dp[i][j], dp[i][k]+dp[k+1][j]);
			}
		}
	}
	return dp[0][len-1];
}

int main()
{
	int i, t, len;
	string s, a;
	cin >> t;
	while (t --)
	{
		cin >> s;
		len = s.length();
		stack <char> st;
		// 首先将[]和()全部排除，优化结构 
		for (i = 0; i < len; i ++)
		{
			if (s[i] == '(' || s[i] == '[')
				st.push(s[i]);
			else
			{
				if (!st.empty() && (s[i] == st.top()+1 || s[i] == st.top()+2))
				{
					st.pop();
				}
				else
					st.push(s[i]);
			}
		}
		a = "";
		while (!st.empty())
		{
			a = st.top()+a;
			st.pop();
		}
		cout << GetMin(a) << endl;
	}
	return 0;
} 
/*
10
[]
([])[]
((] 
([)] 
[][][][]]]]]]))(( 
))))([][]]]]]] 
([)(]) 
([[)[))] 
(])[ 
]]()[)(((] 
0
0
3
2
9
10
2
4
2
6

描述
给你一个字符串，里面只包含"(",")","[","]"四种符号，请问你需要至少添加多少个括号才能使这些括号匹配起来。
如：
[]是匹配的
([])[]是匹配的
((]是不匹配的
([)]是不匹配的
输入
第一行输入一个正整数N，表示测试数据组数(N<=10)
每组测试数据都只有一行，是一个字符串S，S中只包含以上所说的四种字符，S的长度不超过100
输出
对于每组测试数据都输出一个正整数，表示最少需要添加的括号的数量。每组测试输出占一行
样例输入
4
[]
([])[]
((]
([)]
*/
