#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <stack>
using namespace std;

char s[1005];
stack <double> num;
stack <char> ch;

int priority(char a)
{
	if (a == '*' || a == '/')
		return 2;
	if (a == '+' || a == '-')
		return 1;
	return 0;
}

void calc()
{
	char a = ch.top();
	ch.pop();
	double c = num.top();
	num.pop();
	double b = num.top();
	num.pop();
	switch (a)
	{
		case '+':
			num.push(b+c);
			break;
		case '-':
			num.push(b-c);
			break;
		case '*':
			num.push(b*c);
			break;
		case '/':
			num.push(b/c);
			break;
	}
}

int main()
{
	int i, t, len;
	cin >> t;
	while (t --)
	{
		scanf("%s", &s);
		len = strlen(s);
		for (i = 0; i <= len-1; i ++)
		{
			// ���Ϊ���֣�������ѹ��numջ�� 
			if (isdigit(s[i]))
			{
				num.push(atof(&s[i]));
				while (isdigit(s[i]) || s[i] == '.') i ++;
				i --;
			}
			else
			{
				if (s[i] == '(')
					ch.push(s[i]);
				// ���Ϊ���������������ֵ����� 
				else if (s[i] == ')')
				{
					while (ch.top() != '(')
					{
						calc();
					}
					ch.pop();
				}
				// �����һλ�������ȼ����ȴ�λС������һλ��ʼ���ν����ȼ�����
				// ��λС������� �������-+��--��/*��//�ĳ��� 
				else if (!ch.empty() && priority(ch.top()) >= priority(s[i]))
				{
					while (!ch.empty() && priority(ch.top()) >= priority(s[i])) 
						calc();
					ch.push(s[i]);
				}
				else
					ch.push(s[i]);
			}
		}
		printf("%.2f\n", num.top());
		num.pop();
		ch.pop();
	}
	return 0;                                                                                      
} 
