#include <iostream>
#include <set>
#include <queue>
using namespace std;

struct N
{
	int val; // 杯子水的状态 
	int num; // 用过的步数 
};

set <int> exist; // 已达到过的状态 
queue <N> t; // 队列，用来bfs搜索 
int MAX[4]; // 每个杯子最大量 
int tar[4]; // 预达到的目标的每个杯子 里面的量 
int target; //  目标的量转化为整数，方便计算 

int bfs()
{
	int i, j, x;
	N a, b; 
	int get[4]; // 达到过的状态 
	int find[4]; // 下一步能达到的状态 
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
		for (i = 1; i <= 3; i ++) // 6种情况(将i里面的水全部倒进j，或者将j倒满) 
		{
			for (j = 1; j <= 3; j ++)
			{
				if (i != j)
				{
					if (get[i] || MAX[j] != get[j]) // 如果i没水或者j满水排除 
					{
						if (MAX[j] >= get[i]+get[j]) // i全倒进j 
						{
							find[i] = 0;
							find[j] = get[i]+get[j];
							find[6-i-j] = get[6-i-j];
							x = find[1]*100+find[2];
							if (exist.find(x) == exist.end()) // 不存在这个状态时 
							{
								b.val = x*100+find[3];
								b.num = a.num+1;
								exist.insert(x);
								t.push(b);
							}
						}
						else // i倒满j 
						{
							find[i] = get[i]+get[j]-MAX[j];
							find[j] = MAX[j];
							find[6-i-j] = get[6-i-j];
							x = find[1]*100+find[2];
							if (exist.find(x) == exist.end()) // 不存在这个状态时 
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
描述
给出三个水杯，大小不一，并且只有最大的水杯的水是装满的，其余两个为空杯子。三个水杯之间相互倒水，并且水杯没有标识，只能根据给出的水杯体积来计算。现在要求你写出一个程序，使其输出使初始状态到达目标状态的最少次数。
输入
第一行一个整数N(0<N<50)表示N组测试数据
接下来每组测试数据有两行，第一行给出三个整数V1 V2 V3 (V1>V2>V3 V1<100 V3>0)表示三个水杯的体积。
第二行给出三个整数E1 E2 E3 （体积小于等于相应水杯体积）表示我们需要的最终状态
输出
每行输出相应测试数据最少的倒水次数。如果达不到目标状态输出-1
样例输入
2
6 3 1
4 1 1
9 3 2
7 1 1
*/