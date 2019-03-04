#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct C
{
	int a;
	int b;
	bool operator<(const struct C &m)const
	{
		if (this->a < m.a)
			return true;
		else if (this->a > m.a)
			return false;
		else
			return this->b < m.b;
	}
};

int main()
{
	int i;
	C b;
	set <C>a;
	set <C>::iterator it;
	for (i = 1; i <= 4; i ++)
	{
		cin >> b.a >> b.b;
		a.insert(b);
	}
	for (it = a.begin(); it != a.end(); ++ it)
	{
		cout << (*it).a << (*it).b << endl;
	}
	return 0;
}
