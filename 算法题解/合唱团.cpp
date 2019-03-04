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

#define INF 0x3f3f3f3f
typedef long long ll;
#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a < b ? a : b

int a[55];
ll dp1[55][55], dp2[55][55]; // dp1[i][j] ��ʾ����i��ѡ��j�������ڲ����d��˵����˻� 

int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		for (int i = 1; i <= n; i ++)
			scanf("%d", &a[i]);
		int k, d;
		scanf("%d%d", &k, &d);
		memset(dp1, 0, sizeof(dp1));
		memset(dp2, 0, sizeof(dp2));
		for (int i = 1; i <= n; i ++)
			dp1[i][1] = dp2[i][1] = a[i];
		for (int i = 1; i <= n; i ++)
		{
			for (int j = 2; j <= k && j <= i; j ++)
			{
				for (int l = i-1; l >= j-1 && i-l <= d; l --)
				{
					ll x = dp1[l][j-1]*a[i], y = dp2[l][j-1]*a[i];
					dp1[i][j] = max(dp1[i][j], max(x, y));
					dp2[i][j] = min(dp2[i][j], min(x, y));
				}
			}
		} 
		ll Max = -INF;
		for (int i = k; i <= n; i ++)
			Max = max(Max, dp1[i][k]);
		printf("%lld\n", Max);
//		cout << LONG_LONG_MAX << endl;
	}
	return 0;
}
/*

�� n ��ѧ��վ��һ�ţ�ÿ��ѧ����һ������ֵ��ţţ����� n ��ѧ���а���˳��ѡȡ k ��ѧ����Ҫ����������ѧ����λ�ñ�ŵĲ���� d��ʹ���� k ��ѧ��������ֵ�ĳ˻�������ܷ������ĳ˻��� 
��������:

ÿ��������� 1 ������������ÿ���������ݵĵ�һ�а���һ������ n (1 <= n <= 50)����ʾѧ���ĸ�������������һ�У����� n ����������˳���ʾÿ��ѧ��������ֵ ai��-50 <= ai <= 50������������һ�а�������������k �� d (1 <= k <= 10, 1 <= d <= 50)��


�������:

���һ�б�ʾ���ĳ˻���
ʾ��1
����

3
7 4 7
2 50
���

49
*/
