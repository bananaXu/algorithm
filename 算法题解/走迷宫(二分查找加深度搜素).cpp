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
using namespace std;

#define INF 0x3f3f3f3f

int a[105][105];
bool vis[105][105];
int Dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, Max, Min;

bool dfs(int x, int y, int l, int r)
{
	int i, p, q;
	vis[x][y] = true;
	if (a[x][y] >= l && a[x][y] <= r)
	{
		if (x == n && y == n) // �ҵ���һ������(l, r)�����· 
			return true;
		for (i = 0; i <= 3; i ++) // ���ĸ��������� 
		{
			p = x+Dir[i][0];
			q = y+Dir[i][1];
			if (p && q && q <= n && p <= n && !vis[p][q])
			{
				if (dfs(p, q, l, r))
					return true;	
			}
		}
	}
	return false;
}

int Search(int l, int r) // ���ֲ������ֵ����Сֵ�� 
{
	if (l == r)
		return l;
	int mid = (l+r)>>1;
	int i;
	for (i = Min; i <= Max-mid; i ++) // ö�ٲ�ֵΪmid�����ֵ����Сֵ�������� 
	{
		memset(vis, false, sizeof(vis));
		if (dfs(1, 1, i, i+mid)) // ��ȱ�������(i, i+mid)��������Ƿ�����ͨ 
			return Search(l, mid);
	}
	return Search(mid+1, r); // ��ֵmid�߲�ͨ 
}

int main()
{
	int i, j;
	while(~scanf("%d", &n))
	{
		Max = -INF;
		Min = INF;
		for (i = 1; i <= n; i ++)
		{
			for (j = 1; j <= n; j ++)
			{
				scanf("%d", &a[i][j]);
				if (a[i][j] > Max)
					Max = a[i][j];
				if (a[i][j] < Min)
					Min = a[i][j];
			}
		}
		printf("%d\n", Search(0, Max-Min));
	}
	return 0;
}
/*
���Թ�
ʱ�����ƣ�1000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�5
����
Dr.Kong��ƵĻ����˿���ǳ����棬������͵͵�ܳ�ʵ���ң���ĳ�����ֳ���֮��ƣ�����쿨�����ܳ����ˣ���SJTL���ֳ������ͣ�����������������滬���ݣ���ʱ����������һ���Թ��������Թ�����һ��N * N�ķ�������������е�Ԫ���������һ����������ʾ�ߵ����λ�õ��Ѷȡ�
����Թ����������ߣ������ߣ������ߣ������ߣ����ǲ��ܴ�Խ�Խ��ߡ����Թ���ȡʤ���������˼����˭�ܸ�����ҵ�һ��·������·���ϵ�Ԫ������Ѷ�ֵ����С�Ѷ�ֵ֮������С�ġ���Ȼ�ˣ�����������·���������·����
     �����˿����������Թ������Ͻǣ���һ�У���һ�У����������Թ������½ǣ���N�У���N�У���
����ܴ������ܿ���ҵ���������һ��·���������ҵ���
����
�ж���������ݣ���EOFΪ��������ı�־
��һ�У� N ��ʾ�Թ���N*N���� (2�� N�� 100)
��������N�У�	ÿһ�а���N��������������ʾÿ����Ԫ�����Ѷ� (0�������Ѷȡ�120)��
���
���Ϊһ����������ʾ·��������Ѷ��������ѶȵĲ
��������
5
1 1 3 6 8
1 2 2 5 5
4 4 0 3 3
8 0 2 3 4
4 3 0 2 1
�������
2
*/
