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

int main() 
{
	int n, m;
	while (~scanf("%d%d", &n, &m))
	{
		if (n > m)
			swap(n, m);
		int t = m-n;
		int l = (int)((sqrt(5.0)+1)/2*t);
		if (n == l)
			printf("0\n");
		else
			printf("1\n");
	}
	return 0;
}
