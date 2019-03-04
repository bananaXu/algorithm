#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <cmath>
#include <vector> 
#include <queue>
#include <set>
#include <ctype.h>
#include <map>
#include <cfloat>
using namespace std;

struct node
{
	int x, v;
	node(){};
	node(int a, int b):x(a), v(b){};
	bool operator <(const node &a)const{return v < a.v;}
};

bool inqueue[100005];
queue <node> p;

int main()
{
	int n, m;
	cin >> n >> m;
	bool find = false;
	p.push(node(n, 0));
	while (!p.empty())
	{
		node t = p.front();
		int x = t.x, v = t.v;
		if (x == m)
		{
			find = true;
			cout << v << endl;
			break;
		}
		p.pop();
		for (int i = 2; i <= sqrt(x); i ++)
		{
			if (x%i == 0)
			{
				if (x+i <= m && !inqueue[x+i])
				{	
					inqueue[x+i] = true;
					p.push(node(x+i, v+1));
				}
				if (x+x/i <= m && !inqueue[x+x/i])
				{
					inqueue[x+x/i] = true;
					p.push(node(x+x/i, v+1));
				}
			}
		} 
	}
	if (!find)
		cout << "-1" << endl;
	return 0;
}
/*
��Ŀ����
С��������һ��ʯ��·ǰ��ÿ��ʯ���ϴ�1���ű��Ϊ��1��2��3.......
����ʯ��·Ҫ��������Ĺ������ǰ��������С�׵�ǰ���ڵı��ΪK�� ʯ�壬С�׵���ֻ����ǰ��K��һ��Լ��(����1��K)����������K+X(XΪK��һ����1�ͱ����Լ��)��λ�á� С�׵�ǰ���ڱ��ΪN��ʯ�壬�����������ǡ��ΪM��ʯ��ȥ��С����֪��������Ҫ��Ծ���ο��Ե��
���磺
N = 4��M = 24��
4->6->8->12->18->24
����С��������Ҫ��Ծ5�Σ��Ϳ��Դ�4��ʯ������24��ʯ��
��������:
����Ϊһ�У�����������N��M���Կո������ (4 �� N �� 100000) (N �� M �� 100000)
�������:
���С��������Ҫ��Ծ�Ĳ���,������ܵ������-1
ʾ��1
����
4 24
���
5
*/
