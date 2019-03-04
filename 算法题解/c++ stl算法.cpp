#include <iostream>
#include <iomanip>
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
#include <list>
#include <ext/hash_map>
#include <ext/hash_set>
using namespace std;
using namespace __gnu_cxx;

void output(vector <int> a)
{
	for (int i = 0; i < a.size(); i ++)
		cout << a[i] << " ";
	cout << endl;
}

bool Greater(int a)
{
	return a < 100;
}

int main()
{
	vector <int> a, b, c;
	a.push_back(1), a.push_back(2), a.push_back(3), b.push_back(2), b.push_back(3), b.push_back(4);
	c.resize(a.size()+b.size());
	merge(a.begin(), a.end(), b.begin(), b.end(), c.begin()); // �ϲ������������е�����������
	// inplace_merge() �ϲ�ͬһ�������������򲿷� 
	// a.insert(a.end(), b.begin(), b.end());// ��b���в��뵽a���к��� 
	unique(c.begin(), c.end()); // ȥ�������ظ���Ԫ��(��Ԫ�طŵ�����)
	unique_copy(c.begin(), c.end(), back_inserter(a)); // ��ȥ�غ��Ԫ�ط�����һ�����ϣ� 
	// c.erase(unique(c.begin(), c.end(), cmp1), c.end()); //  ����ȥ�������ظ���Ԫ��
	set_union(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin()));// ���������򼯺ϲ���������������� 
	set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin())); // ���������򼯺Ͻ����������������
	set_difference(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin())); // ���������Ͳ�������������
	make_heap(c.begin(), c.end()); // ��������Ԫ���Ƴɶ����ƣ��ӵ���������������< 
	pop_heap(c.begin(), c.end()); // �����Ѷ�Ԫ��
	sort_heap(c.begin(), c.end()); // ����Ԫ������
	sort(c.begin(), c.end()); // �����㷨
	stable_sort(c.begin(), c.end()); // �ȶ������㷨
	upper_bound(c.begin(), c.end(), 5); // ���ص�һ������5(value)��iteration
	lower_bound(c.begin(), c.end(), 5); // ���ص�һ�����ڵ���5(value)��iteration
	partition(c.begin(), c.end(), Greater); // ��������Χ������Ԫ�طֳ���������, ���㺯���ķ�ǰ�棬���ȶ�
	stable_partition(c.begin(), c.end(), Greater); // �ȶ�����
	reverse(c.begin(), c.end()); // ��������Ԫ�ط�ת
	reverse_copy(a.begin(), a.end(), back_inserter(c)); // ��a��Ԫ�ط�ת�����c���棬a��Ԫ��λ�ò���
	remove(c.begin(), c.end(), 5); // ��������ָ����Χ�ڵ���5(value)��Ԫ��ɾ��(�ƶ�������β)�������׸�ɾ��Ԫ�ص�iteration
	remove_if(c.begin(), c.end(), Greater); // ����remove
	remove_copy_if(c.begin(), c.end(), back_inserter(a), Greater); // ����ƥ��Ԫ�ز�����һ������
	replace(c.begin(), c.end(), 10, 5); // ��ָ����Χ������Ϊ10(oldvalue)��Ϊ5(newvalue)
	//find find_first_of
	next_permutation(c.begin(), c.end()); // ��һ����,�����ڷ���false 
	prev_permutation(c.begin(), c.end()); // ��һ����,�����ڷ���false 
	output(c);
	
 	return 0;
} 
