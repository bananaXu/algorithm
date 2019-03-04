#include <iostream>
#include <cstring>
using namespace std;

struct Node
{
	int next;
	int r;
}node[300005];

int head[100005];
int pre[100005];
int I = 0;
int n, m;

void insert(int l, int r)
{
	node[I].r = r;
	node[I].next = head[l];
	head[l] = I ++;
}

void dfs(int x)
{
	int i, r;
	for (i = head[x]; i != -1; i = node[i].next)
	{
		r = node[i].r;
		if (!pre[r])
		{
			pre[r] = x;
			dfs(r);
		}
	}
}

int main()
{
	int i, t, l, r;
	cin >> t;
	while (t --)
	{
		cin >> n >> m;
		for (i = 1; i <= n; i ++)
		{
			pre[i] = 0;
			head[i] = -1;
		}
		for (i = 1; i < n; i ++)
		{
			cin >> l >> r;
			insert(l, r);
			insert(r, l);
		}
		dfs(m);
		pre[m] = -1; 
		for (i = 1; i <= n; i ++)
			cout << pre[i] << " ";
		cout << endl;
	}
	return 0;
}
/*
����
��һ�����ĵĹ�������N�����У���N�����м�ֻ��N-1��·�����N�������������������ڣ�Tom�ڵ�S�ų��У������Ÿù���ͼ������֪������Լ�Ҫȥ�ι۵�T�ų��У����뾭����ǰһ�������Ǽ��ų��У������㲻���ظ���·����
����
��һ������һ������M��ʾ�������ݹ���M(1<=M<=5)��
ÿ��������ݵĵ�һ������һ��������N(1<=N<=100000)��һ��������S(1<=S<=100000)��N��ʾ���е��ܸ�����S��ʾ�ι������ڳ��еı��
����N-1�У�ÿ��������������a,b(1<=a,b<=N)����ʾ��a�ų��к͵�b�ų���֮����һ��·��ͨ��
���
ÿ�����������N�������������У���i������ʾ��S�ߵ�i�ų��У�����Ҫ��������һ�����еı�š�������i=Sʱ�������-1��
��������
1
10 1
1 9
1 8
8 10
10 3
8 6
1 2
10 4
9 5
3 7
�������
-1 1 10 10 9 8 3 1 1 8
*/
