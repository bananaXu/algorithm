#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
using namespace std;

#define M 10005
#define N 105
#define MIN(a, b) a < b ? a : b
#define MAX(a, b) a > b ? a : b

struct EDGE
{
	int r;
	int next;
}edge[M]; // 存储边 

int head[N]; 
int Index; // 索引(时间线)
int res;   // 点集 
stack <int> ist;
int dfn[N]; // 该点时间线 
int low[N]; // 该点之后能够到达该点最的小时间点 
int t[N];   // 点属于的集合 
int instack[N]; // 是否在栈中 

void insert(int l, int r) // 插入边 
{
	edge[Index].r = r;
	edge[Index].next = head[l];
	head[l] = Index ++;
}

int targan(int x) // targan强连通图缩点算法 
{
	int i, r, v;
	ist.push(x); 
	dfn[x] = low[x] = Index ++;
	instack[x] = 1;
	for(i = head[x]; i != -1; i = edge[i].next)
	{
		r = edge[i].r;
		if (!dfn[r]) // 如果r点没有使用过，以r为起点运行targan算法 
		{
			targan(r);
			low[x] = MIN(low[x], low[r]); // 如果r点能从前面的点到达 
		}
		else if (instack[r])
		{
			low[x] = MIN(low[x], dfn[r]); // 如果r点在栈中 
		}
	}
	if (low[x] == dfn[x]) // 如果不能再从后面循环到达该点并经过
						  // 比该点时间点小的点，那么将连通的图缩点 
	{
		++ res;
		do
		{
			v = ist.top();
			instack[v] = 0;
			t[v] = res;
			ist.pop();
		}while (v != x);
	}
}

int main()
{
	int i, j, r, T, m, x, y, sum;
	int in[N], out[N];
	scanf("%d", &T);
	while (T --)
	{
		memset(head, -1, sizeof(head));
		memset(dfn, 0, sizeof(dfn));
		memset(instack, 0, sizeof(instack));
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		scanf("%d", &m);
		Index = 0;
		res = 0;
		for (i = 1; i <= m; i ++)
		{
			x = 1;
			while(1)
			{
				scanf("%d", &x);
				if (!x)
					break;
				insert(i, x);
			}
		}
		Index = 1;
		sum = 0;
		for (i = 1; i <= m; i ++) // 将所有能缩点的强连通图缩点 
		{
			if (!dfn[i])
			{
				targan(i);
			}
		}
		if (res == 1) // 如果点的集合只有一个，则不需要添加边 
		{
			printf("0\n");
		}
		else
		{
			// 计算每个强连通点的入度和出度 
			for (i = 1; i <= m; i ++)
			{
				for (j = head[i]; j != -1; j = edge[j].next)
				{
					r = edge[j].r;
					if (t[r] != t[i]) 
					{
						in[t[r]] ++;
						out[t[i]] ++;
					}
				}
			}
			x = y = 0;
			// 计算出度为0点的个数和入度为0点的个数
			// 结果为其中最大的，保证每个点都有入度和出度 
			for (i = 1; i <= res; i ++)
			{
				if (in[i] == 0)
					x ++;
				if (out[i] == 0)
					y ++;
			}
			printf("%d\n", MAX(x, y));
		}
	} 
	return 0;
}
/*
校园网络
时间限制：3000 ms  |  内存限制：65535 KB
难度：5
描述
南阳理工学院共有M个系，分别编号1~M,其中各个系之间达成有一定的协议，如果某系有新软件可用时，该系将允许一些其它的系复制并使用该软件。但该允许关系是单向的，即：A系允许B系使用A的软件时，B未必一定允许A使用B的软件。

现在，请你写一个程序，根据各个系之间达成的协议情况，计算出最少需要添加多少个两系之间的这种允许关系，才能使任何一个系有软件使用的时候，其它所有系也都有软件可用。

输入
第一行输入一个整数T，表示测试数据的组数(T<10)
每组测试数据的第一行是一个整数M，表示共有M个系(2<=M<=100)。
随后的M行，每行都有一些整数，其中的第i行表示系i允许这几个系复制并使用系i的软件。每行结尾都是一个0，表示本行输入结束。如果某个系不允许其它任何系使用该系软件，则本行只有一个0.
输出
对于每组测试数据，输出最少需要添加的这种允许关系的个数。
样例输入
1
5
2 4 3 0
4 5 0
0
0
1 0
样例输出
2
*/
