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

/*
������ 
y = k+1, x = t*(k+1)+k
y = k+2, x = t*(k+2)+k || x = t*(k+2)+k+1
y = k+3, x = t*(k+3)+k || x = t*(k+3)+k+1 || x = t*(k+3)+k+2
...
y = n, x = k, k+1, ... n-1
��ôx/(k+t)*t+ʣ���x%(k+t)�д��ڵ���k�ľ�������(k == 0ʱ������k) 
*/

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	long long sum = 0;
	if (k == 0)
		sum = (long long)n*n;
	else
	{
		for (int i = 1; i <= n-k; i ++)
		{
			int t = n%(k+i);
			sum += n/(k+i)*i+(t >= k ? t-k+1 : 0);
		}
	}
	printf("%lld\n", sum);
	return 0;
}
/*
ţţ��ǰ����ʦ����õ���һ������������(x, y), ţţ�������Ǿ����Ƕ����ˡ�
����ţţ�ǵ���ʦ���߹���x��y��������n, ����x����y���������ڵ���k��
ţţϣ�����ܰ�������һ���ж��ٸ����ܵ����ԡ�

��������:
�����������������n,k(1 <= n <= 10^5, 0 <= k <= n - 1)��


�������:
����ÿ����������, ���һ����������ʾ���ܵ�����������

��������1:
5 2

�������1:
7

����˵��1:
����������������(2,3),(2,4),(2,5),(3,4),(3,5),(4,5),(5,3)
*/
