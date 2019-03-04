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

#define M 0x1a

int getnum(char s)
{
	if (isalpha(s))
		return s-'a'+10;
	else
		return s-'0';
}

int main()
{
	string s = "7b000f0c241a113f490d433201072b4b245f640e21065a35080801604655216338562917462d0b3841075a7f49137954505f78541c7142184b4c6c67220a3e4907093b521065595a056952446a590a5a6d4e473f6f456867012000523107154f2352456102100d77555e7f0e674a476d467b736363686635547f53143b1066454e6b4a18090b472c1d1e3d49030a2e00073f49584366101d210929121d4b6f1d1434104109271d553307524223041d2d0b2b411a0f2a52163d07061b204f1a3c4945582f164e270a2804406d6f525a78191306261b13724b615c23041d21453f140c0a26065a350c4d4f3c07103449485f3345192d09204109023b523b1b495b4261331b78400a3a66454e64153e080013295a580c01044f230a0c7a0042101e0c0f2b2d2314340e7e423c3d07250a040e1b3d26434a1a0b4c6d5e46414e476f5d550c01044f291a0132064343660a08641124081d473f00153a0504026855553600524332041c640422054e0320001b3d040e0127047f7a49111034001a311722415e5c450f70";
	string a = "XiaoHouZi10FenDeLangOrz";
	int b[10000];
	for (int i = 0; i <= s.length()/2; i ++)
	{
		b[i] = 16*getnum(s[i<<1])+getnum(s[(i<<1)+1]);
	}
	for (int i = 0; i < s.length()/2; i += a.length())
	{
		for (int j = 0; j < a.length() && i+j < s.length()/2; j ++)
		{
			printf("%c", (b[i+j]^a[j]));
		}
			
	}
	return 0;
} 
/*
加密解密
时间限制：3000 ms  |  内存限制：65535 KB
难度：5
描述
SanJiangXiaoDu has a tool which can encrypt any text file by simple XOR encryption. The main procedure for this tool is as below.

for(int i = 0; i < contentLength; i += keyLength) {
        for(int j = 0; j < keyLength && i + j < contentLength; j++) {
                fprintf(f, "%.2x", content[i + j] ^ key[j]);
        }
}

One day, iphxer found the tool and encrypt a source code "source.cpp" by it. If you submit original "source.cpp" you can get Accepted, but unfortunately, you only have the encypted "source.cpp" and you do not know the key. The length of key is no more than 30.

The encrypted "source.cpp" in hex is as below.
7b000f0c241a113f490d433201072b4b245f640e21065a35080801604655216338562917462d0b3841075a7f49137954505f78541c7142184b4c6c67220a3e4907093b521065595a056952446a590a5a6d4e473f6f456867012000523107154f2352456102100d77555e7f0e674a476d467b736363686635547f53143b1066454e6b4a18090b472c1d1e3d49030a2e00073f49584366101d210929121d4b6f1d1434104109271d553307524223041d2d0b2b411a0f2a52163d07061b204f1a3c4945582f164e270a2804406d6f525a78191306261b13724b615c23041d21453f140c0a26065a350c4d4f3c07103449485f3345192d09204109023b523b1b495b4261331b78400a3a66454e64153e080013295a580c01044f230a0c7a0042101e0c0f2b2d2314340e7e423c3d07250a040e1b3d26434a1a0b4c6d5e46414e476f5d550c01044f291a0132064343660a08641124081d473f00153a0504026855553600524332041c640422054e0320001b3d040e0127047f7a49111034001a311722415e5c450f70

输入
无
输出
请直接提交原始的source.cpp即可
样例输入
无
样例输出
无
*/
