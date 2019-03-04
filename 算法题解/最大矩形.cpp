#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdio>
#include <string>
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
#include <cstdlib>
#include <windows.h>
#include <bitset>
#include <sstream>
#include <ext/hash_map>
#include <ext/hash_set>
using namespace std;
using namespace __gnu_cxx;

int largestRectangleArea(vector<int> &height) 
{
    int Max = 0;
    stack <int> st;
    for (int i = 0; i < height.size(); i ++)
    {
        while (!st.empty() && height[st.top()] >= height[i])
        {
            int h = height[st.top()];
            st.pop();
            Max = max(Max, h*(st.empty() ? i: i-st.top()-1));
        }
        st.push(i);
    }
    while (!st.empty())
    {
        int h = height[st.top()];
        st.pop();
        Max = max(Max, h*(int)(st.empty() ? height.size() : height.size()-st.top()-1));
    }
    return Max;
}

int main()
{
	vector <int> h;
	int a[] = {2,1,5,6,2,3};
	for (int i = 0; i < sizeof(a)/4; i ++)
		h.push_back(a[i]);
	cout << largestRectangleArea(h) << endl;
	return 0;
} 
/*
题目大意，一排高度不相等的建筑，找出图中最大的矩形 
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
find the area of largest rectangle in the histogram.
Above is a histogram where width of each bar is 1, given height =[2,1,5,6,2,3].
The largest rectangle is shown in the shaded area, which has area =10unit.
For example,
Given height =[2,1,5,6,2,3],
return10.
*/
