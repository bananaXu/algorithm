#include <iostream>
using namespace std;

int *a = new int[1000];
int len = -1;
 
void adjust(int i)
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

void insert()
{
	int i, val;
	cin >> val;
	a[++len] = val;
	if(len)
	{
		for (i = (len-1)>>1; i >= 0; i --)
		adjust(i);
	}
}
 
void output()
{
	if (len == -1)
	{
 		cout << "none"; 
 		return;
	}
	cout << a[0] << " ";
 	swap(a[0], a[len]);
 	len --;
 	adjust(0);
}

void del()
{
	if (len == -1)
	{
 		cout << "none" << endl; 
 		return;
	}
 	swap(a[0], a[len]);
 	len --;
 	adjust(0);
}

void outall()
{
	if (len == -1)
	{
 		cout << "none"; 
 		return;
	}
	while(len != -1)
		output();
}

void delall()
{
	if (len == -1)
	{
 		cout << "none" << endl; 
 		return;
	}
	while(len != -1)
		del();
}

void freeall()
{
	free(a);
}

int main()
{
	int c;
	int num;
	bool quit = false;
	cout << "1:插入 2：查看头元素" << " 3:删除头元素" <<
	" 4:输出头元素并删除 5.输出全部并清空" << 
	" 6:清空 7:输出元素个数 8:退出" << endl;
	while(1)
	{
		if (quit)
			break;
		cin >> c;
		switch (c)
		{
		case 1:
			printf("请输入元素个数：\n"); 
			cin >> num;
			printf("请输入元素：\n"); 
			if (num <= 0)
			{
				cout << "wrong" << endl;
				break;
			}
			while(num --)
				insert();
			break;
		case 2:
			if (len == -1)
				cout << "none" << endl; 
			else
				cout << a[0] << endl;
			break;
		case 3:
			del();
			break;
		case 4:
			output();
			cout << endl;
			break;
		case 5:
			outall();
			cout << endl;
			break;
		case 6:
			delall();
			break;
		case 7:
			cout << len+1 << endl;
			break;
		case 8:
			quit = true;
			break;
		default:
			cout << "wrong" << endl; 
		}
	}
	freeall();
	return 0;
} 
/*
20
5 14 9 10 15 16 6 3 11 8 1 17 7 13 2 18 20 4 12 19
*/
