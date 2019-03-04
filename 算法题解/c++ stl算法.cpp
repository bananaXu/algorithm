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
	merge(a.begin(), a.end(), b.begin(), b.end(), c.begin()); // 合并两个有序序列到第三个序列
	// inplace_merge() 合并同一序列中两个有序部分 
	// a.insert(a.end(), b.begin(), b.end());// 将b序列插入到a序列后面 
	unique(c.begin(), c.end()); // 去掉相邻重复的元素(将元素放到后面)
	unique_copy(c.begin(), c.end(), back_inserter(a)); // 将去重后的元素放入另一个集合， 
	// c.erase(unique(c.begin(), c.end(), cmp1), c.end()); //  真正去掉相邻重复的元素
	set_union(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin()));// 将两个有序集合并集插入第三个集合 
	set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin())); // 将两个有序集合交集插入第三个集合
	set_difference(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin())); // 将两个集和差集插入第三个集合
	make_heap(c.begin(), c.end()); // 将集合中元素制成堆形势，加第三个参数可重载< 
	pop_heap(c.begin(), c.end()); // 弹出堆顶元素
	sort_heap(c.begin(), c.end()); // 将堆元素排序
	sort(c.begin(), c.end()); // 排序算法
	stable_sort(c.begin(), c.end()); // 稳定排序算法
	upper_bound(c.begin(), c.end(), 5); // 返回第一个大于5(value)的iteration
	lower_bound(c.begin(), c.end(), 5); // 返回第一个大于等于5(value)的iteration
	partition(c.begin(), c.end(), Greater); // 将给定范围内所有元素分成两个部分, 满足函数的放前面，不稳定
	stable_partition(c.begin(), c.end(), Greater); // 稳定划分
	reverse(c.begin(), c.end()); // 将容器内元素反转
	reverse_copy(a.begin(), a.end(), back_inserter(c)); // 将a中元素反转后插入c后面，a中元素位置不变
	remove(c.begin(), c.end(), 5); // 将容器中指定范围内等于5(value)的元素删除(移动到容器尾)并返回首个删除元素的iteration
	remove_if(c.begin(), c.end(), Greater); // 类似remove
	remove_copy_if(c.begin(), c.end(), back_inserter(a), Greater); // 将不匹配元素插入另一个容器
	replace(c.begin(), c.end(), 10, 5); // 将指定范围内所有为10(oldvalue)变为5(newvalue)
	//find find_first_of
	next_permutation(c.begin(), c.end()); // 下一排列,不存在返回false 
	prev_permutation(c.begin(), c.end()); // 上一排列,不存在返回false 
	output(c);
	
 	return 0;
} 
