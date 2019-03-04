#include <iostream>
#include <set>
#include <queue>
using namespace std;

struct N
{
	int val; // ����ˮ��״̬ 
	int num; // �ù��Ĳ��� 
};

set <int> exist; // �Ѵﵽ����״̬ 
queue <N> t; // ���У�����bfs���� 
int MAX[4]; // ÿ����������� 
int tar[4]; // Ԥ�ﵽ��Ŀ���ÿ������ ������� 
int target; //  Ŀ�����ת��Ϊ������������� 

int bfs()
{
	int i, j, x;
	N a, b; 
	int get[4]; // �ﵽ����״̬ 
	int find[4]; // ��һ���ܴﵽ��״̬ 
	while (!t.empty())
	{
		a = t.front();
		t.pop();
		if (a.val/100 == target)
		{
			return a.num;
		}
		get[1] = a.val/10000;
		get[2] = (a.val-get[1]*10000)/100;
		get[3] = a.val%100;
		for (i = 1; i <= 3; i ++) // 6�����(��i�����ˮȫ������j�����߽�j����) 
		{
			for (j = 1; j <= 3; j ++)
			{
				if (i != j)
				{
					if (get[i] || MAX[j] != get[j]) // ���iûˮ����j��ˮ�ų� 
					{
						if (MAX[j] >= get[i]+get[j]) // iȫ����j 
						{
							find[i] = 0;
							find[j] = get[i]+get[j];
							find[6-i-j] = get[6-i-j];
							x = find[1]*100+find[2];
							if (exist.find(x) == exist.end()) // ���������״̬ʱ 
							{
								b.val = x*100+find[3];
								b.num = a.num+1;
								exist.insert(x);
								t.push(b);
							}
						}
						else // i����j 
						{
							find[i] = get[i]+get[j]-MAX[j];
							find[j] = MAX[j];
							find[6-i-j] = get[6-i-j];
							x = find[1]*100+find[2];
							if (exist.find(x) == exist.end()) // ���������״̬ʱ 
							{
								b.val = x*100+find[3];
								b.num = a.num+1;
								exist.insert(x);
								t.push(b);
							}
						}
					}
				}
			}
		}
	}
	return -1;
}

int main()
{
	int num, count;
	N start;
	cin >> num;
	while (num --)
	{
		cin >> MAX[1] >> MAX[2] >> MAX[3] >> tar[1] >> tar[2] >> tar[3];
		target = tar[1]*100+tar[2];
		exist.clear();
		while (!t.empty())
		{
			t.pop();
		}
		start.val = MAX[1]*10000;
		start.num = 0;
		t.push(start);
		exist.insert(MAX[0]*100);
		if (MAX[1] != tar[1]+tar[2]+tar[3])
		{
			cout << "-1" << endl;
		}
		else
		{
			count = bfs();
			cout << count << endl;
		}
	}
	return 0;
} 
/*
����
��������ˮ������С��һ������ֻ������ˮ����ˮ��װ���ģ���������Ϊ�ձ��ӡ�����ˮ��֮���໥��ˮ������ˮ��û�б�ʶ��ֻ�ܸ��ݸ�����ˮ����������㡣����Ҫ����д��һ������ʹ�����ʹ��ʼ״̬����Ŀ��״̬�����ٴ�����
����
��һ��һ������N(0<N<50)��ʾN���������
������ÿ��������������У���һ�и�����������V1 V2 V3 (V1>V2>V3 V1<100 V3>0)��ʾ����ˮ���������
�ڶ��и�����������E1 E2 E3 �����С�ڵ�����Ӧˮ���������ʾ������Ҫ������״̬
���
ÿ�������Ӧ�����������ٵĵ�ˮ����������ﲻ��Ŀ��״̬���-1
��������
2
6 3 1
4 1 1
9 3 2
7 1 1
*/