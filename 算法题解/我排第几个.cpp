#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int a[13];

int lowbit(int x)
{
	return x&-x;
}

int getsum(int x)
{
	int sum = 0;
	while (x)
	{
		sum += a[x];
		x -= lowbit(x);
	}
	return sum;
}

int add(int x)
{
	while (x <= 12)
	{
		a[x] ++;
		x += lowbit(x);
	}
}

int main()
{
	int i, n, sum, x;
	int f[12] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 
				362880, 3628800, 39916800};
    char s[12];
    scanf("%d", &n);
    while (n --)
    {
    	scanf("%s", &s);
    	sum = 1;
    	memset(a, 0, sizeof(a));
    	for (i = 0; i < 12; i ++)
    	{
    		x = s[i]-'a'+1;
	    	add(x);
	    	sum += (x-getsum(x))*f[11-i];
	    }
	    printf("%d\n", sum);
    }
	return 0;
} 
/*
// ����չ�� X=a[n]*(n-1)!+a[n-1]*(n-2)!+...+a[i]*(i-1)!+...+a[1]*0!
// a[n] ��ʾ��ǰδ���ֵ�Ԫ���������ڵڼ���(�ӵ�0����ʼ) 
����
������"abcdefghijkl��12���ַ����������е������а��ֵ������У���������һ�����У�˵��������������е��������ǵڼ�С�ģ�

����
��һ����һ������n��0<n<=10000��;
�����n�У�ÿ����һ�����У�
���
���һ������m��ռһ�У�m��ʾ�����ǵڼ�λ��
��������
3
abcdefghijkl
hgebkflacdji
gfkedhjblcia
�������
1
302715242
260726926
*/
