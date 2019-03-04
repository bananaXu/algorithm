#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct TIME
{
	int l;
	int r;
}ti[10005];

bool cmp(TIME a, TIME b)
{
	return a.r < b.r;
}

int main()
{
	int i, t, m, num, Min;
	cin >> t;
	while (t --)
	{
		cin >> m;
		for (i = 1; i <= m; i ++)
		{
			scanf("%d%d", &ti[i].l, &ti[i].r);
		}
		sort(ti+1, ti+m+1, cmp);
		Min = -1;
		num = 0;
		for (i = 1; i <= m; i ++)
		{
			if (Min < ti[i].l)
			{
				Min = ti[i].r;
				num ++;
			}
		}
		cout << num << endl;
	}
	return 0;
} 
/*
����
ѧУ��С����ÿ�춼�����������ʱ����Щ��ļƻ�ʱ��ᷢ����ͻ����Ҫѡ���һЩ����оٰ졣С���Ĺ������ǰ���ѧУС���õĻ��ÿ��ʱ����ల��һ���������С����һЩ��ƻ���ʱ������뾡���ܵİ��Ÿ���Ļ������������ΰ��š�
����
��һ����һ��������m(m<100)��ʾ����m��������ݡ�
ÿ��������ݵĵ�һ����һ������n(1<n<10000)��ʾ�ò������ݹ���n�����
����n�У�ÿ��������������Bi,Ei(0<=Bi,Ei<10000),�ֱ��ʾ��i�������ʼ�����ʱ�䣨Bi<=Ei)
���
����ÿһ�����룬�������ܹ����ŵĻ������
ÿ������ռһ��
��������
2
2
1 10
10 11
3
1 10
10 11
11 20
�������
1
2
*/
