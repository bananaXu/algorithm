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
����
���ǾͲ�����Ĩ���ˣ����⣬��Ҫ�����ľ���дһ�����򣬵ó�����������С�
tip�������������Ҳ����������Ӵ�(��Ҫ������)��Ӣ����дΪLCS��Longest Common Subsequence�����䶨���ǣ�һ������ S ������ֱ�������������֪���е������У��������з��ϴ�������������ģ��� S ��Ϊ��֪���е�����������С�
����
��һ�и���һ������N(0<N<100)��ʾ������������
������ÿ���������У��ֱ�Ϊ����������ַ�����ÿ���ַ������Ȳ�����1000.
���
ÿ������������һ����������ʾ����������г��ȡ�ÿ����ռһ�С�
��������
2
asdf
adfsd
123abc
abc123abc
�������
3
6
*/
