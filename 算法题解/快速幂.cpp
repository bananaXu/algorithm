#include <iostream>
using namespace std;

int main()
{
	//	¼ÆËãa^b%c
	int a, b, c;
	cin >> a >> b >> c;
	int ans = 1;
	while(b)
	{
		if(b&1)
			ans = ans*a%c;
		b >>= 1;
		a = (a*a)%c;
	}
	cout << ans << endl;
	return 0;
}
