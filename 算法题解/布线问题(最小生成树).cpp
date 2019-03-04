#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define INF 0x3f3f3f3f

struct Node
{
	int next;
	int r;
	int val;
}node[250005];

struct DIS
{
	int x;
	int d;
 	bool operator < (const DIS &a) const  
    {  
        return d > a.d;  
    } 
}dis;

int head[505]; 
int used[505]; // ��ʹ�õĵ� 
int Distance[505]; // ��ʹ�õĵ㵽��ǰ�����С���� 
int I, m, n;

void insert(int l, int r, int val) // �ߵĲ��� 
{
	node[I].r = r;
	node[I].val = val;
	node[I].next = head[l];
	head[l] = I ++;
}

int GetDis()
{ 	// ��С�����������ȶ����Ż� 
	priority_queue <DIS> dp;
	int i, x, d, r, sum;
	sum = 0;
	dis.x = 1;
	dis.d = 0;
	dp.push(dis);
	while (!dp.empty())
	{
		dis = dp.top();
		dp.pop();
		x = dis.x;
		if (used[x]) continue; 
		used[x] = 1;
		sum += dis.d;
		for (i = head[x]; i != -1; i = node[i].next)
		{
			r = node[i].r;
			d = node[i].val;
			if (!used[r] && d < Distance[r]) // δʹ�ò���x�㵽��ǰ��ľ���С��֮ǰ�ľ��룬����� 
			{
				Distance[r] = d;
				dis.x = r;
				dis.d = d;
				dp.push(dis);
			}
		}
	}
	return sum;
}

int main()
{
	int i, t, l, r, val, x, Min;
	cin >> t;
	while (t --)
	{
		cin >> m >> n;
		I = 0;
		Min = INF;
		memset(head, -1, sizeof(head));
		memset(used, 0, sizeof(used));
		memset(Distance, INF, sizeof(Distance));
		for (i = 1; i <= n; i ++)
		{
			cin >> l >> r >> val;
			insert(l, r, val);
			insert(r, l, val);
		}
		for (i = 1; i <= m; i ++)
		{
			cin >> x;
			if (x < Min)
				Min = x;
		}
		cout << GetDis()+Min << endl;
	} 
	return 0;
}
/*
����
������ѧԺҪ�����õ���·���죬����У��Ҫ�����ʦ��Ƴ�һ�ֲ��߷�ʽ���ò��߷�ʽ��Ҫ��������������
1�������е�¥�����ϵ硣
2�����õ��߻�������
����
��һ����һ������n��ʾ��n��������ݡ�(n<5)
ÿ��������ݵĵ�һ������������v,e.
v��ʾѧУ��¥���ܸ���(v<=500)
����e���ÿ������������a,b,c��ʾa��b֮�������������·����Ϊc(c<=100)����������¥�����û��ָ�����ѣ����ʾ������¥ֱ����ͨ��Ҫ����̫����߲�������ͨ��
����1�����v������,���е�i������ʾ�ӵ�i��¥���ߵ���繩����ʩ����Ҫ�ķ��á�( 0<e<v*(v-1)/2 )
��¥�ı�Ŵ�1��ʼ�������ڰ�ȫ���⣬ֻ��ѡ��һ��¥���ӵ���繩���豸��
���ݱ�֤���ٴ���һ�ַ�������Ҫ��
���
ÿ������������һ��������,��ʾ��������У��Ҫ�����·����С���ѡ�
��������
1
4 6
1 2 10
2 3 10
3 1 10
1 4 1
2 4 1
3 4 1
1 3 5 6
�������
4
*/
