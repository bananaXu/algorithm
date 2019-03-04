#include <iostream>
#include <queue>
using namespace std;

int n, r;
int a[10];
int used[10] = {0};

void GetPermutation(int x)
{
	int i;
	if (x == r+1)
	{
		for (i = 1; i <= r; i ++)
			cout << a[i];
		cout << endl;
		return;
	}
	for (i = a[x-1]; i >= 1; i --)
	{
		if (!used[i])
		{
			a[x] = i;
			used[i] = 1;
			GetPermutation(x+1);
			used[i] = 0;
		}
	}
}

int main()
{
	cin >> n >> r;
	a[0] = n;
	GetPermutation(1);
	return 0;
} 
/*
����
�ҳ�����Ȼ��1��2��... ��n��0<n<10������ȡr(0<r<=n)������������ϡ�
����
����n��r��
���
���ض�˳�����������ϡ�
�ض�˳��ÿһ������е�ֵ�Ӵ�С���У����֮�䰴���ֵ������С�
��������
5 3
�������
543
542
541
532
531
521
432
431
421
321
*/
