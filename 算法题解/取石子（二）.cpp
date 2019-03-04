#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <cmath>
#include <vector> 
#include <queue>
#include <ctype.h>
#include <map>
#include <cfloat>
using namespace std;

typedef long long ll;

int main()
{
	int t;
	scanf("%d", &t);
	while (t --)
	{
		int i, n;
		scanf("%d", &n);
		ll m = 0;
		for (i = 1; i <= n; i ++)
		{
			ll x, y;
			scanf("%lld%lld", &x, &y);
			x %= (y+1);
			m ^= x;
		}
		if (!m)
			printf("Lose\n");
		else
			printf("Win\n");
	}
	return 0;
}
/*
取石子（二）
时间限制：3000 ms  |  内存限制：65535 KB
难度：5
描述
小王喜欢与同事玩一些小游戏，今天他们选择了玩取石子。

游戏规则如下：共有N堆石子，已知每堆中石子的数量，并且规定好每堆石子最多可以取的石子数（最少取1颗）。

两个人轮流取子，每次只能选择N堆石子中的一堆，取一定数量的石子(最少取一个），并且取的石子数量不能多于该堆石子规定好的最多取子数，等哪个人无法取子时就表示此人输掉了游戏。

假设每次都是小王先取石子，并且游戏双方都绝对聪明，现在给你石子的堆数、每堆石子的数量和每堆石子规定的单次取子上限，请判断出小王能否获胜。

输入
第一行是一个整数T表示测试数据的组数(T<100)
每组测试数据的第一行是一个整数N(1<N<100),表示共有N堆石子，随后的N行每行表示一堆石子，这N行中每行有两个数整数m,n表示该堆石子共有m个石子，该堆石子每次最多取n个。(0<=m,n<=2^31)
输出
对于每组测试数据，输出Win表示小王可以获胜，输出Lose表示小王必然会败。
样例输入
2
1
1000 1
2
1 1
1 1
样例输出
Lose
Lose
*/
