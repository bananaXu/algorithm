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

#define M 5005
#define MIN(a, b) a < b ? a : b 
#define MAX(a, b) a > b ? a : b 

int main()
{
	int t;
	scanf("%d", &t);
	getchar();
	while (t --)
	{
		char s[M], c[M<<1];
		int a[M<<1]; // ��¼���ַ���ԭ�ַ�����λ�� 
		gets(s);
		int index = 0;
		for (int i = 0; i < strlen(s); i ++)
		{
			if (isalpha(s[i]))
			{
				c[++ index] = '#';
				c[++ index] = toupper(s[i]);
				a[index] = i;
			}
		}
		// ���ַ���ǰ���Լ�ÿ���ַ�֮�����#����֤�Ӵ�Ϊ������Ȼ���ַ������ϲ�ͬ��ͷβ����ֹԽ�� 
		c[0] = '*'; c[++ index] = '#'; c[++ index] = '.'; 
		int Rad[M<<1];
		int Max = 0;
		Rad[0] = 0;
		for (int i = 1, j = 0, k = 0; i < index; i += k)
		{
			while (c[i-j-1] == c[i+j+1]) j ++;
			Rad[i] = j;
			if (j > Rad[Max]) // �Ӵ���ͷ��βһ����#�����Կ���֪���뾶Խ���Ӵ�����һ��� 
				Max = i;
			for (k = 1; k <= j && Rad[i-k] != Rad[i]-k; k ++)
				Rad[i+k] = MIN(Rad[i-k], Rad[i]-k);
			j = MAX(0, Rad[i]-k);
		}
		int l = a[Max-Rad[Max]+1], r = a[Max+Rad[Max]-1]; // ������ԭ�ַ�����λ�� 
		for (int i = l; i <= r; i ++)
			printf("%c", s[i]);
		printf("\n");
	}
	return 0;
} 
/*
������Ӵ�
ʱ�����ƣ�1000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�4
����
����һ���ַ��������������Ļ����Ӵ����Ӵ��ĺ����ǣ���ԭ���������ֵ��ַ���Ƭ�Ρ����ĵĺ����ǣ����ſ��͵��ſ�����ͬ�ģ���abba��abbebba�����ж���Ҫ��������еı��Ϳո��Һ��Դ�Сд�������ʱ��ԭ���������β��Ҫ���������ַ������������ַ������ȴ��ڵ���1С�ڵ���5000���ҵ���ռһ��(����ж���𰸣������һ��)��
����
����һ����������n��1<=n<=10����
�����n�У�ÿ����һ���ַ�����
���
�����Ҫ��Ļ����Ӵ���
��������
1
Confuciuss say:Madam,I'm Adam.
�������
Madam,I'm Adam
*/
