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

int sum[80][80];
int cutl[5], cutr[5];
int n, m;

bool legal(int num, int v)
{
	for (int i = 1; i <= 4; i ++)
	{
		int x = cutl[i-1], y = cutr[num-1], x1 = cutl[i], y1 = cutr[num];
		if (sum[x1][y1]+sum[x][y]-sum[x1][y]-sum[x][y1] < v)
			return false;
	}
	return true;
}

bool rcut(int num, int v)
{
	if (num == 4)
		return legal(4, v);
	for (int i = cutr[num-1]+1; i <= m-4+num; i ++)
	{
		cutr[num] = i;
		if (legal(num, v))
		{ 
			if (rcut(num+1, v))
				return true;
			break;
		}
	}
	return false;
}

bool lcut(int num, int v)
{
	if (num == 4)
	{
		if (sum[cutl[4]][m]-sum[cutl[3]][m] > (v<<2))
			return rcut(1, v);
		return false;
	}
	for (int i = cutl[num-1]+1; i <= n-4+num; i ++)
	{
		cutl[num] = i;
		if (sum[n][m]-sum[i][m] <= (4-num)*(v<<2))
			return false;
		if (sum[cutl[num]][m]-sum[cutl[num-1]][m] >= (v<<2) && lcut(num+1, v))
			return true;
	}
	return false;
}

int search(int l, int r)
{
	if (l == r)
		return l;
	cutl[4] = n;
	cutr[4] = m;
	int mid = (l+r)>>1;
	if (lcut(1, mid+1))
		return search(mid+1, r);
	else
		return search(l, mid);
}

int main()
{
//	freopen("./in.txt", "r", stdin);
//	freopen("./out.txt", "w", stdout);
	while (~scanf("%d%d", &n, &m))
	{
		char s[80];
		for (int i = 1; i <= n; i ++)
		{
			scanf("%s", &s);
			for (int j = 1; j <= m; j ++)
			{
				int t = s[j-1]-'0';
				sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+t;
			}
		}
		printf("%d\n", search(0, sum[n][m]>>4));
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
/*
ţţ�� 15 �������������������ص���Ϸ��ţţ��������������أ���������ؿ��Կ�����һ�����Σ�ÿ��λ����һ����ֵ���ָ���صķ����Ǻ��������������ֳ� 16 �ݣ���Ϊ�쵼�ɲ���ţţ���ǻ�ѡ�������ܼ�ֵ��С��һ����أ� ��Ϊţţ��õ����ѣ���ϣ��ţţȡ�õ���صļ�ֵ�;����ܴ���֪�����ֵ�������Ƕ�����
��������:
ÿ��������� 1 ������������ÿ�����������ĵ�һ�а����������� n �� m��1 <= n, m <= 75������ʾ��صĴ�С���������� n �У�ÿ�а��� m �� 0-9 ֮������֣���ʾÿ��λ�õļ�ֵ��
�������:
���һ�б�ʾţţ����ȡ�õ����ļ�ֵ��
ʾ��1
����
4 4
3332
3233
3332
2323
���
2
*/
//1468 
