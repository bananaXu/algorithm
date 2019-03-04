#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <cmath>
#include <vector> 
#include <queue>
#include <ctype.h>
#include <cfloat>
using namespace std;

int main()
{
	double k,m,t;
	    cout << sizeof(int) <<" " << sizeof(long long) <<" " << sizeof(float) <<" " << sizeof(double) << endl;  
    cout << "int 类型能存储的最大值和最小值" << endl;    
    cout << "INT_MAX = " << INT_MAX << endl;    
    cout << "INT_MIN = " << INT_MIN << endl;    
    cout << "long long 类型能存储的最大值和最小值" << endl;    
    cout << "LONG_MAX = " << LLONG_MAX << endl;    
    cout << "LONG_MIN = " << LLONG_MIN << endl;      
    cout << "float 类型能存储的最大值和最小值" << endl;    
    cout << "FLT_MAX = " << FLT_MAX << endl;    
    cout << "FLT_MIN = " << FLT_MIN << endl;    
    cout << "double 类型能存储的最大值和最小值" << endl;    
    cout << "DBL_MAX = " << DBL_MAX << endl;    
    cout << "DBL_MIN = " << DBL_MIN << endl; 
	cin>>t;
	while(t--)
	{
		cin>>k>>m;
		int a = pow(10.0,double(log10(m)/k));
		while(pow(a+1,k) <= m)    ++ a;
		cout<<a<<endl;
	}
	return 0;
} 
/*
描述
在学习循环的时候，我们都练习过利用循环计算a的k次方。现在给定整数k和一个整数m，
请你求出对应的整数a，使得a的k次方是不超过m并且最接近m的数值。 
输入
一个整数T表示测试组数。
对于每组测试数据：
给定两个整数k和m 

数据范围：
1 <= T <= 20
1 <= k <= 10^9
0 <= a <= 10^9
0 <= M <= 10^100
输出
对于每组数据，输出一个整数a占一行。
*/
