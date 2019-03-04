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

typedef long long ll;

int main()
{
	int t;
	scanf("%d", &t);
	while (t --)
	{
		int n;
		int p[7];
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++)
			scanf("%d", &p[i]);
		double sum = 0;
		for (int i = 1; i <= n; i ++)
		{
			double t = 1;
			for (int j = 1; j <= n; j ++)
			{
				if (i == j)
					continue;
				t = t*(n+1-j)/(i-j);
			}
			sum += t*p[i];
		}
		printf("%lld\n", (ll)sum);
	}
	return 0;
}
/*
�ҹ���
ʱ�����ƣ�1000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�4
����
���һ������������Ŀ������һЩ�����ҳ���Щ��֮��Ĺ��ɣ�д����һ������ù��ɵ�����

���磺2 5 10 17 26������Կ�����Щ������n*n+1���ͨ�ʽ������һ����Ϊ37��

����ͨ�ʽ��ֻһ�������Դ��ǲ�Ψһ�ġ��������֪��N����������֪��ͨ�ʽ��һ������С��N�Ķ���ʽ����𰸾�Ψһȷ���ˡ�

���ڸ���һ�����У����ҳ����ɲ��������һ����Ϊ���٣�

����
��һ����һ������T��ʾ�������ݵ�����(T<=20)
ÿ��������ݵĵ�һ����һ������N��1<=N<=5)
����һ����N������,��ʾ��������֪�˵�N������(��N��������ֵ��������1000)��
���
������Ϲ��ɵ���һ����
��������
2
2
1 2
5
2 5 10 17 26
�������
3
37
*/
