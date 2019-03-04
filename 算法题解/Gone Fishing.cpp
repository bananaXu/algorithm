#include <iostream>
using namespace std;

int n, h;
int f[27];
int d[27];
int t[27];

void getmax()
{
	int i, j, sum, time, Max, MaxId, m, len;
	bool w;
	int a[27];
	int b[27];
	int c[27] = {0};
	m = 0;
	for (i = 1; i <= n; i ++)
	{
		sum = 0;
		time = h*60;
		for (j = 1; j <= i; j ++)
		{
			a[j] = f[j];
			if (i != j)
			{
				time -= t[j]*5;
			}
			b[j] = 0;
		}
		while (time >= 5)
		{
			time -= 5;
			Max = -1;
			MaxId = 0;
			for (j = 1; j <= i; j ++)
			{
				if (a[j] > Max)
				{
					Max = a[j];
					MaxId = j;
				}
			}
			if (Max-d[MaxId] > 0)
			{
				a[MaxId] = Max-d[MaxId] ;
			}
			else
			{
				a[MaxId] = 0;
			}
			b[MaxId] += 5;
			sum += Max;
		}
		if (sum > m)
		{
			m = sum;
			for (j = 1; j <= i; j ++)
			{
				c[j] = b[j];
				len = i;
			}
		}
		else if (sum == m)
		{
			w = false;
			for (j = 1; j <= i; i ++)
			{
				if (b[i] > c[i])
				{
					w = true;
					break;
				}
				else if (b[i] < c[i])
					break;
			}
			if (w)
			{
				for (j = 1; j <= i; j ++)
				{
					c[j] = b[j];
					len = i;
				}	
			}
		}
	}
	for (i = 1; i <= len; i ++)
	{
		cout << c[i];
		if (i != len)
			cout << ", ";
	}
	for (i = len+1; i <= n; i ++)
	{
		cout << ", 0";
	}
	cout << endl;
	cout << "Number of fish expected: " << m << endl << endl;
}

int main() 
{
	int i;
	while (1)
	{
		cin >> n;
		if (!n)
			break;
		cin >> h;
		for (i = 1; i <= n; i ++)
			cin >> f[i];
		for (i = 1; i <= n; i ++)
			cin >> d[i];
		for (i = 1; i <= n-1; i ++)
			cin >> t[i];
		getmax();
	}
	return 0;
}
/*
描述
John is going on a fishing trip. He has h hours available (1 <= h <= 16), and there
 are n lakes in the area (2 <= n <= 25) all reachable along a single, one-way road.
 John starts at lake 1, but he can finish at any lake he wants. He can only travel
 from one lake to the next one, but he does not have to stop at any lake unless he
 wishes to. For each i = 1,...,n - 1, the number of 5-minute intervals it takes to
 travel from lake i to lake i + 1 is denoted ti (0 < ti <=192). For example, t3 = 4 
 means that it takes 20 minutes to travel from lake 3 to lake 4. To help plan his
 fishing trip, John has gathered some information about the lakes. For each lake i,
 the number of fish expected to be caught in the initial 5 minutes, denoted 
 fi( fi >= 0 ), is known. Each 5 minutes of fishing decreases the number of fish 
 expected to be caught in the next 5-minute interval by a constant rate of di (di >= 0). 
 If the number of fish expected to be caught in an interval is less than or equal to di ,
 there will be no more fish left in the lake in the next interval. To simplify the planning,
 John assumes that no one else will be fishing at the lakes to affect the number of fish
 he expects to catch. 
Write a program to help John plan his fishing trip to maximize the number of fish expected
 to be caught. The number of minutes spent at each lake must be a multiple of 5. 
输入
You will be given a number of cases in the input. Each case starts with a line containing n.
This is followed by a line containing h. Next, there is a line of n integers specifying fi 
(1 <= i <=n), then a line of n integers di (1 <=i <=n), and finally, a line of n - 1 integers
ti (1 <=i <=n - 1). Input is terminated by a case in which n = 0. 
输出
For each test case, print the number of minutes spent at each lake, separated by commas, for the
plan achieving the maximum number of fish expected to be caught (you should print the entire plan
on one line even if it exceeds 80 characters). This is followed by a line containing the number 
of fish expected. 
If multiple plans exist, choose the one that spends as long as possible at lake 1, even if no fish
are expected to be caught in some intervals. If there is still a tie, choose the one that spends
as long as possible at lake 2, and so on. Insert a blank line between cases. 
样例输入
2 
1 
10 1 
2 5 
2 
4 
4 
10 15 20 17 
0 3 4 3 
1 2 3 
4 
4 
10 15 50 30 
0 3 4 3 
1 2 3 
0 
样例输出
45, 5 
Number of fish expected: 31 

240, 0, 0, 0 
Number of fish expected: 480 

115, 10, 50, 35 
Number of fish expected: 724 
*/
