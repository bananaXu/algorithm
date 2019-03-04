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
题目描述
小易来到了一条石板路前，每块石板上从1挨着编号为：1、2、3.......
这条石板路要根据特殊的规则才能前进：对于小易当前所在的编号为K的 石板，小易单次只能往前跳K的一个约数(不含1和K)步，即跳到K+X(X为K的一个非1和本身的约数)的位置。 小易当前处在编号为N的石板，他想跳到编号恰好为M的石板去，小易想知道最少需要跳跃几次可以到达。
例如：
N = 4，M = 24：
4->6->8->12->18->24
于是小易最少需要跳跃5次，就可以从4号石板跳到24号石板
输入描述:
输入为一行，有两个整数N，M，以空格隔开。 (4 ≤ N ≤ 100000) (N ≤ M ≤ 100000)
输出描述:
输出小易最少需要跳跃的步数,如果不能到达输出-1
示例1
输入
4 24
输出
5
*/
