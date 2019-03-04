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

string a[] = {"billion", "million", "thousand", "hundred"};
string b[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", 
              "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
			  "eighteen", "nineteen"};
string c[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
vector <string> v;
vector <string>::iterator it;

void Trans(int t)
{
	if (t >= 100)
	{
		v.push_back(b[t/100]);
		v.push_back(a[3]);	
		t %= 100;
		if (t)
			v.push_back("and");
	}
	if (!t)
		return;
	if (t < 20)
	{
		v.push_back(b[t]);
		return;
	}
	v.push_back(c[t/10-2]);
	t %= 10;
	if (!t)
		return;
	v.push_back(b[t]); 
}

int main()
{
	int n;
	while (cin >> n)
	{
		v.clear();
		if (n >= 1e9)
		{
			v.push_back(b[n/(int)1e9]);
			v.push_back(a[0]);
			n %= (int)1e9;
		}
		if (n >= 1e6)
		{
			int t = n/(int)1e6;
			Trans(t);
			v.push_back(a[1]);
			n %= (int)1e6;
		}
		if (n >= 1000)
		{
			int t = n/1000;
			Trans(t);
			v.push_back(a[2]);
			n %= 1000;
		}
		Trans(n);
		for (it = v.begin(); it != v.end(); it ++)
		{
			if (it != v.begin())
				cout << " ";
			cout << *it;
		}
		cout << endl;
	}
	return 0;
}
