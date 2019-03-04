#include <iostream>
using namespace std;

int a[10001] = {0};

void cz()
{
	for(int i = 0; i <= 10000; i ++)
	{
		a[i] = 0;
	}
} 

void input()
{
	string s;
	int i, len;
	cin >> s;
	len = s.length();
	cz();
	for(i = 0; i < len; i ++)
	{
		a[len-i] = s[i]-'0';
	}
}

void jia(int x)
{
	int i = 0;
	a[1] += x;
	while (a[++i] >= 10)
	{
		a[i+1] += a[i]/10;
		a[i] %= 10;
	}
}

void chen(int x)
{
	int i, num;
	for(i = 10000; i >= 0; i --)
	{
		if(a[i] != 0)
		{
			num = i;
			break;
		}
	}
	for (i = 1; i <= num; i ++)
	{
		a[i] *= x;
	}
	for(i = 1; i <= num; i ++)
	{
		if(a[i] >= 10)
		{
			a[i+1] += a[i]/10;
			a[i] %= 10;
		}
	}
	i = num;
	while (a[++ i] >= 10)
	{
		a[i+1] += a[i]/10;
		a[i] %= 10;
	}
}

int chu(int x)
{
	int i, num;
	for(i = 10000; i >= 0; i --)
	{
		if(a[i] != 0)
		{
			num = i;
			break;
		}
	}
	for(i = num; i >= 1; i --)
	{
		a[i-1] += a[i]%x*10;
		a[i] /= x;
	}
	return a[0]/10;
}

void jian(int x)
{
	int i = 0;
	a[1] -= x;
	while(a[++i] < 0)
	{
		if (a[i]%10 == 0)
		{
			a[i+1] += a[i]/10;
			a[i] = 0;
		}
		else
		{
			a[i+1] += a[i]/10-1;
			a[i] = 10+a[i]%10; 
		}
	}
}

void output()
{
	int i, num;
	for(i = 10000; i >= 0; i --)
	{
		if(a[i] != 0)
		{
			num = i;
			break;
		}
	}
	for(i = num; i >= 1; i --)
	{
		cout << a[i];
	}
	cout << endl;
}

void jiechen(int x, int y)
{
	int i;
	cz();
	a[1] = 1;
	for(i = 1; i <= y; i ++)
	{
		chen(x);
	}
}

int main()
{
	// 大数加减乘除一般数，大数每个操作运算前需大于0， 
	jiechen(49, 100); // 阶乘 ，使用前会清空数组 
	output();
	input();
	output();
	chen(12436);
	output();
	return 0;
} 
