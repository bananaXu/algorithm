#include <iostream>
using namespace std;

int *a = NULL;
int len;

void adjustheap(int i)
{
	int l;
	int r;
	while (1)
	{
		l = (i<<1)+1;
		r = (i<<1)+2;
		if (l > len)
			break;
		if (r > len)
		{
			if (l == len && a[l] > a[i])
				swap(a[l], a[i]);
			break;
		}
		if (a[i] < a[l] && a[i] < a[r])
		{
			if (a[l] > a[r])
			{
				swap(a[l], a[i]);
				i = l;
			}
			else
			{
				swap(a[r], a[i]);
				i = r;
			}
		}
		else if (a[i] < a[l])
		{
			swap (a[i], a[l]);
			i = l;
		}
		else if (a[i] < a[r])
		{
			swap(a[i], a[r]);
			i = r;
		}
		else
			break;
	}
}

void buildheap()
{
	int i;
	len --;
	for (i = (len-1)>>1; i >= 0; i --)
	{
		adjustheap(i);
	}
}

void input()
{
	int i;
	cin >> len;
	a = new int[len];
	for (i = 0; i < len; i ++)
	{
		cin >> a[i];
	}
}

void output()
{
	if(!len)
	{
		cout << a[0] << endl;
		return;
	}
	cout << a[0] << " ";
	swap(a[0], a[len]);
	len --;
	adjustheap(0);
	output();
}

void freeall()
{
	free(a);
}

int main()
{
	input();
	buildheap();
	output();
	freeall();
	return 0;
} 
//¶ÑÅÅÐò 
/*
12
5 6 7 9 11 4 2 3 10 12 1 8
*/
