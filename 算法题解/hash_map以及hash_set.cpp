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
#include <ext/hash_map>
#include <ext/hash_set>
using namespace std;
using namespace __gnu_cxx;

int main()
{
	srand(time(0));
	hash_map <int, int> m;
	hash_map <int, int>::iterator it;
	for (int i = 1; i <= 10; i ++)
	{
		int x = rand()%100, y = rand()%100;
		m[x] = y;
	}
	m[101] = 21;
	for (int i = 1; i <= 1000; i ++)
	{
		int t = rand()%10;
		m[101] += t;
	}
	for (it = m.begin(); it != m.end(); it ++)
		cout << (*it).first << " " << (*it).second << endl;
	cout << m[101] << endl;
	
	cout << endl;
	hash_set <int> is;
	hash_set <int>::iterator ist;
	for (int i = 1; i <= 10; i ++)
	{
		int t = rand()%100;
		is.insert(t);
	}
	for (ist = is.begin(); ist != is.end(); ist ++)
		cout << *ist << " ";
	cout << endl;
	return 0;
}
