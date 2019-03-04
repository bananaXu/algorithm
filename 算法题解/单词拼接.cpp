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
int b[27]; // 以'a'+b[i]开头的点数 
int c[27]; // 以'a'+c[i]结尾的点数 

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
			if (num > 2) // 入度和出度相差为一的点超过两个 
				return false;
		}
		if (abs(b[i]-c[i]) > 1) // 入度和出度相差大于1 
			return false;
	}
	return true;
}

bool dfs(char l, int num)
{
	int i;
	// 长度为n时，说明找到了 
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
	// 如果能形成环，则以最小的字母为起点 
	// 如果不能形成环，找到入度比出度大1的点作为起点 
	while (!b[l]) l ++;
	for (i = 0; i < 26; i ++)
	{
		if (b[i] > c[i])
		{
			l = i;
			break;
		}
	}
	// 寻找以起点开始，最终长度能为n的串 
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
		if (CanConCat()) // 排除由所有l和r点不能形成欧拉回路的情况 
		{				 // 入度出度相差不能大于二，且入度出度为一的点只能有0个或2个 
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
描述
给你一些单词，请你判断能否把它们首尾串起来串成一串。

前一个单词的结尾应该与下一个单词的道字母相同。

如

aloha

dog

arachnid

gopher

tiger

rat

 

可以拼接成：aloha.arachnid.dog.gopher.rat.tiger

输入
第一行是一个整数N(0<N<20)，表示测试数据的组数
每组测试数据的第一行是一个整数M,表示该组测试数据中有M(2<M<1000)个互不相同的单词，随后的M行，每行是一个长度不超过30的单词,单词全部由小写字母组成。
输出
如果存在拼接方案，请输出所有拼接方案中字典序最小的方案。(两个单词之间输出一个英文句号".")
如果不存在拼接方案，则输出
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
