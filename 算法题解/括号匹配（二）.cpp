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
	// dp[i][j]����s[i..j]������С�����,��Ȼdp[i][i]=1 
	for (i = 0; i < len; i ++)
	{
		dp[i][i] = 1;
	}
	// ���s[i] == s[j] dp[i][j] = {MAX(dp[i+1][j-1], dp[i][k]+dp[k+1][j])(i<=k<j)} 
	// ���s[i] ��= s[j] dp[i][j] = {MAX(dp[i][k]+dp[k+1][j])(i<=k<j)}
	// ����dp[i][k]+dp[k+1][j]�漰������С��i-j��dp,�����Գ���Ϊ��һ��ѭ�� 
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
		// ���Ƚ�[]��()ȫ���ų����Ż��ṹ 
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

����
����һ���ַ���������ֻ����"(",")","[","]"���ַ��ţ���������Ҫ������Ӷ��ٸ����Ų���ʹ��Щ����ƥ��������
�磺
[]��ƥ���
([])[]��ƥ���
((]�ǲ�ƥ���
([)]�ǲ�ƥ���
����
��һ������һ��������N����ʾ������������(N<=10)
ÿ��������ݶ�ֻ��һ�У���һ���ַ���S��S��ֻ����������˵�������ַ���S�ĳ��Ȳ�����100
���
����ÿ��������ݶ����һ������������ʾ������Ҫ��ӵ����ŵ�������ÿ��������ռһ��
��������
4
[]
([])[]
((]
([)]
*/
