#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <cmath>
#include <ctype.h>
using namespace std;

int c(int m, int n)
{
	int i, j;
	int sum = 1;
	for (i = 1; i <= n; i ++)
	{
		sum = sum*(m-n+i)/i;
	}
	return sum;
} 

int main()
{
	char s[30];
	int i, j, l, sum;
	bool f;
	while (~scanf("%s", &s))
	{
		sum = 1;
		l = strlen(s)-1;
		f = true;
		if (l)
		{
			for (i = 1; i <= l; i ++)
			{
				if (s[i] <= s[i-1])
				{
					f = false;
					break;
				}
			}
		}
		if (!f)
		{
			printf("0\n");
		}
		else
		{
			for (i = 1; i <= l; i ++)
				sum += c(26, i);
			for (i = 0; i <= l; i ++)
			{
				for (j = 1; j <= s[i]-'a'-i; j ++)
					sum += c(25-i-j, l-i); 
			}
			printf("%d\n", sum);
		}
	}
	return 0;
}
/*
С�����ѧ��
ʱ�����ƣ�1000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�3
����
����С�������Ͽ�����һ����ֵ��ʾ��ʽ������дһ�����������Ѹ��ת��һ�¡���Ŀ��Ϣ���£�

         ��֪һ�ֶ�Ӧ��ϵ,��a��ʼ�����ֵ������ӣ��ַ����Ϊ5��������ͬ�Ļ��ߺ�����ַ�����ǰ��Ĵ���ַ����Ͳ�������

         a->1

         b->2

         ����

         ����

         z->26

ab->27

ac->28

����

����

vwxyz->83681

����

����
����������200�е����ݣ�ÿһ����һ���ַ�����������ֲ����Ϲ�����ַ����������ַ����ǵ����������ģ����0�������������Ӧ������������are ���Ϲ��򣬶�Ӧ���0��
���
���ÿ����������н�����
��������
a
z
cat
vwxyz
�������
1
26
0
83681

*/
