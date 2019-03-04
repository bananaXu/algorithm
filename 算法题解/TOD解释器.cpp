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

string s[205];
int n = 0;
map <string, int> Map;

void TOD(int l, int r, int t)
{
	while (t --)
	{
		for (int i = l; i <= r; i ++)
		{
			int x, len = s[i].length();
			if (len > 6 && s[i].substr(0, 5) == "Loop(")
			{
				int j = i, z = 1;
				while (z)
				{
					if (s[++ j].length() > 6 && s[j].substr(0, 5) == "Loop(")
						z ++;
					else if (s[j] == "End")
						z --;
				}
				TOD(i+1, j-1, Map[s[i].substr(5, len-6)]);
				i = j;
			}
			else if (s[i].substr(len-2, 2) == "++")
				Map[s[i].substr(0, len-2)] ++;
			else if (s[i] == "show")
			{
				i ++;
				printf("%d\n", Map[s[i]]);
			}
			else
			{
				if (s[i][len-1] == '0' && s[i][len-2] == '=')
					Map[s[i].substr(0, len-2)] = 0;
				else
				{
					int y = s[i].find_first_of('=');
					Map[s[i].substr(0, y)] = Map[s[i].substr(y+1, len-y-1)];
				}
			}
		}
	}
}

int main()
{
	while (cin >> s[++ n] && s[n] != "$");
	TOD(1, n-1, 1);
	return 0;
}
/*
描述
有这样一种编程语言TOD：
1 只有int型数据且负数是不合法的
2 合法的运算如下：
   A．给一个变量清零 V=0；
   B．将一个变量赋给另一变量 V1 = V2；
   C．变量自增 V++；
   D．循环并且可以嵌套使用
            i.e. Loop(v1)
                            ……..
                            Loop(v2)
                             ………
                           End
    .                      ……..
                   End

i.e 下面的情况循环执行了两次（请仔细理解）
        V=0
        V++
        V++
        Loop(V)
               V=0
        End

注意：1 常量不能出现“0”以外的数字
           2 程序不含任何比较和if语句

           3 第一次出现的变量全部当成0

除了以上四种运算外，还可以用show a输出变量a的值。

比如下面的程序段

a=0
b=0
a++
Loop(a)
b++
End
show a
show b
$

则程序的输出是

1

1

现在你要做的事就是，读入一段tod程序，并对其进行解释性执行。

输入
一段合法的TOD程序，并保证每行只有一个语句，行首不会出现空格或者缩进。假设其标识符中只含字母下划线与数字并且首字符不能是数字，且大小写敏感。遇到$表示程序结束。
程序长度不超过200行，运算过程中不会出现大于10000的数。
输出
请解释性执行该段程序，将Tod程序的输出输出出来。
样例输入
a++
a++
P=0
Loop(a)
a=P
P++
End
show a
show P
$
样例输出
1
2
*/ 
