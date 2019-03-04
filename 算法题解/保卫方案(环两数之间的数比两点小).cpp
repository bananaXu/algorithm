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

#define M 1000005
typedef long long ll;
typedef pair<int, int> p;

vector <p> v;
vector <p>::iterator it1;
set <int> s;
set <int>::iterator it2;

int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 1; i <= n; i ++)
		{
			int x;
			cin >> x;
			s.insert(x);
			if (v.empty() || x != v.back().first)
				v.push_back(make_pair(x, 1));
			else
				v.back().second ++;
		}
		ll sum = 0;
		for (it2 = s.begin(); it2 != s.end(); it2 ++)
		{
			for (it1 = v.begin(); it1 != v.end();)
			{
				if (v.size() == 1)
				{
					ll t = v.back().second;
					if (t == 1)
						sum --;
					sum += t*(t-1)/2;
					v.clear();
					break;
				}
				p x = *it1;
				int y = *it2;
				if (x.first == y)
				{
					if (it1 == v.begin() && x.first == y && v.back().first == y)
					{
						ll t = x.second+v.back().second;
						sum += t*(t+3)/2;
						it1 ++;
						v.erase(v.begin());
						v.erase(v.end());
					}
					else if (x.first == y)
					{
						ll t = x.second;
						sum += t*(t+3)/2;
						it1 ++;
						v.erase(it1-1);
						it1 --;
						if (it1 != v.begin() && it1 != v.end() && (*it1).first == (*(it1-1)).first)
						{
							(*it1).second += (*(it1-1)).second;
							v.erase(it1-1);
							it1 --;
						}
					}
				}
				else
					it1 ++;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
/*
��Ŀ����
ս����Ϸ��������Ҫ���ھ�Ҫ�����ˣ���εĽ������������������������СB�����׶��ķ����������׶�λ��һ�����滷ɽ������У���Χ��n��Сɽ����һ��������ΪԤ����ʩ��СB�ƻ���ÿ��Сɽ������һ���۲��ڣ���ҹ��ͣ�Ĳt����Χ����������� һ��������������¼���ɽ���ϵĸ��ڽ���ȼ���̣��������������ڵ�ɽ��֮��û�и��ߵ�ɽ���ڵ�������֮��������ͨ·������ڿ��Թ۲쵽��һ��ɽ���ϵķ����Ƿ��ȼ������Сɽ���ڻ��ϣ���������Сɽ֮�����������ͬ������ͨ·�������������ڵ��������£�һ��ɽ���ϸ��ڵ�ȼ�ķ������ٿ���ͨ��һ��ͨ·����һ�˹۲쵽�������������ڵĸ��ڣ�һ�˵ĸ���һ�����Է���һ�˵�ȼ�ķ��̡� СB��Ƶ����ֱ���������һ����Ҫ�������ܹ��۲⵽�Է����̵ĸ��ڶԵ���������ϣ�����ܹ��������������⡣
��������:
�������ж���������ݣ�ÿһ��������ݵĵ�һ��Ϊһ������n(3<=n<=10^6),Ϊ�׶���Χ��Сɽ�������ڶ���Ϊn�����������α�ʾΪСɽ�ĸ߶�h��1<=h<=10^9��.
�������:
��ÿ��������ݣ��ڵ�����һ����������໥�۲쵽�ĸ��ڵĶ�����
ʾ��1
����

5
1 2 4 5 3
���

7
*/
