#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <cmath>
#include <vector> 
#include <queue>
#include <ctype.h>
#include <map>
#include <cfloat>
using namespace std;

void f(int n, int m)
{
	map <string, int> sim;
	char a[16];
	string s;
	int i;
	getchar();
	for (i = 1; i <= n; i ++)
	{
		gets(a);
		s = a;
		sim[a] ++;
	}
	while (m --)
	{
		gets(a);
		s = a;
		printf("%d\n", sim[s]);
	}
}

int main()
{
	
	int t, n, m;
	scanf("%d", &t);
	while (t --)
	{
		scanf ("%d%d", &n, &m);
		f(n, m);
	}
	return 0;
} 
/*
�����ַ���
ʱ�����ƣ�1000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�3
����
С���õ���һ��д������ַ�����ֽ������֪��һЩ�ַ��������˶��ٴΣ�����Щ�ַ���̫���ˣ�
���������æ�����ܰ����������ַ���������Сд��ĸ����@������+����

����
��һ�а���һ������T��T<=100).��ʾ��������������
������ÿ�����ݵ�һ�а�����������n��m(n��m<100000),�ֱ��ʾ��n���ַ�����С��Ҫ����m�Ρ�
������n�У�ÿ�а���һ���ַ��������Ȳ�����15��
������m�У�ÿ�а���һ���ַ�������ʾС��Ҫ�ʸô����ֵĴ�����
���
���ÿ��С��ѯ���������ֵĴ�����
��������
1
5 3
hello
it@is+so@easy
hello
ibelieveicanac
hello
hello
icannotacit
Giveup
�������
3
0
0
*/
