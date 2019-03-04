#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

double calc()
{
	char s[10];
	if(!~scanf("%s", &s))
		exit(0);
	switch (*s)
	{
		case '+': return calc()+calc();
		case '-': return calc()-calc();
		case '*': return calc()*calc();
		case '/': return calc()/calc();
		default: return atof(s);
	}
}

int main()
{
	while(1)
	{
		printf("%.2f\n", calc());
	}
	return 0;
}
