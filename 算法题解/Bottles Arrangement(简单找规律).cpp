#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <cmath>
#include <vector> 
#include <queue>
#include <ctype.h>
#include <cfloat>
using namespace std;

int main()
{
	int i, n, m;
	while (~scanf("%d%d", &m, &n))
	{
		printf("%d\n", ((m<<1)-(n>>1)+1)*(n>>1)+m-(n>>1));
	}
	return 0;
}
/*
m��n��
ÿ��Ϊ1~m
һ������������֮���ܴ���1
�ҳ����������ľ������еĺ�����һ������С���Ǹ�ֵ 
�� 3*3 
1 2 3
2 1 1
3 3 2
��СΪ8
����Ϊ
m*n
m m-1 m-2 ...m-n/2
m m-1 m-2 ...m-n/2+1
*/
