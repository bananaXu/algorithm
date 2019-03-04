#include <iostream>
#include <iomanip>
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
#include <list>
using namespace std;

#define M 1005

int dp[M][M];

int main()
{
	string s;
	while(cin >> s)
	{
		string a = s;
		reverse(a.begin(), a.end());
		int len = s.length();
		dp[0][0] = dp[0][1] = dp[1][0] = 0;
		for (int i = 0; i < len; i ++)
		{
			for (int j = 0; j < len; j ++)
			{
				if (s[i] == a[j])
					dp[i+1][j+1] = dp[i][j]+1;
				else
					dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
			}
		}
		cout << len-dp[len][len] << endl;
	}
	return 0;
}
