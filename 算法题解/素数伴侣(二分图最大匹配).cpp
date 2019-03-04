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
#include <string>
using namespace std;

#define M 105

struct EDGE
{
	int r, next;
}edge[M*M];

bool a[60005], used[M];
int b[M], head[M], match[M];
int Index;

void insert(int l, int r)
{
	edge[Index].r = r;
	edge[Index].next = head[l];
	head[l] = Index ++;
}

bool Dfs_Match(int x) // dfs������ƥ��
{
	int i;
	for (i = head[x]; i != -1; i = edge[i].next)
	{
		int r = edge[i].r;
		if (!used[r]) // ���ڽ���·��
		{
			used[r] = 1;
			if (match[r] == -1 || Dfs_Match(match[r])) // �ҵ�δƥ��㣬��·������
			{
				match[r] = x;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	for(int i = 4; i < 60000; i += 2)
		a[i] = true;
	for(int i = 3; i*i < 60000; i += 2)
	{
		if(!a[i])
		{
			for(int j = i*i; j < 60000; j += 2*i) 
				a[j] = true;
		}
	}
	int n;
	while (cin >> n)
	{
		memset(head, -1, sizeof(head));
		memset(match, -1, sizeof(match));
		Index = 0;
		for (int i = 1; i <= n; i ++)
			cin >> b[i];
		for (int i = 1; i <= n; i ++)
		{
			for (int j = i+1; j <= n; j ++)
			{
				if (!a[b[i]+b[j]])
				{
					if (b[i]&1)
						insert(i, j);
					else
						insert(j, i);
				}
			}
		}
		int sum = 0;
		for (int i = 1; i <= n; i ++)
		{
			memset(used, false, sizeof(used));
			if (Dfs_Match(i))
				sum ++;
		}
		cout << sum << endl;
	}
	return 0;
}
/*
��Ŀ����
��Ŀ����
�������������ĺ�Ϊ����������������������֮Ϊ���������¡�����2��5��6��13��������Ӧ����ͨ�ż��ܡ���������ѧ���������һ�����򣬴����е�N��NΪż����������������ѡ�����ɶ���ɡ��������¡�����ѡ�������ֶ�����������4����������2��5��6��13�������5��6��Ϊһ����ֻ�ܵõ�һ�顰�������¡�������2��5��6��13���齫�õ����顰�������¡�������ɡ��������¡����ķ�����Ϊ����ѷ���������Ȼ����ѧ��ϣ����Ѱ�ҳ�����ѷ�������
����:
��һ����ż��N��N��100������ʾ����ѡ����Ȼ���ĸ��������������������֣���ΧΪ[2,30000]��
���:
���һ������K����ʾ����õġ���ѷ�������ɡ��������¡��Ķ�����
 
��������:
����˵��
1 ����һ����ż��n
2 ����n������
�������:
��õġ���ѷ�������ɡ��������¡��Ķ�����
ʾ��1
����
4
2 5 6 13
���
2
*/
