#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int t, i, j, l;
	string s;
	string a;
	scanf("%d", &t); 
	short dp[2][1005];
	while (t --)
	{
		cin >> s;
		memset(dp, 0, sizeof(dp));
		l = s.length();
		a = s;
		reverse(a.begin(), a.end());
		for (i = 0; i < l; i ++)
		{
			for (j = 0; j < l; j ++)
			{
				if (s[i] == a[j])
					dp[i&1][j+1] = dp[1-(i&1)][j]+1;
				else
					dp[i&1][j+1] = max(dp[i&1][j], dp[1-(i&1)][j+1]);
			}
		}
		printf("%d\n", l-dp[1-(l&1)][l]);
	}
	return 0;
}
/*
����
��ν�����ַ���������һ���ַ����������Ҷ��ʹ��ҵ��������ȫһ���ģ�����"aba"����Ȼ�����Ǹ�������ⲻ���ټ򵥵��ж�һ���ַ����ǲ��ǻ����ַ���������Ҫ���㣬����һ���ַ�������������λ������ַ�����������Ӽ����ַ�������ʹ����ַ�����Ϊ�����ַ�����
����
��һ�и�������N��0<N<100��
��������N�У�ÿ��һ���ַ�����ÿ���ַ������Ȳ�����1000.
���
ÿ�����������ӵ������ַ���
��������
1
Ab3bd
�������
2

10
ahdflgajlskjgnkajdnflgjadlhfagjk
lajdfjaklnfdljndfjkgsladjfkag
asjdfgljskdfnakljdf'gijreiogesl
alrfhgoeirgmaklrgfmear
hrithwiuerglwirughslkjfg
jlhadfkyghskdyfgysdfguisehryigserhgysergiysegfvhksdfh
ayehgfusykerkysekfghhsfdhsudfgksydfgkusy
erughsjdfngjdfvbsiehguirhglsjefghlsudfkfsgs
shdfghieurhggierhgljksnfkjgnsltugsbiljerngiusbirubgisrtugstr
gugvksfhgurebgvienriugsnefbilueshgiusehrgliseubgiljsbnlisughnlisuhjgouiergilujsflsj
*/
