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
dp[i][j] ��ʾһ���˴�i-1��ʼ����һ���˴�j-1��ʼ��һֱ��������ѶȺ�
��һ������Ϊmax{i, j}+1����t
dp[i][j] = min{dp[i][t]+abs(v[t-1]-v[j-1]), dp[j][t]+abs(val[t-1]-[j-1])} 
���ǵ�����λ�ÿ��Ի�����dp[i][j] == dp[j][i]
ֻ�迼��j>=i���� 
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
���ӣ�https://www.nowcoder.com/questionTerminal/fddf64d5757e41ec93f3ef0c0a10b891
��Դ��ţ����

СQ��ţ��ʿ�ϳ�һ�׸���,���׸�����n���������,ÿ��������һ����������ʾ��
����ÿ������Ҫô��СQ�ݳ�Ҫô��ţ��ʿ�ݳ�,����һϵ�������ݳ����Ѷȵ����������������仯����֮��, ����һ������������8, 8, 13, 12, ��ô�����Ѷȵ���|8 - 8| + |13 - 8| + |12 - 13| = 6(����||��ʾ����ֵ)��
����Ҫ�԰���n�����������СQ��ţ��ʿ,�������ݳ����Ѷ�֮����С,����������С���ѶȺ��Ƕ��١�
��������ʾ: СQѡ���ݳ�{5, 6}�Ѷ�Ϊ1, ţ��ʿѡ���ݳ�{1, 2, 1}�Ѷ�Ϊ2,�Ѷ�֮��Ϊ3,��һ������С�ѶȺ͵ķ����ˡ� 
��������:

�����������,��һ��һ��������n(1 �� n �� 2000) �ڶ���n������v[i](1 �� v[i] �� 10^6), ��ʾÿ��������


�������:

���һ������,��ʾСQ��ţ��ʿ�ݳ���С���ѶȺ��Ƕ��١�
ʾ��1
����

5
1 5 6 2 1
���

3
*/ 
