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

string s[205];
int n = 0;
map <string, int> Map;

void TOD(int l, int r, int t)
{
	while (t --)
	{
		for (int i = l; i <= r; i ++)
		{
			int x, len = s[i].length();
			if (len > 6 && s[i].substr(0, 5) == "Loop(")
			{
				int j = i, z = 1;
				while (z)
				{
					if (s[++ j].length() > 6 && s[j].substr(0, 5) == "Loop(")
						z ++;
					else if (s[j] == "End")
						z --;
				}
				TOD(i+1, j-1, Map[s[i].substr(5, len-6)]);
				i = j;
			}
			else if (s[i].substr(len-2, 2) == "++")
				Map[s[i].substr(0, len-2)] ++;
			else if (s[i] == "show")
			{
				i ++;
				printf("%d\n", Map[s[i]]);
			}
			else
			{
				if (s[i][len-1] == '0' && s[i][len-2] == '=')
					Map[s[i].substr(0, len-2)] = 0;
				else
				{
					int y = s[i].find_first_of('=');
					Map[s[i].substr(0, y)] = Map[s[i].substr(y+1, len-y-1)];
				}
			}
		}
	}
}

int main()
{
	while (cin >> s[++ n] && s[n] != "$");
	TOD(1, n-1, 1);
	return 0;
}
/*
����
������һ�ֱ������TOD��
1 ֻ��int�������Ҹ����ǲ��Ϸ���
2 �Ϸ����������£�
   A����һ���������� V=0��
   B����һ������������һ���� V1 = V2��
   C���������� V++��
   D��ѭ�����ҿ���Ƕ��ʹ��
            i.e. Loop(v1)
                            ����..
                            Loop(v2)
                             ������
                           End
    .                      ����..
                   End

i.e ��������ѭ��ִ�������Σ�����ϸ��⣩
        V=0
        V++
        V++
        Loop(V)
               V=0
        End

ע�⣺1 �������ܳ��֡�0�����������
           2 ���򲻺��καȽϺ�if���

           3 ��һ�γ��ֵı���ȫ������0

�����������������⣬��������show a�������a��ֵ��

��������ĳ����

a=0
b=0
a++
Loop(a)
b++
End
show a
show b
$

�����������

1

1

������Ҫ�����¾��ǣ�����һ��tod���򣬲�������н�����ִ�С�

����
һ�κϷ���TOD���򣬲���֤ÿ��ֻ��һ����䣬���ײ�����ֿո�����������������ʶ����ֻ����ĸ�»��������ֲ������ַ����������֣��Ҵ�Сд���С�����$��ʾ���������
���򳤶Ȳ�����200�У���������в�����ִ���10000������
���
�������ִ�иöγ��򣬽�Tod�����������������
��������
a++
a++
P=0
Loop(a)
a=P
P++
End
show a
show P
$
�������
1
2
*/ 
