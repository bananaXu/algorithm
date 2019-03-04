#include <iostream>
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

using namespace std;

int main()
{
	while (1)
	{
		int n;
		scanf("%d", &n);
		if (!n)
			break;
		int pre, now, differ, Index = 0;
		int a[] = {1, -1, 0, 1, -1};
		bool ok = true;
		scanf("%d", &pre);
		for (int i = 1; i < n; i ++)
		{
			scanf("%d", &now);
			if (ok)
			{
				int t = now-pre;
				pre = now;
				if (i == 1)
				{
					differ = t;
					if(differ <= 0)
						ok = false;
					continue;
				}
				if (t == differ)
					continue;
				if (Index == 4)
				{
					ok = false;
					continue;
				}
				if (a[++ Index] == 0)
				{
					if (t == 0)
						differ = 0;
					else if (t > 0)
					{
						differ = t;
						Index ++;
					}
					else
						ok = false;
					continue;
				}
				if (a[Index] != 0 && a[Index]*t > 0)
				{
					differ = t;
					continue;
				}
				ok = false;
			}
		}
		if (ok && Index == 4)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
// 题目大意：数组0~a递增a~b递减b~c相等c~d递增d~e递减，并且b可以等于c，其他不能相等 
