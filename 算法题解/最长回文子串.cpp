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

vector <int> rad;

int getlen(string a)
{
	string s = ".#";
	for (int i = 0; i < a.length(); i ++)
	{
		s += a[i];
		s += "#";
	}
	s += "*";
	int len = s.length();
	rad.resize(len, 0);
	int Max = 0;
	for (int i = 1, j = 0, k = 0; i < len; i += k)
	{
		while (s[i-j-1] == s[i+j+1])
			j ++;
		rad[i] = j;
		Max = max(Max, j);
		for (k = 1; k < rad[i] && rad[i]-k != rad[i-k]; k ++)
			rad[i+k] = min(rad[i-k], rad[i]-k);
		j = max(0, rad[i]-k);
	}
	return Max;
}

int main()
{
	string s;
	while (cin >> s)
		cout << getlen(s) << endl;
	return 0;
}
