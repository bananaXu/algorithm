#include <iostream>
#include <algorithm>
using namespace std;

string s;

void input()
{
	cin >> s;
}

void rev(int i, int j)
{
	int k;
	for (k = i; k <= (i+j-1)>>1; k ++)
	{
		swap(s[k], s[i+j-k]);
	}
}

bool nextpermutation()
{
	int len = s.length();
	int i, j;
	i = len-2;
	j = len-1;
	while (i && s[i] >= s[i+1]) i --;
	if (s[i] < s[i+1])
	{
		while(s[j] <= s[i]) j --;
		swap(s[i], s[j]);
		rev(i+1, len-1);
		return true;
	}
	return false;
}

void output()
{
	int num = 1;
	cout << s << endl;
	while (nextpermutation())
	{
		num ++;
		cout << s << endl;
	}
	cout << num << endl;
}

int main()
{
	input();
	output();
	return 0;
} 
