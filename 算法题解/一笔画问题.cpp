#include <iostream>
#include <cstring>
using namespace std;

int father[1005];

int FindFather(int x)
{
	while (x != father[x]) x = father[x];
	return x;
}
// ���һ��ͼ����ͨ�Ĳ�����ȵ�Ϊ0����2�������ͼ�ܱ�һ�ʻ����������� 
int main()
{
	int i, t, n, m, l, r, num, f;
	int a[1005];
	bool connect;
	cin >> t;
	while (t --)
	{
		cin >> n >> m;
		num = 0;
		memset(a, 0, sizeof(a));
		for (i = 1; i <= n; i ++)
			father[i] = i;
		for (i = 1; i <= m; i ++)
		{
			cin >> l >> r;
			// ���鼯��l, r�ϲ� 
			father[FindFather(l)] = FindFather(r);
			// ��¼��Ķ��� 
			a[l] ++;
			a[r] ++;
		}
		connect = true;
		f = FindFather(1);
		for (i = 2; i <= n; i ++)
		{
			if (FindFather(i) != f)
			{
				connect = false;
				break;
			}
		}
		if (connect) // �������ͨ�� 
		{
			for (i = 1; i <= n; i ++)
			{
				if (a[i]&1)
					num ++;
				if (num > 2)
					break;
			}
			if (num == 0 || num == 2)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		else
			cout << "No" << endl;
	}
	return 0;
}
/*
����
zyc��С�ͱȽ�ϲ����һЩС��Ϸ�����оͰ�����һ�ʻ��������������дһ�������ж�һ��ͼ�Ƿ��ܹ���һ�ʻ�������

�涨�����еı߶�ֻ�ܻ�һ�Σ������ظ�����

 

����
��һ��ֻ��һ��������N(N<=10)��ʾ�������ݵ�������
ÿ��������ݵĵ�һ��������������P,Q(P<=1000,Q<=2000)���ֱ��ʾ��������ж��ٸ�����Ͷ��������ߡ�����ı�Ŵ�1��P��
����Q�У�ÿ��������������A,B(0<A,B<P)����ʾ���ΪA��B������֮�������ߡ�
���
������ڷ������������ߣ������"Yes",
��������ڷ������������ߣ����"No"��
��������
2
4 3
1 2
1 3
1 4
4 5
1 2
2 3
1 3
1 4
3 4
�������
No
Yes
*/
