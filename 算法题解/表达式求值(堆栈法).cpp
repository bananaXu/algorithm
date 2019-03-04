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
			// 如果为数字，将数字压入num栈顶 
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
				// 如果为），将括号里面的值算出来 
				else if (s[i] == ')')
				{
					while (ch.top() != '(')
					{
						calc();
					}
					ch.pop();
				}
				// 如果上一位符号优先级不比此位小，从上一位开始依次将优先级不比
				// 此位小的算出来 避免出现-+或--或/*或//的出现 
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
