#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
	int num = 0;
	long long x;
	set <long long> a;
	set <long long>::iterator it;
	a.insert(1);
	while (num < 1500)
	{
		it = a.begin();
		x = *it;
		a.insert(x<<1);
		a.insert(x*3);
		a.insert(x*5);
		a.erase(it);
		num ++;
		cout << x << endl;
	}
	cout << x << endl;
	return 0;
}
/*
我们把只包含因子2、3和5的数称作丑数,通常把1当做丑数，找到第1500个丑数 
*/
