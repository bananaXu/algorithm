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

typedef struct NODE
{
	int num;
	struct NODE * prev , * next;
}Node;

typedef struct LINKLIST
{
	Node node[6];
	struct LINKLIST * next;
}Linklist;

Linklist * linklist[99991];

bool cmp(int sum, int * num)
{
	Linklist * curr;
	curr = linklist[sum];
	Node * node;
	while(curr != NULL)
	{
		int i, j;
		for(i = 0; i < 6; i++)
		{
			if(curr->node[i].num == num[0])
			{
				node = curr->node[i].next ;
				for(j = 1; j < 6; j++)
				{
					if(node->num != num[j])
						break;
					node = node->next;
				}
				if(j == 6)
					return 1;
				node = curr->node[i].prev ;
				for(j = 1; j < 6; j++)
				{
					if(node->num != num[j])
					break;
					node = node->prev;
				}
				if(j == 6)
					return 1;
			}
		}
		curr = curr->next;
	}
	return 0;
}

void insert(int sum, int num[])
{
	int i;
	Linklist * newLinklist = new Linklist;
	for(i = 0; i < 6; i++)
	{
		newLinklist->node[i].num = num[i];
	}
	for(i = 1; i< 6; i++)
	{
		newLinklist->node[i].prev = &newLinklist->node[i - 1];
	}
	newLinklist->node[0].prev = &newLinklist->node[5];
	for(i = 0 ; i < 5; i++)
	{
		newLinklist->node[i].next = &newLinklist->node[i + 1];
	}
	newLinklist->node[5].next = &newLinklist->node[0];
	newLinklist->next = linklist[sum];
	linklist[sum] = newLinklist;
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		memset(linklist, 0, sizeof(linklist));
		int n;
		scanf("%d", &n);
		int i;
		int num[6]; 
		bool flag = 0;
		int sum;
		for(i = 0; i < n; i++)
		{
			scanf("%d %d %d %d %d %d", &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]);
			if(flag == 0)
			{
				sum = (num[0] + num[1] + num[2] + num[3] + num[4] + num[5]) % 99991;
				if(cmp(sum, num) == 1)
				flag = 1 ;
				else
				insert(sum, num);
			}
		}
		if(flag == 1)
			printf("Twin snowflakes found.\n");
		else
			printf("No two snowflakes are alike.\n");
	}
	return 0;
}
