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

int main()
{
	int l, r;
	scanf("%d%d", &l, &r);
	int sum = (r-l+1)/3*2;
	int t = (r-l+1)%3;
	if (t == 1)
		sum += r%3 == 1 ? 0 : 1;
	else if (t == 2)
	{
		sum += r%3 == 1 ? 0 : 1;
		sum += (r-1)%3 == 1 ? 0 : 1;
	}
	printf("%d\n", sum);
	return 0;
} 
/*
СQ�õ�һ�����������: 1, 12, 123,...12345678910,1234567891011...��
����СQ�����ܷ�3����������ʺܸ���Ȥ��
СQ����ϣ�����ܰ�������һ�´����еĵ�l������r��(�����˵�)�ж��ٸ������Ա�3������

��������:
���������������l��r(1 <= l <= r <= 1e9), ��ʾҪ�����������ˡ�


�������:
���һ������, ��ʾ�������ܱ�3���������ָ�����

��������1:
2 5

�������1:
3

����˵��1:
12, 123, 1234, 12345...
����12, 123, 12345�ܱ�3������
*/
