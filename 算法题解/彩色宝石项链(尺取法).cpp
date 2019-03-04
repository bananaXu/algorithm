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

#define INF 0x3f3f3f3f

int getnum(char c)
{
	if (c >= 'A' && c <= 'E')
		return c-'A';
	return 5;
}

int main()
{
	string s;
	while (cin >> s)
	{
		int len = s.length();
		int Min = INF;
		int l = 0;
		int a[6];
		memset(a, 0, sizeof(a));
		for (int i = 0; i < (len<<1); i ++)
		{
			if (!(a[0] && a[1] && a[2] && a[3] && a[4]))
			{
				l ++;
				int t = getnum(s[i%len]);
				a[t] ++;
			}
			if (a[0] && a[1] && a[2] && a[3] && a[4])
			{
				while (a[0] && a[1] && a[2] && a[3] && a[4])
				{
					Min = min(Min, l);
					int t = getnum(s[(i-l+1+len)%len]);
					a[t] --;
					l --;
				}
			}
		}
		cout << len-Min << endl;
	}
	return 0;
}
/*
题目描述
有一条彩色宝石项链，是由很多种不同的宝石组成的，包括红宝石，蓝宝石，钻石，翡翠，珍珠等。有一天国王把项链赏赐给了一个学者，并跟他说，你可以带走这条项链，但是王后很喜欢红宝石，蓝宝石，紫水晶，翡翠和钻石这五种，我要你从项链中截取连续的一小段还给我，这一段中必须包含所有的这五种宝石，剩下的部分你可以带走。如果无法找到则一个也无法带走。请帮助学者找出如何切分项链才能够拿到最多的宝石。
输入描述:
我们用每种字符代表一种宝石，A表示红宝石，B表示蓝宝石，C代表紫水晶，D代表翡翠，E代表钻石，F代表玉石，G代表玻璃等等，我们用一个全部为大写字母的字符序列表示项链的宝石序列，注意项链是首尾相接的。每行代表一种情况。
输出描述:
输出学者能够拿到的最多的宝石数量。每行一个
示例1
输入

ABCYDYE
ATTMBQECPD
输出

1
3
*/
