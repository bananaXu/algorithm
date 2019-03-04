#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdio>
#include <string>
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
#include <list>
#include <cstdlib>
#include <bitset>
#include <sstream>
using namespace std;

void getnext(string s, vector <int> &next)
{
	next[0] = -1;
	for (int i = 1; i < s.length(); i ++)
	{
		int k = next[i-1];
		while (k != -1 && s[i-1] != s[k]) k = next[k];
		next[i] = k+1; 
	}
	for (int i = 1; i < s.length(); i ++)
		if (s[i] == s[next[i]]) 
			next[i] = next[next[i]];
}

int KMP(string a, string b, vector <int> &next)
{
	int la = a.length(), lb = b.length();
	if (la < lb)
		return -1;
	int i = 0, j = 0, MaxNum = la-lb;
	while (1)
	{
		if (i-j > MaxNum)
			return -1;
		if (a[i] == b[j])
		{
			if (j == lb-1)
				return i-j;
			i ++;
		 	j ++;
		}
		else
		{
			if (next[j] == -1)
			{
				i ++;
				j = 0;
			}
			else
				j = next[j];
		}
	}
}

int main() 
{
	string a = "hu6hj6jhu76rjh6jujrhj", b = "j6j";
	vector <int> next(b.length());
	getnext(b, next);
	int t = KMP(a, b, next);
	cout << t << endl;
	return 0;
}
