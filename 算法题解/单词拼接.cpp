#include <iostream>
#include <algorithm> 
#include <cstring>
using namespace std;

struct Node
{
	string s;
	char l;
	char r;
	bool choose;
}a[1005];

int n;
string s;
int b[27]; // ��'a'+b[i]��ͷ�ĵ��� 
int c[27]; // ��'a'+c[i]��β�ĵ��� 

bool cmp(Node x, Node y)
{
	return x.s < y.s;
}

bool CanConCat()
{
	int i;
	int num = 0;
	for (i = 0; i < 26; i ++)
	{
		if (abs(b[i]-c[i]) == 1)
		{
			num ++;
			if (num > 2) // ��Ⱥͳ������Ϊһ�ĵ㳬������ 
				return false;
		}
		if (abs(b[i]-c[i]) > 1) // ��Ⱥͳ���������1 
			return false;
	}
	return true;
}

bool dfs(char l, int num)
{
	int i;
	// ����Ϊnʱ��˵���ҵ��� 
	if (num == n)
		return true;
	for (i = 1; i <= n && a[i].l <= l; i ++)
	{
		if (!a[i].choose && a[i].l == l)
		{
			a[i].choose = true;
			if (dfs(a[i].r, num+1))
			{
				s = a[i].s+'.'+s;
				return true;
			}
			a[i].choose = false;
		}
	}
	return false;
}

void FindConcat()
{
	int i, j, l;
	l = 0;
	s = "";
	sort (a+1, a+n+1, cmp);
	// ������γɻ���������С����ĸΪ��� 
	// ��������γɻ����ҵ���ȱȳ��ȴ�1�ĵ���Ϊ��� 
	while (!b[l]) l ++;
	for (i = 0; i < 26; i ++)
	{
		if (b[i] > c[i])
		{
			l = i;
			break;
		}
	}
	// Ѱ������㿪ʼ�����ճ�����Ϊn�Ĵ� 
	if (dfs(l+'a', 0))
	{
		s = s.erase(s.length()-1);
		cout << s << endl;
	}
	else
	{
		cout << "***" << endl;
	}
}

int main()
{
	int t, i, len;
	cin >> t;
	while (t --)
	{
		cin >> n;
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		for (i = 1; i <= n; i ++)
		{
			cin >> a[i].s;
			a[i].choose = false;
			len = a[i].s.length();
			a[i].l = a[i].s[0];
			a[i].r= a[i].s[len-1];
			b[a[i].s[0]-'a'] ++;
			c[a[i].s[len-1]-'a'] ++;
		}
		if (CanConCat()) // �ų�������l��r�㲻���γ�ŷ����·����� 
		{				 // ��ȳ������ܴ��ڶ�������ȳ���Ϊһ�ĵ�ֻ����0����2�� 
			FindConcat();
		}
		else
		{
			cout << "***" << endl;
		}
	}
	return 0;
}
/*
����
����һЩ���ʣ������ж��ܷ��������β����������һ����

ǰһ�����ʵĽ�βӦ������һ�����ʵĵ���ĸ��ͬ��

��

aloha

dog

arachnid

gopher

tiger

rat

 

����ƴ�ӳɣ�aloha.arachnid.dog.gopher.rat.tiger

����
��һ����һ������N(0<N<20)����ʾ�������ݵ�����
ÿ��������ݵĵ�һ����һ������M,��ʾ���������������M(2<M<1000)��������ͬ�ĵ��ʣ�����M�У�ÿ����һ�����Ȳ�����30�ĵ���,����ȫ����Сд��ĸ��ɡ�
���
�������ƴ�ӷ��������������ƴ�ӷ������ֵ�����С�ķ�����(��������֮�����һ��Ӣ�ľ��".")
���������ƴ�ӷ����������
***
3
5
asldfjowiefjoa
dajdoiwejfob
ajofwirejfoiwc
cseoiwfjwoeid
bwoeifjwiooia
6
aloha
arachnid
dog
gopher
rat
tiger
3
oak
maple
elm
*/ 
