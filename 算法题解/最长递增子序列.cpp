#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int t, i, j, x;
	char a[128];
	char s[10005];
	scanf("%d", &t);
	while (t --)
	{
		scanf("%s", &s);
		memset(a, 0, sizeof(a));
		for (i = 0; i < strlen(s); i ++)
		{
			x = a[s[i]-1]+1;
			for (j = s[i]; j <= 127 && a[j] < x; j ++)
			{
				a[j] = x;
			}
		}
		printf("%d\n", a[127]);
	}
	return 0;
} 
