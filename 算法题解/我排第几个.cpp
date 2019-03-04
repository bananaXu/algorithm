#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int a[13];

int lowbit(int x)
{
	return x&-x;
}

int getsum(int x)
{
	int sum = 0;
	while (x)
	{
		sum += a[x];
		x -= lowbit(x);
	}
	return sum;
}

int add(int x)
{
	while (x <= 12)
	{
		a[x] ++;
		x += lowbit(x);
	}
}

int main()
{
	int i, n, sum, x;
	int f[12] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 
				362880, 3628800, 39916800};
    char s[12];
    scanf("%d", &n);
    while (n --)
    {
    	scanf("%s", &s);
    	sum = 1;
    	memset(a, 0, sizeof(a));
    	for (i = 0; i < 12; i ++)
    	{
    		x = s[i]-'a'+1;
	    	add(x);
	    	sum += (x-getsum(x))*f[11-i];
	    }
	    printf("%d\n", sum);
    }
	return 0;
} 
/*
// 康托展开 X=a[n]*(n-1)!+a[n-1]*(n-2)!+...+a[i]*(i-1)!+...+a[1]*0!
// a[n] 表示当前未出现的元素中是排在第几个(从第0个开始) 
描述
现在有"abcdefghijkl”12个字符，将其所有的排列中按字典序排列，给出任意一种排列，说出这个排列在所有的排列中是第几小的？

输入
第一行有一个整数n（0<n<=10000）;
随后有n行，每行是一个排列；
输出
输出一个整数m，占一行，m表示排列是第几位；
样例输入
3
abcdefghijkl
hgebkflacdji
gfkedhjblcia
样例输出
1
302715242
260726926
*/
