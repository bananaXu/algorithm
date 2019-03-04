#include <iostream>
#include <iomanip>
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
#include <list>
#include <ext/hash_map>
#include <ext/hash_set>
using namespace std;
using namespace __gnu_cxx;

typedef pair <int, int> lp;
#define M 9905

vector <lp> a[M];
int n, m;

set <int> dfs(int u)
{
	set <int> b[M], val;
	set <int>::iterator it, it1;
	val.insert(0);
	for (int i = 0; i < a[u].size(); i ++)
	{
		set <int> t(dfs(a[u][i].first));
		for (it = t.begin(); it != t.end(); it ++)
			if (*it+a[u][i].second <= m)	
				b[i].insert(*it+a[u][i].second);
	}
	for (int i = 0; i < a[u].size(); i ++)
	{
		for (it = b[i].begin(); it != b[i].end(); it ++)
			if (*it <= m)
				val.insert(*it);
	   	for (int j = 0; j < a[u].size(); j ++)
	   	{
	   		if (i == j)
	   			continue;
   			for (it = b[i].begin(); it != b[i].end(); it ++)
   			{
		   		for (it1 = b[j].begin(); it1 != b[j].end(); it1 ++)
		   			if (*it+*it1 <= m)
		   				val.insert(*it+*it1);
		    }
	   	}
	}
	return val;
}

int main()
{
	cin >> m >> n;
	vector <int> root(n, 0);
	int u, v, d;
	for (int i = 1; i < n; i ++)
	{
		cin >> u >> v >> d;
		a[u].push_back(make_pair(v, d));
		root[v] = 1;
	}
	for (int i = 0; i < n; i ++)
	{
		if (!root[i])
		{
			set <int> b(dfs(i));
			cout << *b.rbegin() << endl;
			break;
		}
	}
	return 0;
}
/*
ƴ��������ĳ��к͵�·�����˽ṹ�Ƚ��ر���һ����״�ṹ��
1. ÿ������������һ���ڵ㣻
2. ����֮��ĵ�·������һ���ߣ�
3. ���ĸ��ڵ����׶���
ƴ������������Ͼ�Ҫ���ˣ�����ƴ���������һ�������ӡ�Ϊ�˻�Ծ���գ��������ڵ�·�ϲ��û��ơ����ƿ��Ǻܹ�Ķ��������ܹ�����Ҫ�����е�·�϶����û��ƣ��������Ҫ��̫��Ǯ�Ļ����ǹ����˲�������һ�صġ�����������ƻ����߲����󳼣�����������ֳ�����ôһ��������
1. һ����·Ҫô�����û��ƣ�Ҫô�������û��ƣ�����ѡ�����е�ĳһ�β��ã�
2. ����û�е�·ͨ���׶�����������Ϊһ��ͨ���׶��ĵ�·���û��ƣ�
3. ���в��û��Ƶĵ�·���ɵ���ͼ����ͨ�ģ��Ᵽ֤�������׶���������ͨ��ֻ�߲����˻��Ƶĵ�·�������еĻ��������ꣻ 
4. ���ĳ�����У������׶����д��ڵ���2����·ͨ���ӳ��У�Ϊ�˷�ֹ�����˷ѣ����ֻ��ѡ�����е�����·���û��ƣ�
5. ���û��Ƶĵ�·���ܳ����趨һ�����ޡ�
�����������£�������Ҫʹ�ò��û��Ƶĵ�·����Խ��Խ�ã�����������취��

��������:
ÿ�������������1������������

����ĵ�һ����һ��������m��0<m<=9900����ʾ���û��Ƶĵ�·���ܳ��ȵ����ޡ�

����ĵڶ�����һ��������n��n<=100����ʾ���еĸ�����

��������n-1�����룬ÿ������������u��v��d����ʾ�±�Ϊu�ĳ�����һ������Ϊd�ĵ�·ͨ������һ���ӳ���v������0<=u<n��0<=v<n��0<d<=100��
�������:
���һ������������ʾ�ܲ��û��Ƶĵ�·���ȵ����ֵ

��������1:
5
5
0 1 1
0 2 2
0 3 3
0 4 4

�������1:
5
*/
