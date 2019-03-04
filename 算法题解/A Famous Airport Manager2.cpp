#include<stdio.h>
#include<queue>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<memory>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<malloc.h>
#include<iostream>
using namespace std;
#define exp(x) (1<<x)
#define N 8
#define M 6561
int base[N], tag[M][exp(N)], cnt[M], one[exp(N)];
int g[3][3], flag[3][3];
int diret[][2]={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
/*�㷨˼��:
��ʼ˳��
λ��1 2 3   �� * * *  0 0 0 
	4 5 6  	   G * B  1 0 2 
	7 8 9      G G *  1 1 0 
   ������ʼ״̬00102110
1���ܹ����������˳��һ���ͳ�ʼ��״̬��ɫ����һ��(�գ�0��G:1��B:2)
2��ö���ܹ��ɳ�����ɫ��˳�����磺1121��1112��2111 
3��flag[m][n]�����Ƿ��ܴӳ�ʼ״̬Ϊm�ɳ�˳��Ϊn������Ϊ1��������Ϊ0
4�������12110��1121��ɾ����һ�������ɫ��Ϊ121����Ϊ״̬x��
   �������ȷɵ�����ɫ1����ôһ�����ܹ�ֱ�Ӵӳ�ʼ״̬������ɫ1�ĵ��� 
   ��ɣ�����������(2,1)(3,2)����ɾ��һ������ʼ״̬Ϊy������ܹ�
   ����״̬n����ôһ��������һ��flag[x][y]=1��
5��ö��1~3^8-1,6560�ֳ�ʼ״̬(m)�����m��Ӧ������n������flag[m][n],
   flag[m][n]������Ϊ1�ļ��������ǳ�ʼm�ܷ���ֵ�˳������������n
   ��ֻ��1��2�������ö���������ʾ��m����0��1��2��������������ʾ 
*/
void dfs(int x,int y)
{
	flag[x][y] = 1;
	int next_x, next_y;
	if(g[x][y] == 0)
	{
		for(int i = 0; i < 4; i ++)
		{
			next_x = x+diret[i][0];
			next_y = y+diret[i][1];
			if(next_x >= 0 && next_x < 3 && next_y >= 0 && next_y < 3 && !flag[next_x][next_y])
			dfs(next_x,next_y);
		}
	}
}

void get_g(int x)
{
	int i, j, k;
	for(i = 0; i < 3; i ++)
	{
		for(j = 0; j < 3; j ++)
		{
			if(!i && !j)
				g[i][j] = 0;
			else
			{
				g[i][j] = x%3;
				x /= 3;
			}
		}
	}
	memset(flag, 0, sizeof(flag));
	dfs(0, 0);
}

void init()
{
	int i, j, tot, num, k, next_i, next_j;
	base[0] = 1;
	for(i = 1; i < N; i++)
		base[i] = base[i-1]*3;
	memset(tag, 0, sizeof(tag));
	for(i = 0; i < exp(N); i++)
	{
		one[i] = 0;
		for(j = 0; j < N; j ++)
		if(i&exp(j))
			one[i] ++;
	}
	tag[0][0] = 1;
	for(i = 1; i < M; i++) // ö�ٳ�ʼ״̬ 
	{
		get_g(i); // ��g����i����ĳ�ʼ״̬ 
		tot = num = 0;
		for(j = 0; j < 3; j ++) // ����зɻ�����Ŀtotal����ɫ2����Ŀnum 
		{
			for(k = 0; k < 3; k ++)
			{
				if(g[j][k])
				{
					tot ++;
					if(g[j][k] == 2)
						num++;
				}
			}
		}
		cnt[0] = 1;
		cnt[i] = 0; 
		for(j = 0; j < exp(tot); j ++) // ö����ɫ���ܳ��ֵ�˳�� 
		{
			if(one[j] == num) // ��ɫΪ2��������i��ͬ��j 
			{
				for(k = 0; !tag[i][j] && k < 3; k ++)
				{ 
					for(int kk = 0; !tag[i][j] && kk < 3; kk ++)
					{ 
						if(g[k][kk] == (j%2+1) && flag[k][kk]) // ��j״̬��Ӧ�ĵ�һ�������ɫ��ͬ���ܹ�ֱ�ӵ��� 
						{
							next_i = i-base[k*3+kk-1]*g[k][kk];
							next_j = j>>1;
							if(tag[next_i][next_j])
							{ 
								tag[i][j] = 1;
								cnt[i] ++;
							} 
						}
					} 
				} 
			}
		}
	}
}
int main()
{
	int cas,i,j,st,k;
	char tmp[3][10];
	init();
	cas=0;
	while(scanf("%s",tmp[0])!=EOF)
	{
		cas++;
		scanf("%s",tmp[1]);
		scanf("%s",tmp[2]);
		st=0;
		k=0;
		for(i = 0; i < 3; i ++)
		{
			for(j = 0; j < 3; j ++)
			{
				if(!i && !j)
					continue;
				else if(tmp[i][j]=='B')
					st += base[k++];
				else if(tmp[i][j]=='G')
					st += base[k++]<<1;
				else k++;
			}
		}
		printf("Case %d: %d\n",cas,cnt[st]);
	}
	return 0;
}
/*
��Ŀ����
3X3�ķɻ���,(0,0)��Ϊ��ɵ㣬'*'�գ�'G'��ɫ��'B'��ɫ��
�ɻ����ߵ�����λ�ã����ܿ����������ɫ˳��������� 
*BB  
BBB
BBB
*GB
BBB
BBB
*BG
BBB
*GB
*GB
GBG
BGB
*G*
B*G
GGB
*/
