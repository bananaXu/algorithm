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

#define M 500

void muliti(int a[], int b[], int &lena, int lenb)
{
	int c[M] = {0};
	for (int i = 0; i < lena; i ++)
	{
		for (int j = 0; j < lenb; j ++)
			c[i+j] += a[i]*b[j];
	}
	lena = lena+lenb-1;
	memcpy(a, c, lena*sizeof(int));
	for (int i = 0; i < lena; i ++)
	{
		if (i == lena-1 && a[i] >= 10)
			lena ++;
		a[i+1] += a[i]/10;
		a[i] %= 10;
	}
}

int main()
{
	int a[M];
	int b[M];
	char c[M];
	int n;
	while (~scanf("%s%d", &c, &n))
	{
		string s = c;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		int f = s.find('.');
		if (f == -1)
			f = s.length()-1;
		int lenDec = (s.length()-f-1)*n;
		if (f != s.length()-1)
			s.erase(f, 1);
		int len = s.length();
		for (int i = 0; i < len; i ++)
			a[len-i-1] = s[i]-'0';
		b[0] = 1;
		int lenb = 1;
		while (n)
		{
			if (n&1)
				muliti(b, a, lenb, len);
			muliti(a, a, len, len);
			n >>= 1;
		}
		int i = lenb-1;
		while (b[i] == 0 && i >= lenDec) i --;
		for (int j = i; j >= lenDec; j --)
			printf("%d", b[j]);
		i = 0;
		while (b[i] == 0 && i < lenDec) i ++;
		if (i < lenDec)
		{
			printf(".");
			for (int j = lenDec-1; j >= i; j --)
				printf("%d", b[j]);
		}
		printf("\n");
	}
	return 0;
} 
/*
求高精度幂
时间限制：3000 ms  |  内存限制：65535 KB
难度：2
描述
对数值很大、精度很高的数进行高精度计算是一类十分常见的问题。比如，对国债进行计算就是属于这类问题。 

现在要你解决的问题是：对一个实数R( 0.0 < R < 99.999 )，要求写程序精确计算 R 的 n 次方(Rn)，其中n 是整数并且 0 < =n <= 25。

输入
输入有多行，每行有两个数R和n，空格分开。R的数字位数不超过10位。
输出
对于每组输入，要求输出一行，该行包含精确的 R 的 n 次方。输出需要去掉前导的 0 后不要的 0 。如果输出是整数，不要输出小数点。
样例输入
95.123 12
0.4321 20
5.1234 15
6.7592  9
98.999 10
1.0100 12
样例输出
548815620517731830194541.899025343415715973535967221869852721
.00000005148554641076956121994511276767154838481760200726351203835429763013462401
43992025569.928573701266488041146654993318703707511666295476720493953024
29448126.764121021618164430206909037173276672
90429072743629540498.107596019456651774561044010001
1.126825030131969720661201
*/
