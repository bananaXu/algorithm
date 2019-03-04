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

const int MOD = 1e9+7;
/*
算法思想:
4x+3 = 2(2x+1)+1;
8x+7 = 2(2(2x+1)+1)+1;
那么就不断x = (2x+1)%MOD，直到x == 0或者次数超过上限 
*/

int main()
{
	int n;
	cin >> n;
	int i;
	for (i = 1; i <= 300000; i ++)
	{
		n = (n<<1|1)%MOD;
		if (!n)
			break;
	}
	i  = (i+2)/3;
	cout << (i == 100001 ? -1 : i) << endl;
	return 0;
}
/*
小易总是感觉饥饿，所以作为章鱼的小易经常出去寻找贝壳吃。最开始小易在一个初始位置x_0。对于小易所处的当前位置x，他只能通过神秘的力量移动到 4 * x + 3或者8 * x + 7。因为使用神秘力量要耗费太多体力，所以它只能使用神秘力量最多100,000次。贝壳总生长在能被1,000,000,007整除的位置(比如：位置0，位置1,000,000,007，位置2,000,000,014等)。小易需要你帮忙计算最少需要使用多少次神秘力量就能吃到贝壳。
输入描述:
输入一个初始位置x_0,范围在1到1,000,000,006
输出描述:
输出小易最少需要使用神秘力量的次数，如果使用次数使用完还没找到贝壳，则输出-1
示例1
输入
125000000
输出
1
*/