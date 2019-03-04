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

struct GOODS
{
	int x, v, zj;
	vector <int> iv;
}g[65];

int dp[3205];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i ++)
	{ 
		cin >> g[i].x >> g[i].v >> g[i].zj;
		g[i].x /= 10; 
	} 
	n /= 10;
	for (int i = 1; i <= m; i ++)
		if (g[i].zj)
			g[g[i].zj].iv.push_back(i);
	for (int i = 1; i <= m; i ++)
	{
		if (g[i].zj)
			continue;
		for (int j = n; j >= g[i].x; j --)
		{
			int num = g[i].iv.size();
			if (num == 0)
				dp[j] = max(dp[j-g[i].x]+g[i].x*g[i].v, dp[j]);
			else if (num == 1)
			{
				dp[j] = max(dp[j-g[i].x]+g[i].x*g[i].v, dp[j]);
				int t = g[i].iv[0];
				if (j-g[i].x-g[t].x >= 0)
					dp[j] = max(dp[j-g[i].x-g[t].x]+g[i].x*g[i].v+g[t].x*g[t].v, dp[j]);
			}
			else if (num == 2)
			{
				dp[j] = max(dp[j-g[i].x]+g[i].x*g[i].v, dp[j]);
				int t = g[i].iv[0];
				if (j-g[i].x-g[t].x >= 0)
					dp[j] = max(dp[j-g[i].x-g[t].x]+g[i].x*g[i].v+g[t].x*g[t].v, dp[j]);
				int t1 = g[i].iv[1];
				if (j-g[i].x-g[t1].x >= 0)
					dp[j] = max(dp[j-g[i].x-g[t1].x]+g[i].x*g[i].v+g[t1].x*g[t].v, dp[j]);
				if (j-g[i].x-g[t].x-g[t1].x >= 0)
					dp[j] = max(dp[j-g[i].x-g[t].x-g[t1].x]+g[i].x*g[i].v+g[t].x*g[t].v+g[t1].x*g[t].v, dp[j]);
			}
		}
	}
	cout << dp[n]*10 << endl;
	return 0;
}
/*
��Ŀ����
��ǿ����ܿ��ģ���˾����NԪ�����ս�����ǿ���������ս����ڹ�������������Ʒ��Ϊ���ࣺ�����븽���������Ǵ�����ĳ�������ģ��±����һЩ�����븽�������ӣ�
����	����
����	��ӡ����ɨ����
���	ͼ��
����	̨�ƣ��ľ�
������	��
���Ҫ�����Ϊ��������Ʒ����������ø���������������ÿ������������ 0 ���� 1 ���� 2 �����������������д������Լ��ĸ�������ǿ����Ķ����ܶ࣬Ϊ�˲�����Ԥ�㣬����ÿ����Ʒ�涨��һ����Ҫ�ȣ���Ϊ 5 �ȣ������� 1 ~ 5 ��ʾ���� 5 ������Ҫ���������������ϲ鵽��ÿ����Ʒ�ļ۸񣨶��� 10 Ԫ��������������ϣ���ڲ����� N Ԫ�����Ե��� N Ԫ����ǰ���£�ʹÿ����Ʒ�ļ۸�����Ҫ�ȵĳ˻����ܺ����
    ��� j ����Ʒ�ļ۸�Ϊ v[j] ����Ҫ��Ϊ w[j] ����ѡ���� k ����Ʒ���������Ϊ j 1 �� j 2 �������� j k ����������ܺ�Ϊ��
v[j 1 ]*w[j 1 ]+v[j 2 ]*w[j 2 ]+ �� +v[j k ]*w[j k ] �������� * Ϊ�˺ţ�
    ���������ǿ���һ������Ҫ��Ĺ��ﵥ��
 

��������:
����ĵ� 1 �У�Ϊ��������������һ���ո������N m
������ N �� <32000 ����ʾ��Ǯ���� m �� <60 ��Ϊϣ��������Ʒ�ĸ�������

�ӵ� 2 �е��� m+1 �У��� j �и����˱��Ϊ j-1 ����Ʒ�Ļ������ݣ�ÿ���� 3 ���Ǹ����� v p q

������ v ��ʾ����Ʒ�ļ۸� v<10000 ���� p ��ʾ����Ʒ����Ҫ�ȣ� 1 ~ 5 ���� q ��ʾ����Ʒ���������Ǹ�������� q=0 ����ʾ����ƷΪ��������� q>0 ����ʾ����ƷΪ������ q �����������ı�ţ�
 

�������:
 ����ļ�ֻ��һ����������Ϊ��������Ǯ������Ʒ�ļ۸�����Ҫ�ȳ˻����ܺ͵����ֵ�� <200000 ����
ʾ��1
����
1000 5
800 2 0
400 5 1
300 5 1
400 3 0
500 2 0
���
2200
*/
