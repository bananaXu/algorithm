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

int main()
{
	int t;
	scanf("%d", &t);
	while (t --)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		int sum = 0;
		for (int i = 1; i <= n; i ++)
		{
			int x;
			scanf("%d", &x);
			sum ^= (x-1)/(m-1);
		}
		if (sum)
			printf("Win\n");
		else
			printf("Lose\n");
	}
	return 0;
}
/*
��ʯ������
ʱ�����ƣ�2000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�6
����
�������£�zyc������һ����Ϸ���з�ʯ����Ϸ����ʼ��D��ʯ�ӣ�ÿ��ʯ�ӵ�������֪��

������������ʯ�ӣ�����ѡȡ��D��ʯ���е�����һ�ѣ�Ȼ���ѡ�е����ʯ�ӷֳ�M�ѣ�ÿ��ʯ���������������0��������ʯ�ӵĶ��������D+M-1�ѣ��Է��Ϳ�������D+M-1��ʯ��������ѡһ�ѷֳ�M�ѣ����η���ȥ��ֱ��ĳ���޷�ִ�����ֲ���ʱ���޷�ִ�в�������������ⳡ��Ϸ��

�������Ϸ��˫�����ǳ����������ڸ���һ����ʼ״̬�������ж��ȷ�ʯ�ӵ����ǻ�ȡʤ���ǻ�ʧ�ܡ�

����
��һ����һ������T����ʾ�������ݵ�������T<=10)
ÿ��������ݵĵ�һ������������D,M(0<D<100,2<=M<=7)
����һ����D��������Ni(Ni<100),��ʾÿ��ʯ�ӵĳ�ʼ������
���
����ȷ�ʯ�ӵ��˻�ʤ�����Win
�������Lose
��������
2
1 3
5
2 3
5 6
�������
Win
Lose
*/
