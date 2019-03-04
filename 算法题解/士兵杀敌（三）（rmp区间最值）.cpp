#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a < b ? a : b

int n, x, y;
int k[100005];
int mm[100005][20], mi[100005][20];
// rmp�㷨
// dp[i][j]��ʾk[i]��k[i+(2^j)-1]����ֵ 
void rmq_isit()  
{  
	int i, j;
    for(i = 1; i <= n; i++)  
        mm[i][0] = mi[i][0] = k[i];  
    for(j = 1; (1<<j) <= n; j++)  
    {  
        for(i = 1; i+(1<<j)-1 <= n; i ++)  
        { 
            mm[i][j] = MAX(mm[i][j-1], mm[i+(1<<(j-1))][j-1]);  
            mi[i][j] = MIN(mi[i][j-1], mi[i+(1<<(j-1))][j-1]);  
        }  
    }  
}

int rmq(int l,int r)  
{  
    int k = 0;  
    k = (int)(log(y-x+1.0)/log(2.0));
    int ans1 = MAX(mm[l][k], mm[r-(1<<k)+1][k]);  
    int ans2 = MIN(mi[l][k], mi[r-(1<<k)+1][k]);  
    return ans1-ans2;  
}  

int main()
{
	int i, j, q;
	scanf("%d%d", &n, &q);
	for (i = 1; i <= n; i ++)
		scanf("%d", &k[i]);
	rmq_isit();
	for (i = 1; i <= q; i ++)
	{
		scanf("%d%d", &x, &y);
		printf("%d\n", rmq(x, y));
	}
	return 0;
} 
/*
����
�Ͻ���ͳ����N��ʿ����ʿ���ֱ���Ϊ1~N,�Ͻ�����������ĳһ�α����ɱ������ߵ�����ɱ������͵��˽��бȽϣ�����������˵�ɱ������ֵ�������ַ���һ�����ܹ���ɱ�����ߵ��ˣ���һ����Ҳ��������ɱ�����͵��ˣ����˺ܺõ�Ч����
���ԣ��Ͻ��������ʾ�ʦС����i��ʿ������j��ʿ���У�ɱ������ߵ�����ɱ������͵���֮�������ֵ�Ƕ��١�
���ڣ�����дһ�����򣬰�С���ش��Ͻ���ÿ�ε�ѯ�ʰɡ�
ע�⣬�Ͻ�������ѯ�ʺܶ�Ρ�
����
ֻ��һ���������
��һ������������N,Q������N��ʾʿ����������Q��ʾ�Ͻ���ѯ�ʵĴ�����(1<N<=100000,1<Q<=1000000)
����һ����N������Vi(0<=Vi<100000000)���ֱ��ʾÿ���˵�ɱ������
��֮���Q�У�ÿ��������������m,n����ʾ�Ͻ���ѯ�ʵ��ǵ�m��ʿ������n��ʿ����
���
����ÿ��ѯ�ʣ������m��ʿ������n��ʿ��֮������ʿ��ɱ���������ֵ����Сֵ�Ĳ
��������
5 2
1 2 6 9 3
1 2
2 4
�������
1
7
*/
