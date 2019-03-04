#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define S sqrt(5.0)

int main()
{
	int t, m;
	cin >> t;
	while (t --)
	{
		cin >> m;
		cout << floor(1/S*pow((1+S)/2, m)-pow((1-S)/2, m)+0.5) << endl;
	} 
	return 0;
} 
