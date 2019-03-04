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
ll dp1[55][55], dp2[55][55]; // dp1[i][j] 表示到第i个选择j个数相邻差不超过d相乘的最大乘积 

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

有 n 个学生站成一排，每个学生有一个能力值，牛牛想从这 n 个学生中按照顺序选取 k 名学生，要求相邻两个学生的位置编号的差不超过 d，使得这 k 个学生的能力值的乘积最大，你能返回最大的乘积吗？ 
输入描述:

每个输入包含 1 个测试用例。每个测试数据的第一行包含一个整数 n (1 <= n <= 50)，表示学生的个数，接下来的一行，包含 n 个整数，按顺序表示每个学生的能力值 ai（-50 <= ai <= 50）。接下来的一行包含两个整数，k 和 d (1 <= k <= 10, 1 <= d <= 50)。


输出描述:

输出一行表示最大的乘积。
示例1
输入

3
7 4 7
2 50
输出

49
*/
