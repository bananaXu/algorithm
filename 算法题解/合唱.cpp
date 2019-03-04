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

#define M 2005
#define INF 0x3f3f3f3f
#define MIN(a, b) (a < b ? a : b)

/*
dp[i][j] 表示一个人从i-1开始，另一个人从j-1开始，一直到唱完的难度和
下一个音调为max{i, j}+1赋给t
dp[i][j] = min{dp[i][t]+abs(v[t-1]-v[j-1]), dp[j][t]+abs(val[t-1]-[j-1])} 
考虑到两人位置可以互换，dp[i][j] == dp[j][i]
只需考虑j>=i即可 
*/

int n;
int dp[M][M];
int val[M];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> val[i];
    for (int i = n; i >= 1; i --)
    {
        for (int j = n; j >= i; j --)
        {
            dp[i][j] = INF;
            dp[i][j] = min(dp[i][j], dp[i][j+1] + (j == 1 ? 0 : abs(val[j]-val[j-1])));
            dp[i][j] = min(dp[i][j], dp[j][j+1] + (i == 1 ? 0 : abs(val[j]-val[i-1])));
        }
    }
    cout << dp[1][1] << endl;
}
/*
链接：https://www.nowcoder.com/questionTerminal/fddf64d5757e41ec93f3ef0c0a10b891
来源：牛客网

小Q和牛博士合唱一首歌曲,这首歌曲由n个音调组成,每个音调由一个正整数表示。
对于每个音调要么由小Q演唱要么由牛博士演唱,对于一系列音调演唱的难度等于所有相邻音调变化幅度之和, 例如一个音调序列是8, 8, 13, 12, 那么它的难度等于|8 - 8| + |13 - 8| + |12 - 13| = 6(其中||表示绝对值)。
现在要对把这n个音调分配给小Q或牛博士,让他们演唱的难度之和最小,请你算算最小的难度和是多少。
如样例所示: 小Q选择演唱{5, 6}难度为1, 牛博士选择演唱{1, 2, 1}难度为2,难度之和为3,这一个是最小难度和的方案了。 
输入描述:

输入包括两行,第一行一个正整数n(1 ≤ n ≤ 2000) 第二行n个整数v[i](1 ≤ v[i] ≤ 10^6), 表示每个音调。


输出描述:

输出一个整数,表示小Q和牛博士演唱最小的难度和是多少。
示例1
输入

5
1 5 6 2 1
输出

3
*/ 
