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

/*
思路：
找到坐边第一个比右边小的数，删除这个数，如果没找到，剩余的全部从后往前删 
*/

int main()
{
	string s;
	int n;
	cin >> s >> n;
	int i = 0, len = s.length();
	while (n)
	{
		while (i < len-1 && s[i] >= s[i+1])
			i ++;
		if (i == len-1)
		{
			for (int j = 0; j <= len-1-n; j ++)
				cout << s[j];
			cout << endl;
			break;
		}
		s.erase(i, 1);
		if (i)
			i --;
		len --;
		n --;
		if (n == 0)
			cout << s << endl;
	}
	return 0;
}
/*
题目描述
给定一个十进制的正整数number，选择从里面去掉一部分数字，希望保留下来的数字组成的正整数最大。
输入描述:
输入为两行内容，第一行是正整数number，1 ≤ length(number) ≤ 50000。第二行是希望去掉的数字数量cnt 1 ≤ cnt < length(number)。
输出描述:
输出保留下来的结果。
示例1
输入

325 1
输出

35
*/
