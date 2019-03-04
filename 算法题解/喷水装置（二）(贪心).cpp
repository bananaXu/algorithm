#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct Node
{
	double l;
	double r;
}node[10005];

bool cmp(Node a, Node b)
{
	return a.l < b.l;
}

// Ӧ�ô�������ʹ��̰���㷨������д�����ˣ��򵥣����ø��� 
int Find(int n, double w)
{
	int i, num;
	double x, Max;
	x = 0.0;
	num = 0;
	i = 1;
	while (1)
	{
		if (node[i].l > x) // ���ܸ���xλ�� 
			return 0;
		Max = 0.0;
		while(node[i].l <= x && i <= n) // ̰���ҵ��ܸ���x�����ܵ����ұ���Զ�ĵ� 
		{
			if (node[i].r == w)
				return num+1;
			if (i == n)
				return 0;
			if (node[i].r > Max)
				Max = node[i].r;
			i ++;
		}
		num ++;
		x = Max;
	}
}

int main()
{
	int i, n, t;
	double r, w, h, x, y;
	cin >> t;
	while (t --)
	{
		cin >> n >> w >> h;
		for (i = 1; i <= n; i ++)
		{
			cin >> x >> y;
			if (y < h/2.0) // ����뾶С�ڿ��һ�룬������������ 
				node[i].l = node[i].r = 0;
			else
			{
				// �����ܸ��ǵ�λ�� 
				r = sqrt(y*y-h*h/4.0);
				node[i].l = x-r >= 0 ? x-r : 0;
				node[i].r = x+r <= w ? x+r : w;
			}
		}
		// �����Ϊ��׼����  
		sort(node+1, node+n+1, cmp);
		cout << Find(n, w) << endl;
	}
	return 0;
}
/*
����
��һ���ƺ������w,����Ϊh,�����ęM���������ϲ�ͬλ�ô�װ��n(n<=10000)����״����ˮװ�ã�ÿ����ˮװ��i��ˮ��Ч����������Ϊ���İ뾶ΪRi��Բ������ʪ�����ڸ�������ˮװ����ѡ�����ٵ���ˮװ�ã���������ƺȫ����ʪ��
����
��һ������һ��������N��ʾ����n�β������ݡ�
ÿһ��������ݵĵ�һ������������n,w,h��n��ʾ����n����ˮװ�ã�w��ʾ��ƺ�ĺ��򳤶ȣ�h��ʾ��ƺ�����򳤶ȡ�
����n�У�������������xi��ri,xi��ʾ��i����ˮװ�õĵĺ����꣨�����Ϊ0����ri��ʾ����ˮװ���ܸ��ǵ�Բ�İ뾶��
���
ÿ������������һ������������ʾ����Ҫ���ٸ���ˮװ�ã�ÿ���������ռһ�С�
���������һ���ܹ���������ƺʪ��ķ����������0��
��������
2
2 8 6
1 1
4 5
2 10 6
4 5
6 5
�������
1
2
*/
