#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int t, m, n, sum;
	cin >> t;
	while (t --)
	{
		sum = 0;
		cin >> m >> n;
		while (m)
		{
			sum += m/n;
			m /= n;
		}
		cout << sum << endl;
	} 
	return 0;
}
/*
����
����������m,n,����m��һ��������

��n��0<=n<=10000���Ľ׳˷ֽ����������������ж��ٸ�m��

����
��һ����һ������s��0<s<=100)����ʾ�������ݵ�����
����s��, ÿ������������n��m��
���
���m�ĸ�����
��������
2
100 5
16 2
�������
24
15
*/ 
