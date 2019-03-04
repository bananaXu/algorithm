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
#include <cstdlib>
#include <windows.h>
#include <ext/hash_map>
#include <ext/hash_set>
using namespace std;
using namespace __gnu_cxx;

int main()
{
	time_t start, end;
 	time(&start);
	Sleep(1005);
	time(&end);
	cout << difftime(end, start) << endl;
	
	clock_t start1, end1;
	start1 = clock();
	Sleep(1005);
	end1 = clock();
	cout << end1-start1 << endl;
	
	double start2 = GetTickCount();
	Sleep(1005);
	double end2 = GetTickCount();  
	cout << end2-start2 << endl;
	
	SYSTEMTIME start3;
	string s[] = {"星期日", "星期一", "星期二", "星期三", "星期四", "星期五", "星期六"};
	GetLocalTime(&start3);
	cout<< start3.wYear << "-" << start3.wMonth << "-" << start3.wDay << " "
		<< start3.wHour << ":" << start3.wMinute << ":" << start3.wSecond 
		<< " " << s[start3.wDayOfWeek] << endl;
		
	time_t the_time;
	time(&the_time);
	cout << the_time << endl;
	
 	LARGE_INTEGER m_nFreq;  
    LARGE_INTEGER m_nBeginTime;  
    LARGE_INTEGER nEndTime;  
    QueryPerformanceFrequency(&m_nFreq); // 获取时钟周期  
    QueryPerformanceCounter(&m_nBeginTime); // 获取时钟计数  
    Sleep(105);  
    QueryPerformanceCounter(&nEndTime);  
    cout << (double)(nEndTime.QuadPart-m_nBeginTime.QuadPart)*1000/m_nFreq.QuadPart << endl; 
	
 	LARGE_INTEGER m_nFreq1;  
    LARGE_INTEGER m_nBeginTime1;  
    LARGE_INTEGER nEndTime1;  
    QueryPerformanceFrequency(&m_nFreq1); // 获取时钟周期  
    QueryPerformanceCounter(&m_nBeginTime1); // 获取时钟计数  
    for (int i = 0; i < 100000000; ++ i)
	for (int j = 0; j < 10; ++ j); 
    QueryPerformanceCounter(&nEndTime1);  
    cout << (double)(nEndTime1.QuadPart-m_nBeginTime1.QuadPart)*1000/m_nFreq1.QuadPart << endl; 

 	LARGE_INTEGER m_nFreq2;  
    LARGE_INTEGER m_nBeginTime2;  
    LARGE_INTEGER nEndTime2;  
    QueryPerformanceFrequency(&m_nFreq2); // 获取时钟周期  
    QueryPerformanceCounter(&m_nBeginTime2); // 获取时钟计数  
    for (int i = 0; i < 100000000; i ++)
    for (int j = 0; j < 10; j ++); 
    QueryPerformanceCounter(&nEndTime2);  
    cout << (double)(nEndTime2.QuadPart-m_nBeginTime2.QuadPart)*1000/m_nFreq2.QuadPart << endl; 
	return 0;
}
