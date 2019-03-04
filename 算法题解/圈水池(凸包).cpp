#include <iostream>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Point
{
	int x;
	int y;
}p[105], sta[105];

// ������� 
int muliti(Point p1, Point p2, Point p0)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

// ÿ������p[0]Ϊ��׼��ʱ������ 
bool cmp(Point a, Point b)
{
	if (muliti(a, b, p[0]) > 0)
		return 1;
	if (muliti(a, b, p[0]) == 0 && abs(a.x-p[0].x) < abs(a.x-p[0].x))
		return 1;
	return 0;
}
 
bool cmp1(Point a, Point b)
{
	if (a.x < b.x)
		return true;
	if (a.x == b.x && a.y < b.y)
		return true;
	return false;
}

int main()
{
	int t, i, n, k, top;
	cin >> t;
	while (t --)
	{
		cin >> n;
		for (i = 0; i < n; i ++)
			cin >> p[i].x >> p[i].y;
		k = 0;
		// ѡ��y������С�е�����ߵĵ�Ϊp[0] 
		for (i = 1; i < n; i ++)
			if (p[i].y < p[k].y || (p[i].y == p[k].y && p[i].x < p[k].x))
				k = i;
		swap(p[0], p[k]);
		sort(p+1, p+n, cmp);
		sta[0] = p[0];
		sta[1] = p[1];
		sta[2] = p[2];
		top = 2;
		for (i = 3; i < n; i ++)
		{
			// �����ҹգ����ϸ����ջ 
			while(top > 1 && muliti(p[i], sta[top], sta[top-1]) >= 0)
			 	top--;
			sta[++ top] = p[i];
		}
		sort (sta, sta+top+1, cmp1);
		for (i = 0; i <= top; i ++)
			cout << sta[i].x << " " << sta[i].y << endl;
	}
	return 0;
}
/*
Ȧˮ��
ʱ�����ƣ�3000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�4
����
��һ���������������кܶ����ˮװ�ã�����������������Ҫ����ʰ���Щ��ˮװ��Ȧ�������Է�ֹ�����Լ�����������ˮ������ˮ�ض����и��Ե����꣬����Ҫ��дһ������������̵���ʽ���Щ��ˮװ��Ȧ������������㹻�࣬���ҳ��ȿɱ䣩
����
��һ���������N,������N��������ݣ�1<=N<=10��
�ڶ����������m,������������ݹ���m����ˮװ�ã�3<=m<=100��
������m�д�����Ǹ�����ˮװ�õĺ�������
���
���������ʾ���������ˮװ�õ�����㣬���Ұ���x������ֵ��С������������x������ֵ��ͬ���ٰ���y������ֵ��С�������
��������
1
4
0 0
1 1
2 3
3 0
�������
0 0
2 3
3 0
*/
