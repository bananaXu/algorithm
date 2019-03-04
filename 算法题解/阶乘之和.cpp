#include <iostream>
#include <set>
#include <stack>
using namespace std;

int main()
{
	int i, a, v;
	int m, b;
	set <int> c;
	set <int>::iterator it;
	stack <int> d;
	c.insert(0);
	a = 1;
	for (i = 1; i <= 10; i ++)
	{
		a *= i;
		for (it = c.begin(); it != c.end(); it ++)
		{
			v = (*it)+a;
			if (v < 1000000)
				d.push(v);
		}
		while (!d.empty())
		{
			v = d.top();
			c.insert(v);
			d.pop();
		}
	}
	cin >> m;
	while (m --)
	{
		cin >> b;
		if (c.find(b) != c.end())
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
} 
/*
����
����һ���Ǹ�������n���ж�n�ǲ���һЩ������Щ���������ظ�ʹ�ã���Ϊ�������Ľ�
��֮�ͣ���9=1��+2!+3!������ǣ������Yes���������No��
����
��һ����һ������0<m<100,��ʾ��m��������ݣ�
ÿ�����������һ��������n<1000000;
���
����������������Yes���������No;
*/