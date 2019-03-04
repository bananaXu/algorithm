#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

// meet[i][j]表示i能遇到j
// 刚开始一定能和旁边的相遇
// 如果i能遇到x并且x能遇到j，那么i打败x或j打败x则i，j一定能相遇
// 如果经过一圈i遇到自己说明i能赢 
int main()
{
	int i, j, t, n, d, sum, start, mid, end;
	int beat[505][505];
	bool meet[505][505];
	scanf("%d", &t);
	while (t --)
	{
		scanf("%d", &n);
		memset(meet, false, sizeof(meet));
		for (i = 0; i < n; i ++)
		{
			for (j = 0; j < n; j ++)
				scanf("%d", &beat[i][j]);
		}
		for (i = 0; i < n; i ++)
		{
			meet[i][(i+1)%n] = true;
		}
		for (d = 2; d <= n; d ++)
		{
			for (i = 0; i < n; i ++)
			{
				start = i; end = (d+i)%n;
				for (j = i+1; j <= d+i-1; j ++)
				{
			 		mid = j%n;
					if (meet[start][mid] && meet[mid][end] && (beat[start][mid] || beat[end][mid]))
					{
						meet[start][end] = true;
						break;
					}
				}
			}
		}
		sum = 0;
		for (i = 0; i < n; i ++)
		{
			if (meet[i][i])
				sum ++;
		}
		printf("%d\n", sum);
	} 
	return 0;
} 
/*
描述
在路易十三和红衣主教黎塞留当权的时代，发生了一场决斗。n个人站成一个圈，依次抽签。抽中的人和他右边的人决斗，负者出圈。这场决斗的最终结果关键取决于决斗的顺序。现书籍任意两决斗中谁能胜出的信息，但“A赢了B”这种关系没有传递性。例如，A比B强，B比C强，C比A强。如果A和B先决斗，C最终会赢，但如果B和C决斗在先，则最后A会赢。显然，他们三人中的第一场决斗直接影响最终结果。

假设现在n个人围成一个圈，按顺序编上编号1~n。一共进行n-1场决斗。第一场，其中一人（设i号）和他右边的人（即i+1号，若i=n，其右边人则为1号）。负者被淘汰出圈外，由他旁边的人补上他的位置。已知n个人之间的强弱关系（即任意两个人之间输赢关系）。如果存在一种抽签方式使第k个人可能胜出，则我们说第k人有可能胜出，我们的任务是根据n个人的强弱关系，判断可能胜出的人数。

输入
第一行是一个整数N(1<=N<=20)表示测试数据的组数。
第二行是一个整数n表示决斗的总人数。(2<=n<=500)
随后的n行是一个n行n列的矩阵，矩阵中的第i行第j列如果为1表示第i个人与第j个人决斗时第i个人会胜出，为0则表示第i个人与第j个人决斗时第i个人会失败。
输出
对于每组测试数据，输出可能胜出的人数，每组输出占一行
样例输入
1
3
0 1 0
0 0 1
1 0 0
样例输出
3
*/
