#include <iostream>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	// n! = sqrt(2¦Ð)*n^(n+1/2)*e^(-n)
	double PI=acos(-1.0),e=exp(1.0);
	int t, n;
	cin >> t;
	while (t --)
	{
		cin >> n;
		cout << (int)(log10(sqrt(2*PI*n))+n*log10(n/e))+1 << endl;
	}
	return 0;
}
