#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

string s;
int len;

double getres(int l, int r)
{
	int i, j, num, m;
	double a = 1.0;
	double b;
	int p = 1;
	char x;
	// 如果前面有负号 
	if (s[l] == '-')
	{
		l ++;
		p = -1;
	}
	i = l;
	// 找到表达式最外层第一个加号或减号 
	while (s[i] != '+' && s[i] != '-' && i != r+1)
	{
		if (s[i] == '(')
		{
			num = 1;
			while (num)
			{
				i ++;
				if (s[i] == '(')
					num ++;
				if (s[i] == ')')
					num --;
			}
		}
		i ++;
	}
	// 如果没到结尾，将表达式分成两段计算 
	if (i != r+1 && s[i] == '+')
		return p*getres(l, i-1)+getres(i+1, r);
	if (i != r+1 && s[i] == '-')
		return p*getres(l, i-1)+getres(i, r);
 	// 到了文件结尾，那么表达式最外层全为乘或除 
	i = l;
	x = '*';
	while (i != r+1)
	{
		// 如果有括号，计算括号里面的结果 
		if (s[i] == '(')
		{
			m = i;
			num = 1;
			while (num)
			{
				i ++;
				if (s[i] == '(')
					num ++;
				if (s[i] == ')')
					num --;
			}
			b = getres(m+1, i-1);
			i ++;
		}
		// 如果是数字，直接获取数字的值 
		else
		{
			b = atof(&s[i]);
			while (i != r+1 && ((s[i] >= '0' && s[i] <= '9') || s[i] == '.')) i ++;
		}
		// 按运算符来得到结果 
		if (x == '*')
			a *= b;
		else
			a /= b;
	 	// 如果到了结尾返回得到的值 
		if (i == r+1)
			return a*p;
		x = s[i];
		i ++;
	}
}

int main()
{
	double k;
	int t;
	cin >> t;
	while (t --)
	{
		cin >> s;
		len = s.length();
		k = getres(0, len-2);
		printf("%.2f\n", k);
	}
	return 0;
}
/*
50
1.000+2/4=
((1.5+2*3.5/2.0)*5.2)/2+3.5=
(5*(2+0.3)/0.5)-50.1=
(1/4-5/6+1/3+2/3)/1/2=
(2/2-4*3/2)=
1.01-2=
(1+2)/4=
((1+2)/4+(3-5))*2=
1.000+2/4=
((1+2)*5+1)/4=
1-2+3=
1+3-2=
1-2*3-3+1=

描述
ACM队的mdd想做一个计算器，但是，他要做的不仅仅是一计算一个A+B的计算器，他想实现随便输入一个表达式都能求出它的值的计算器，现在请你帮助他来实现这个计算器吧。
比如输入：“1+2/4=”，程序就输出1.50（结果保留两位小数）
输入
第一行输入一个整数n，共有n组测试数据（n<10)。
每组测试数据只有一行，是一个长度不超过1000的字符串，表示这个运算式，每个运算式都是以“=”结束。这个表达式里只包含*+-/与小括号这几种符号。其中小括号可以嵌套使用。数据保证输入的操作数中不会出现负数。
数据保证除数不会为0
输出
每组都输出该组运算式的运算结果，输出结果保留两位小数。
样例输入
2
1.000+2/4=
((1+2)*5+1)/4=
样例输出
1.50
4.00
*/
