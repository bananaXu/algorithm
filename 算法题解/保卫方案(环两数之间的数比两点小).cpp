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
题目描述
战争游戏的至关重要环节就要到来了，这次的结果将决定王国的生死存亡，小B负责首都的防卫工作。首都位于一个四面环山的盆地中，周围的n个小山构成一个环，作为预警措施，小B计划在每个小山上设置一个观察哨，日夜不停的瞭望周围发生的情况。 一旦发生外地入侵事件，山顶上的岗哨将点燃烽烟，若两个岗哨所在的山峰之间没有更高的山峰遮挡且两者之间有相连通路，则岗哨可以观察到另一个山峰上的烽烟是否点燃。由于小山处于环上，任意两个小山之间存在两个不同的连接通路。满足上述不遮挡的条件下，一座山峰上岗哨点燃的烽烟至少可以通过一条通路被另一端观察到。对于任意相邻的岗哨，一端的岗哨一定可以发现一端点燃的烽烟。 小B设计的这种保卫方案的一个重要特性是能够观测到对方烽烟的岗哨对的数量，她希望你能够帮她解决这个问题。
输入描述:
输入中有多组测试数据，每一组测试数据的第一行为一个整数n(3<=n<=10^6),为首都周围的小山数量，第二行为n个整数，依次表示为小山的高度h（1<=h<=10^9）.
输出描述:
对每组测试数据，在单独的一行中输出能相互观察到的岗哨的对数。
示例1
输入

5
1 2 4 5 3
输出

7
*/
