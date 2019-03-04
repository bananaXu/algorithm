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

long long  turn(long long x,long long y)
{
    while(y!=0)
    {
       int r=x%y;
       x=y;
       y=r;
    }
    return x;
}
long long ten(int x)
{
    long long sum=1;
    while(x)
    {
        sum*=10;
        x--;
    }
    return sum;
}
int main()
{
    int n,x,y;
    long long a,b,c,a1,b1,c1,w;
    long long u,d,u1,d1;
    char char1[21],char2[21],char3[21],char4[21],char5[21],char6[21];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s %s %s %s %s %s",char1,char2,char3,char4,char5,char6);
        x=strlen(char2);
        y=strlen(char3);
        if(char2[0]=='$'&&char3[0]!='$')
        {
            c=atoll(char3);
//字符串取long long 型，字符串取long型为atol，字符串取浮点型atof，字符串取整型atoi
            u=c;
            d=(ten(y)-1);
            w=turn(u,d);
            u/=w;d/=w;
        }
        else if(char2[0]!='$'&&char3[0]!='$')
        {
            b=atoll(char2); c=atoll(char3);
            u=(b*(ten(y)-1)+c);
            d=ten(x)*(ten(y)-1);
            w=turn(u,d);
            u/=w;d/=w;
        }
        else if(char2[0]!='$'&&char3[0]=='$')
        {
            u=atoll(char2);
            d=ten(x);
        }
        else
        {
            u=0;d=1;
        }

        x=strlen(char5);
        y=strlen(char6);
        if(char5[0]=='$'&&char6[0]!='$')
        {
            c1=atoll(char6);u1=c1;
            d1=(ten(y)-1);
            w=turn(u1,d1);
            u1/=w;d1/=w;
        }
        else if(char5[0]!='$'&&char6[0]!='$')
        {
            b1=atoll(char5);c1=atoll(char6);
            u1=(b1*(ten(y)-1)+c1);
            d1=ten(x)*(ten(y)-1);
            w=turn(u1,d1);
            u1/=w;d1/=w;
        }
        else if(char5[0]!='$'&&char6[0]=='$')
        {
            u1=atoll(char5);
            d1=ten(x);
        }
        else
        {
            u1=0;d1=1;
        }

        if(char1[0]=='$') a=0;
        else a=atoll(char1);

        if(char4[0]=='$') a1=0;
        else a1=atoll(char4);

        u=u*d1+u1*d;
        d*=d1;
        w=turn(u,d);
        u/=w;d/=w;
        
        u=(a+a1)*d+u;
        w=turn(u,d);
        u/=w;d/=w;
        
        if(d!=1)
        printf("%lld/%lld\n",u,d);
        else
        printf("%lld\n",u);
    }
    return 0;
}