#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

// 当前节点走过n次，如果n为奇数，左孩子节点走过(n+1)/2次，右孩子节点走过n/2次
// 如果n为偶数，左孩子节点走过n/2次，右孩子节点走过n/2次
// 而第n次为奇数时往左孩子节点走，n为偶数时往右孩子节点走 
int main()
{
	int i, m, n, x;
	while (1)
	{
		cin >> m >> n;
		if (m == 0 && n == 0)
			break;
		x = 1;
		for (i = 1; i < m; i ++)
		{
			if (n&1)
			{
				x <<= 1;
				n = (n>>1)+1;
			}
			else
			{
				x = x<<1|1;
				n >>= 1;
			}
		}
		cout << x << endl;
	}
	return 0;
}
/*
描述
有一颗二叉树，最大深度为D,且所有叶子的深度都相同。所有结点从左到右从上到下的编号为1,2,3，·····，2的D次方减1。在结点1处放一个小猴子，它会往下跑。每个内结点上都有一个开关，初始全部关闭，当每次有小猴子跑到一个开关上时，它的状态都会改变，当到达一个内结点时，如果开关关闭，小猴子往左走，否则往右走，直到走到叶子结点。

一些小猴子从结点1处开始往下跑，最后一个小猴儿会跑到哪里呢？

输入
输入二叉树叶子的深度D,和小猴子数目I，假设I不超过整棵树的叶子个数，D<=20.最终以 0 0 结尾
输出
输出第I个小猴子所在的叶子编号。
样例输入
4 2
3 4
0 0
样例输出
12
7
*/ 
//1 5 3  7  2  6  4  8  
//8 9 10 11 12 13 14 15
