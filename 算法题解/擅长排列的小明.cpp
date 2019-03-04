#include <iostream>
#include <algorithm>
using namespace std;

int a[10];
int used[10];
int n, m;

void GetPermutation(int pos)
{
	int i;
	if (pos == m+1)
	{
		for (i = 1; i <= m; i ++)
			cout << a[i];
		cout << endl;
	}
	// ���� 
	for (i = 1; i <= n; i ++)
	{
		if (!used[i])
		{
			used[i] = 1;
			a[pos] = i;
			GetPermutation(pos+1);
			used[i] = 0;
		}
	}
}

int main()
{
	int i, t;
	cin >> t;
	while (t --)
	{
		cin >> n >> m;
		for (i = 1; i <= 9; i ++)
		{
			used[i] = 0;
			a[i] = i;
		}
		GetPermutation(1);
	}
	return 0;
}
/*
����
С��ʮ�ִ���������ʮ���ó����м��㡣�����С��һ������5���������̸���1-5���ֵ����ȫ���У��������Ϊ����������5��������ѡ������������������ȫ���У���ô��ʹ��ˣ���ͬ���ĺ��ó���������Ҫ��дһ����������֤�ó����е�С�����׶Բ��ԡ�
����
��һ����������N��1<N<10����ʾ������������ݣ�
ÿ��������ݵ�һ���������� n m (1<n<9,0<m<=n)
���
��1-n��ѡȡm���ַ�����ȫ���У����ֵ���ȫ�����,ÿ������ռһ�У�ÿ�����ݼ䲻��ֽ硣������
��������
2
3 1
4 2
�������
1
2
3
12
13
14
21
23
24
31
32
34
41
42
43
*/
