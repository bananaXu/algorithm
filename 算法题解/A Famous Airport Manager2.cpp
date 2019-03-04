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
/*算法思想:
初始顺序
位置1 2 3   例 * * *  0 0 0 
	4 5 6  	   G * B  1 0 2 
	7 8 9      G G *  1 1 0 
   例：初始状态00102110
1、能够看到的起飞顺序一定和初始的状态颜色总数一样(空：0，G:1，B:2)
2、枚举能够飞出的颜色的顺序，例如：1121，1112，2111 
3、flag[m][n]代表是否能从初始状态为m飞出顺序为n，能则为1，不能则为0
4、例如从12110到1121，删除第一个起飞颜色后，为121，设为状态x，
   由于最先飞的是颜色1，那么一定是能够直接从初始状态到达颜色1的点中 
   起飞，例如例子上(2,1)(3,2)，设删除一个点后初始状态为y。如果能够
   到达状态n，那么一定至少有一个flag[x][y]=1。
5、枚举1~3^8-1,6560种初始状态(m)，求出m对应的所有n，再求flag[m][n],
   flag[m][n]中所有为1的加起来就是初始m能否出现的顺序总数，由于n
   中只有1和2，可以用二进制来表示，m中有0，1，2，用三进制来表示 
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
	for(i = 1; i < M; i++) // 枚举初始状态 
	{
		get_g(i); // 用g保存i代表的初始状态 
		tot = num = 0;
		for(j = 0; j < 3; j ++) // 算出有飞机的数目total，颜色2的数目num 
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
		for(j = 0; j < exp(tot); j ++) // 枚举颜色可能出现的顺序 
		{
			if(one[j] == num) // 颜色为2的数量与i相同的j 
			{
				for(k = 0; !tag[i][j] && k < 3; k ++)
				{ 
					for(int kk = 0; !tag[i][j] && kk < 3; kk ++)
					{ 
						if(g[k][kk] == (j%2+1) && flag[k][kk]) // 与j状态对应的第一个起飞颜色相同且能够直接到达 
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
题目大意
3X3的飞机场,(0,0)点为起飞点，'*'空，'G'绿色，'B'蓝色，
飞机能走到相邻位置，求能看到的起飞颜色顺序的总数。 
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
