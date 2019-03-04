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

map <char, int> Map;

string Max(string a, string b)
{
	string s1 = a, s2 = b;
	int i = 0;
	while ((i = s1.find(' ', i)) != string::npos)
		s1.erase(i, 1);
	while ((i = s1.find("10")) != string::npos)
		s1.replace(i, 2, "T");
	i = 0;
	while ((i = s2.find(' ', i)) != string::npos)
		s2.erase(i, 1);
	while ((i = s2.find("10")) != string::npos)
		s2.replace(i, 2, "T");
	if (s1.length() == s2.length())
	{
		if (Map[s1[0]] > Map[s2[0]])
			return a;
		return b;
	}
	if (s1.length() == 10)
		return a;
	if (s1.length() == 4 && s2.length() != 10)
		return a;
	if (s2.length() == 10)
		return b;
	if (s2.length() == 4 && s1.length() != 10)
		return b;
	return "ERROR";
}

int main()
{
	char a[20];
	gets(a);
	string s = a;
	string s1, s2;
	int i = 0;
	int t = s.find('-');
	s1 = s.substr(0, t);
	s2 = s.substr(t+1, s.length()-t);
	for (int i = 3; i <= 9; i ++)
		Map[i+'0'] = i-2;
	Map['T'] = 8, Map['J'] = 9, Map['Q'] = 10, Map['K'] = 11, Map['A'] = 12, Map['2'] = 13;
	cout << Max(s1, s2) << endl;
	return 0;
}
/*
�˿�����Ϸ���Ӧ�ö��Ƚ���Ϥ�ˣ�һ������54����ɣ���3~A��2��4�ţ�С��1�ţ�����1�š������С�����������ַ����ַ�����ʾ�����У�Сдjoker��ʾС������дJOKER��ʾ������:) 
3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER 
���������ƣ�������֮���á�-�����ӣ�ÿ���Ƶ�ÿ�����Կո�ָ�����-������û�пո��磺4 4 4 4-joker JOKER
��Ƚ������ƴ�С������ϴ���ƣ���������ڱȽϹ�ϵ�����ERROR

��������
��1������ÿ���ƿ����Ǹ��ӣ����ӣ�˳�ӣ�����5�ţ���������ը�����ĸ����Ͷ����е�һ�֣���������������������뱣֤�����ƶ��ǺϷ��ģ�˳���Ѿ���С�������У�
��2������ը���Ͷ������Ժ������ƱȽ�֮�⣬�������͵���ֻ�ܸ���ͬ���͵Ĵ��ڱȽϹ�ϵ���磬���Ӹ����ӱȽϣ������������Ƚϣ��������ǲ���������磺�����Ӳ�ֳɸ��ӣ�
��3����С��������ƽʱ�˽�ĳ���������ͬ�����ӣ����ӣ������Ƚ������С��˳�ӱȽ���С�ƴ�С��ը������ǰ�����е��ƣ�ը��֮��Ƚ������С�������������ƣ�
��4������������Ʋ��������ȵ������

����ʾ��
��1������ը���Ͷ���֮�⣬��������ͬ���ͱȽϡ�
��2�������Ѿ���֤�Ϸ��ԣ����ü�������Ƿ��ǺϷ����ơ�
��3�������˳���Ѿ�������С����������˲�����������.

��������:
���������ƣ�������֮���á�-�����ӣ�ÿ���Ƶ�ÿ�����Կո�ָ�����-������û�пո���4 4 4 4-joker JOKER��


�������:
����������нϴ�����֣��������ӷ����˿���˳�򲻱䣬���Կո��������������ڱȽϹ�ϵ�����ERROR��

��������1:
4 4 4 4-joker JOKER

�������1:
joker JOKER
*/
