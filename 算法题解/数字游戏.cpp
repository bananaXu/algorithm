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

int a[25];

/*
�㷨˼�룺
���������ǰ����������1~x
��ô������������x+1����ôһ���������x+1
��������Ϊt(1~x+1)��ôһ�������1~x+t�������� 
*/ 

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	sort(a+1, a+n+1);
	int sum = 0;
	for (int i = 1; i <= n; i ++)
	{
		if (a[i] > sum+1)
			break;
		sum += a[i];
	}
	cout << sum+1 << endl;
	return 0;
}
/*
��Ŀ���⣺
��һ�����飬ÿ���������һ�����һ������������ɵ���С���� 
*/
