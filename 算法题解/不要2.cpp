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
�㷨˼�룺
* *
* *
    * *
	* *
������ͼ��Ϊһ����λ
����ʣ�µľ������� 
*/

int main()
{
	int n, m;
	cin >> n >> m;
	int sum = 0;
	sum += ((n>>2)*(m>>2))<<3;
	sum += (n%4)*(m>>2)*2+(n>>2)*(m%4)*2;
	sum += (n%4 > 2 ? 2 : n%4)*(m%4 > 2 ? 2 : m%4);
	if (n%4 == 3 && m%4 == 3)
		sum ++;
	cout << sum << endl;
	return 0;
}
/*
��Ŀ����
����С����һ��W*H��������ӣ�������б��Ϊ0~H-1��������б��Ϊ0~W-1��ÿ������������Է�һ�鵰�⣬�������鵰���ŷ����þ��벻�ܵ���2��
����������������(x1,y1),(x2,y2)��ŷ����þ���Ϊ:
( (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2) ) ������ƽ����
С����֪�������ԷŶ��ٿ鵰������������
��������:
ÿ������������񳤿�W,H���ÿո�ָ�.(1 �� W��H �� 1000)
�������:
���һ�������Էŵĵ�����
ʾ��1
����
3 2
���
4
*/
