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

string s[10005];

bool match(int i, string a)
{
	int lena = a.length();
	int lens = s[i].length();
	if (abs(lena - lens) > 1)
		return false;
	for (int j = 0; j < lena; j ++)
	{
		if (a[j] != s[i][j])
		{
			if (lena == lens && a.substr(j+1, string::npos) == s[i].substr(j+1, string::npos))
				return true;
			if (lena > lens && a.substr(j+1, string::npos) == s[i].substr(j, string::npos))
				return true;
			if (lena < lens && a.substr(j, string::npos) == s[i].substr(j+1, string::npos))
				return true;
			return false;
		}
		if (j == lena-1)
			return true;
	}
	return false;
}

int main()
{	
	int I = -1;
	while (1)
	{
		cin >> s[++ I];
		if (s[I] == "#")
			break;
	}
	while (1)
	{
		string a;
		cin >> a;
		if (a == "#")
			break;
		bool find = false;
		for (int i = 0; i < I && !find; i ++)
			if (s[i] == a)
			{
				cout << a << " is correct" << endl;
				find = true;
			}
		if (find)
			continue;
		cout << a << ":";
		for (int i = 0; i < I; i ++)
			if (match(i, a))
				cout << " " << s[i];
		cout << endl;
	}
	return 0;
} 
/*
题目大意：
输入一些单词作为词典
再输入一些单词在词典中查找匹配
如果找到，输出：该单词+ is correct 
如果未找到，找出所有下列匹配：删除一个字母，替换一个字母，增加一个字母
样例输入
i
is
has
have
be
my
more
contest
me
too
if
award
#
me
aware
m
contest
hav
oo
or
i
fi
mre
#
样例输出
me is correct
aware: award
m: i my me
contest is correct
hav: has have
oo: too
or:
i is correct
fi: i
mre: more me 
*/
