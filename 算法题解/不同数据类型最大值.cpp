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
    cout << "int �����ܴ洢�����ֵ����Сֵ" << endl;    
    cout << "INT_MAX = " << INT_MAX << endl;    
    cout << "INT_MIN = " << INT_MIN << endl;    
    cout << "long long �����ܴ洢�����ֵ����Сֵ" << endl;    
    cout << "LONG_MAX = " << LLONG_MAX << endl;    
    cout << "LONG_MIN = " << LLONG_MIN << endl;      
    cout << "float �����ܴ洢�����ֵ����Сֵ" << endl;    
    cout << "FLT_MAX = " << FLT_MAX << endl;    
    cout << "FLT_MIN = " << FLT_MIN << endl;    
    cout << "double �����ܴ洢�����ֵ����Сֵ" << endl;    
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
����
��ѧϰѭ����ʱ�����Ƕ���ϰ������ѭ������a��k�η������ڸ�������k��һ������m��
���������Ӧ������a��ʹ��a��k�η��ǲ�����m������ӽ�m����ֵ�� 
����
һ������T��ʾ����������
����ÿ��������ݣ�
������������k��m 

���ݷ�Χ��
1 <= T <= 20
1 <= k <= 10^9
0 <= a <= 10^9
0 <= M <= 10^100
���
����ÿ�����ݣ����һ������aռһ�С�
*/
