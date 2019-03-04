#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int main()
{
	string s, ss;
	int a[12];
	int f[12] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 
				362880, 3628800, 39916800};
	int i, n, m;
	scanf("%d", &n);
	while (n --)
	{
		scanf("%d", &m);
		m --;
		for (i = 11; i >= 0; i --)
		{
			if (m >= f[i])
			{
				a[i] = m/f[i];
				m %= f[i];
			}
			else
			{
				a[i] = 0;
			}
		}
		s = "abcdefghijkl";
		ss = "";
		for (i = 11; i >= 0; i --)
		{
			ss += s[a[i]];
			s.erase(a[i], 1);
		}
		cout << ss << endl;
	}
	return 0;
}
