#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int i, n, t;
	double sum;
	double a[605];
	cin >> t;
	while (t --)
	{
		cin >> n;
		sum = 20.0;
		for (i = 1; i <= n; i ++)
		{
			cin >> a[i];
			a[i] = 2*sqrt(pow(a[i], 2)-1);
		}
		sort(a+1, a+n+1);
		for (i = n; i >= 1; i --)
		{
			sum -= a[i];
			if (sum <= 0)
				break;
		}
		cout << n-i+1 << endl;
	}
	return 0;
}
/*
����
����һ���ƺ����Ϊ20�ף���Ϊ2�ף�Ҫ�ں��������Ϸ��ð뾶ΪRi����ˮװ�ã�ÿ����ˮװ�õ�Ч������������Ϊ���ĵİ뾶Ϊʵ��Ri(0<Ri<15)��Բ��ʪ�����г������ˮװ��i��1<i<600)��������һ���ܰѲ�ƺȫ��ʪ����Ҫ�����ǣ�ѡ�����ٵ���ˮװ�ã���������ƺ��ȫ��ʪ��
����
��һ��m��ʾ��m���������
ÿһ��������ݵĵ�һ����һ��������n��n��ʾ����n����ˮװ�ã�����һ�У���n��ʵ��ri��ri��ʾ����ˮװ���ܸ��ǵ�Բ�İ뾶��
���
�������װ�õĸ���
��������
2
5
2 3.2 4 4.5 6 
10
1 2 3 1 2 1.2 3 1.1 1 2
�������
2
5
*/
