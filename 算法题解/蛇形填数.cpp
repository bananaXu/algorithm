#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n, num, i, j;
	int a[105][105] = {0};
	cin >> n;
	num = 0;
	i = 0;
	j = n;
	while (num < n*n)
	{
		while(i < n && !a[i+1][j]) a[++i][j] = ++ num;
		while(j > 1 && !a[i][j-1]) a[i][--j] = ++ num;
		while(i > 1 && !a[i-1][j]) a[--i][j] = ++ num;
		while(j < n && !a[i][j+1]) a[i][++j] = ++ num;
	}
	for (i = 1; i <= n; i ++)
	{
		for (j = 1; j <= n; j ++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	return 0;
}
/*
����
��n*n����������1,2,...,n*n,Ҫ��������Ρ�����n=4ʱ����Ϊ��
10 11 12 1
9 16 13 2
8 15 14 3
7 6 5 4
����
ֱ�����뷽�µ�ά������n��ֵ��(n<=100)
���
�����������η��¡�
��������
3
�������
7 8 1
6 9 2
5 4 3
*/
