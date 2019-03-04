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

#define M 205
#define INF 0x3f3f3f3f
#define MOD 1000000009

struct POINT // ��������Ϣ 
{
	int dis;
	int num;
}point[M][M];

struct Point
{
	int x;
    int y;
    int dis;
	bool operator < (const struct Point &a)const {return this->dis > a.dis;}
}; // Ϊ����׼������ 

priority_queue <Point> pq; // ���ȶ��� 
int vis[M][M]; // �Ƿ���ʹ� 
int a[M][M]; // ���ֵ 
int n;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // ���� 

int getNum()
{
	Point p;
	p.x = 1; p.y = 1; p.dis = 0;
	pq.push(p); // ��ԭ��ѹ�����ȶ��� 
	int i, j, l, r, min, num, x, y, dis;
	point[1][1].num = 1;
	memset(vis, 0, sizeof(vis));
	min = INF; num = 0;
	while (!pq.empty())
	{
		p = pq.top();
		x = p.x; y = p.y; dis = p.dis;
		vis[x][y] = 1;
		pq.pop();
		if (x+y == n+1) // ������յ� 
		{
			if (dis < min) // ���������ȶ��У����ҵ���һ����ʱ������С���� 
			{
				min = dis; // ������С���� 
				num = (num+point[x][y].num)%MOD;
			}
			else if (p.dis == min) // �������յ�Ҳ����С���� 
				num = (num+point[x][y].num)%MOD;
			else // ������С����,�����ÿգ�Ϊ��������׼�� 
			{
				while(!pq.empty()) pq.pop();
				return num;
			}
		}
		else
		{
			for (i = 0; i <= 3; i ++)
			{
				l = x+dir[i][0];
				r = y+dir[i][1]; // �ĸ�����ĵ� 
				// ��������Ϸ�����(û�г����й�����벻��)
				if (l && r && l+r <= n+1 && dis+a[l][r] <= point[l][r].dis) 
				{	// ���벻�䣬��ô������㷽�������ϵ����ϸ���ķ�����
					// ���������ȶ����ҷ�������·���޹أ�������һ����ʱ�Ѿ������е����������ۼ�
					// ���Կ���ֱ����� 
					point[l][r].num = (point[l][r].num+point[x][y].num)%MOD;
					if (!vis[l][r] && dis+a[l][r] < point[l][r].dis) // δ�����й��Ҿ���ɸ��� 
					{
						point[l][r].dis = dis+a[l][r];
						p.x = l; p.y = r; p.dis = point[l][r].dis;
						pq.push(p);	
					}
				}
			}
		}
	}
	return num;
}

int main()
{
	int i, j, x;
	while (1)
	{
		scanf("%d", &n);
		if (n == 0)
			break;
		memset(a, 0, sizeof(a));
		for (i = 1; i <= n; i ++)
		{
			for (j = 1; j <= n; j ++)
			{
				scanf("%d", &x);
				if (i+j <= n+1)
					a[i][j] += x; // �ضԽ������ 
				else
					a[n+1-j][n+1-i] += x;
			}
		}
		for (i = 1; i <= n; i ++)
		{
			for (j = 1; j+i <= n+1; j ++)
			{
				point[i][j].dis = INF; // �Ƚ�ÿ�����ԭ�������Ϊ��󣬵��������ķ�������Ϊ0 
				point[i][j].num = 0;
			}
		}
		printf("%d\n", getNum());
	}
	return 0;
}
/*
���ŶԳ�·��
ʱ�����ƣ�1000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�3
����
    ��һ�� n �� n �е�����ÿ����������һ�� 1 �� 9 �����֡�����Ҫ�����Ͻ��ߵ����½ǣ�
	����ÿһ��ֻ�����ϡ��¡������ĸ�����֮һ�ߵ����ڸ��ӣ�����б���ߣ�Ҳ�����߳�����
	�������ظ�����һ�����ӡ�Ϊ�����ۣ��㾭����·����������ڡ�����-���ϡ������Խ��߶Գơ���
	ͼ��һ�� 6x6 �����ϵĶԳ�·����
    ���������ͳ�����кϷ�·���У�����֮����С��·���ж�������
����
���������� 25 ��������ݡ�ÿ�����ݵ�һ��Ϊһ������ n��2<=n<=200�������� n ��ÿ�а��� n �� 1 �� 9
�����֣���ʾ�����������������־Ϊ n=0��
���
����ÿ�����ݣ�����Ϸ�·���У�����֮����С��·���������� 1,000,000,009 ��������
��������
2 
1 1 
1 1 
3 
1 1 1 
1 1 1 
2 1 1 
0 
�������
2 
3
*/
