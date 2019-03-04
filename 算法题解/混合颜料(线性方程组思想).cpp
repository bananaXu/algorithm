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

vector <int> v;

int getlen(int x)
{
	int t = (int)(log(x)/log(2)+1e-8);
	return (1<<t);
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	n --;
	int sum = 0;
	while (n > 0 && v[n])
	{
		int t = getlen(v[n]);
		for (int i = 0; i < n; i ++)
		{
			if (v[i]&t)
				v[i] ^= v[i+1];
		}
		sum ++;
		n --;
		v.pop_back();
		sort(v.begin(), v.end());
	}
	if (v[n])
		sum ++;
	cout << sum << endl;
	return 0;
}
/*
��Ŀ����
����n����������ѡ���ٵ������ܹ����������� 
�㷨˼�룺
������ 
�ҳ���������λ����������һλΪ1�������������һ�������ͱ��0��
Ȼ��������������ôҲ����������������������ɾ����������һ
ֱ�����ֻ��һ������������������0 
*/
