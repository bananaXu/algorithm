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

/*
˼·��
�ҵ����ߵ�һ�����ұ�С������ɾ������������û�ҵ���ʣ���ȫ���Ӻ���ǰɾ 
*/

int main()
{
	string s;
	int n;
	cin >> s >> n;
	int i = 0, len = s.length();
	while (n)
	{
		while (i < len-1 && s[i] >= s[i+1])
			i ++;
		if (i == len-1)
		{
			for (int j = 0; j <= len-1-n; j ++)
				cout << s[j];
			cout << endl;
			break;
		}
		s.erase(i, 1);
		if (i)
			i --;
		len --;
		n --;
		if (n == 0)
			cout << s << endl;
	}
	return 0;
}
/*
��Ŀ����
����һ��ʮ���Ƶ�������number��ѡ�������ȥ��һ�������֣�ϣ������������������ɵ����������
��������:
����Ϊ�������ݣ���һ����������number��1 �� length(number) �� 50000���ڶ�����ϣ��ȥ������������cnt 1 �� cnt < length(number)��
�������:
������������Ľ����
ʾ��1
����

325 1
���

35
*/
