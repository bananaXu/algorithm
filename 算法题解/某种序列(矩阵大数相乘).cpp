#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

int main()
{
	int i, l, l1, l2, l3, x, y, z;
	while (~scanf("%d%d%d", & x, &y, &z))
	{
		if (x == 0 && y == 0 && z == 0)
		{
			cout << 0 << endl;
			continue;
		}
		l = 25;
		int a[35] = {9,8,4,3,4,8,8,5,8,7,6,1,1,7,0,2,4,5,9,7,6,2,6,7,5,1};
		int b[35] = {1,4,2,8,8,7,1,5,4,1,3,4,1,8,6,9,1,2,5,7,6,2,3,3,4,2};
		int c[35] = {7,1,4,4,3,9,2,1,6,7,1,7,6,1,4,8,0,7,7,8,0,2,9,9,8,2};
		for (i = 0; i <= l; i ++)
		{
			a[i] *= x;
			b[i] *= y;
			c[i] *= z;
		}
		l1 = l;
		for (i = 0; i <= l1; i ++)
		{
			if (i == l1 && a[i] > 9)
				l1 ++;
			if (a[i] > 9)
			{
				a[i+1] += a[i]/10;
				a[i] %= 10;
			}
		}
		l2 = l;
		for (i = 0; i <= l2; i ++)
		{
			if (i == l2 && b[i] > 9)
				l2 ++;
			if (b[i] > 9)
			{
				b[i+1] += b[i]/10;
				b[i] %= 10;
			}
		}
		l3 = l;
		for (i = 0; i <= l3; i ++)
		{
			if (i == l3 && c[i] > 9)
				l3 ++;
			if (c[i] > 9)
			{
				c[i+1] += c[i]/10;
				c[i] %= 10;
			}
		}
		l = (l1 > l2) ? (l1 > l3 ? l1 : l3) : (l2 > l3 ? l2 : l3);
		for (i = 0; i <= l; i ++)
		{
			a[i] += b[i]+c[i];
			if (i == l && a[i] > 9)
				l ++;
			if (a[i] > 9)
			{
				a[i+1] += a[i]/10;
				a[i] %= 10;
			}
		}
		for (i = l; i >= 0; i --)
			cout << a[i];
		cout << endl;
	}
	return 0;
}
/*
a b c   0 0 1
0 0 0 * 1 0 1
0 0 0   0 1 1
转换为矩阵相乘 

描述
数列A满足An = An-1 + An-2 + An-3, n >= 3 
编写程序，给定A0, A1 和 A2, 计算A99
输入
输入包含多行数据 
每行数据包含3个整数A0, A1, A2 (0 <= A0, A1, A2 <= 100000000) 
数据以EOF结束
输出
对于输入的每一行输出A99的值
样例输入
1 1 1
样例输出
69087442470169316923566147

100000000 100000000 100000000
*/

//struct BigInt
//{
//	int a[1000];
//}b[3][3], c[3][3];
//
//int a[3][3] = {{0, 0, 1},
//			     {1, 0, 1},
//		    	 {0, 1, 1}};
//
//void getc(int j, int k, int l)
//{
//	int i;
//	if (a[l][k])
//	{
//		for (i = 0; i < 1000; i ++)
//		{
//			c[j][k].a[i] += b[j][l].a[i];
//			if (c[j][k].a[i] > 9)
//			{
//				c[j][k].a[i] -= 10;
//				c[j][k].a[i+1] ++;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int i, j, k, l;
//	for (i = 0; i < 3; i ++)
//	{
//		for (j = 0; j < 3; j ++)
//			b[i][j].a[0] = a[i][j];
//	}
//	for (i = 1; i <= 96; i ++)
//	{
//		for (j = 0; j < 3; j ++)
//		{
//			for (k = 0; k < 3; k ++)
//			{
//				for (l = 0; l <= 999; l ++)
//					c[j][k].a[l] = 0;
//			}
//		}
//		for (j = 0; j < 3; j ++)
//		{
//			for (k = 0; k < 3; k ++)
//			{
//				for (l = 0; l < 3; l ++)
//				{
//					getc(j, k, l);
//				}
//			}
//		}
//		for (j = 0; j < 3; j ++)
//		{
//			for (k = 0; k < 3; k ++)
//				b[j][k] = c[j][k];
//		}
//	}
//	for (i = 0; i < 3; i ++)
//	{
//		for (j = 0; j < 3; j ++)
//		{
//			for (k = 999; k > 0; k --)
//			{
//				if (b[i][j].a[k])
//					break;
//			}
//			for (; k >= 0; k --)
//				cout << b[i][j].a[k];
//			cout << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}
/*
15762679542071167858843489
24332675219681431451788241
28992087708416717612934417
*/
