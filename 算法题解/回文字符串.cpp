#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int t, i, j, l;
	string s;
	string a;
	scanf("%d", &t); 
	short dp[2][1005];
	while (t --)
	{
		cin >> s;
		memset(dp, 0, sizeof(dp));
		l = s.length();
		a = s;
		reverse(a.begin(), a.end());
		for (i = 0; i < l; i ++)
		{
			for (j = 0; j < l; j ++)
			{
				if (s[i] == a[j])
					dp[i&1][j+1] = dp[1-(i&1)][j]+1;
				else
					dp[i&1][j+1] = max(dp[i&1][j], dp[1-(i&1)][j+1]);
			}
		}
		printf("%d\n", l-dp[1-(l&1)][l]);
	}
	return 0;
}
/*
描述
所谓回文字符串，就是一个字符串，从左到右读和从右到左读是完全一样的，比如"aba"。当然，我们给你的问题不会再简单到判断一个字符串是不是回文字符串。现在要求你，给你一个字符串，可在任意位置添加字符，最少再添加几个字符，可以使这个字符串成为回文字符串。
输入
第一行给出整数N（0<N<100）
接下来的N行，每行一个字符串，每个字符串长度不超过1000.
输出
每行输出所需添加的最少字符数
样例输入
1
Ab3bd
样例输出
2

10
ahdflgajlskjgnkajdnflgjadlhfagjk
lajdfjaklnfdljndfjkgsladjfkag
asjdfgljskdfnakljdf'gijreiogesl
alrfhgoeirgmaklrgfmear
hrithwiuerglwirughslkjfg
jlhadfkyghskdyfgysdfguisehryigserhgysergiysegfvhksdfh
ayehgfusykerkysekfghhsfdhsudfgksydfgkusy
erughsjdfngjdfvbsiehguirhglsjefghlsudfkfsgs
shdfghieurhggierhgljksnfkjgnsltugsbiljerngiusbirubgisrtugstr
gugvksfhgurebgvienriugsnefbilueshgiusehrgliseubgiljsbnlisughnlisuhjgouiergilujsflsj
*/
