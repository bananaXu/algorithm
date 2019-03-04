#include <iostream>
#include <algorithm>
using namespace std;

int GCD(int a, int b)
{
	if (a < b)
		swap(a, b);
	if (b == 0)
		return a;
	return GCD(a%b, b);
} 

int main()
{
	int a, b, c, d, gcd, l, r, mem, den;
	char abolish, o;
	while(!cin.eof())
	{
		cin >> a >> abolish >> b >> o >> c >> abolish >> d;
		gcd = GCD(b, d);
		l = b/gcd;
		r = d/gcd;
		den = b/gcd*d;
		if (o == '-')
			mem = a*r - c*l;
		else
			mem = a*r + c*l;
		gcd = GCD(den, abs(mem));
		den /= gcd;
		mem /= gcd;
		if (mem == 0)
			cout << 0 << endl;
		else if(mem == den)
	 		cout << 1 << endl;
		else if (den == 1)
			cout << mem << endl;
		else
			cout << mem << "/" << den << endl; 
	}
	return 0;
} 
