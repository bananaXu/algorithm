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

int getnum(char c)
{
	if (c >= 'A' && c <= 'E')
		return c-'A';
	return 5;
}

int main()
{
	string s;
	while (cin >> s)
	{
		int len = s.length();
		int Min = INF;
		int l = 0;
		int a[6];
		memset(a, 0, sizeof(a));
		for (int i = 0; i < (len<<1); i ++)
		{
			if (!(a[0] && a[1] && a[2] && a[3] && a[4]))
			{
				l ++;
				int t = getnum(s[i%len]);
				a[t] ++;
			}
			if (a[0] && a[1] && a[2] && a[3] && a[4])
			{
				while (a[0] && a[1] && a[2] && a[3] && a[4])
				{
					Min = min(Min, l);
					int t = getnum(s[(i-l+1+len)%len]);
					a[t] --;
					l --;
				}
			}
		}
		cout << len-Min << endl;
	}
	return 0;
}
/*
��Ŀ����
��һ����ɫ��ʯ���������ɺܶ��ֲ�ͬ�ı�ʯ��ɵģ������챦ʯ������ʯ����ʯ����䣬����ȡ���һ������������ʹ͸���һ��ѧ�ߣ�������˵������Դ����������������������ϲ���챦ʯ������ʯ����ˮ����������ʯ�����֣���Ҫ��������н�ȡ������һС�λ����ң���һ���б���������е������ֱ�ʯ��ʣ�µĲ�������Դ��ߡ�����޷��ҵ���һ��Ҳ�޷����ߡ������ѧ���ҳ�����з��������ܹ��õ����ı�ʯ��
��������:
������ÿ���ַ�����һ�ֱ�ʯ��A��ʾ�챦ʯ��B��ʾ����ʯ��C������ˮ����D������䣬E������ʯ��F������ʯ��G�������ȵȣ�������һ��ȫ��Ϊ��д��ĸ���ַ����б�ʾ�����ı�ʯ���У�ע����������β��ӵġ�ÿ�д���һ�������
�������:
���ѧ���ܹ��õ������ı�ʯ������ÿ��һ��
ʾ��1
����

ABCYDYE
ATTMBQECPD
���

1
3
*/
