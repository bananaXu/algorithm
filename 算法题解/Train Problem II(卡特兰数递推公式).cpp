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

int a[105][100];
void ktl()
{
    int i,j,yu,len;
    a[2][0] = 1;
    a[2][1] = 2;
    a[1][0] = 1;
    a[1][1] = 1;
    len = 1;
    for(i = 3; i < 101; i ++)
    {
        yu = 0;
        for(j = 1; j <= len; j ++)
        {
            int t = (a[i-1][j])*(4*i-2)+yu;
            yu = t/10;
            a[i][j] = t%10;
        }    
        while(yu)
        {
            a[i][++ len] = yu%10;
            yu /= 10;
        }
        for(j = len; j >= 1; j --)
        {
            int t = a[i][j]+yu*10;
            a[i][j] = t/(i+1);
            yu = t%(i+1);
        }        
        while(!a[i][len])
        {
            len --;
        }    
        a[i][0] = len;
    }    
    
}    
int main()
{
    ktl();
    int n;
    while(~scanf("%d", &n))
    {
        for(int i = a[n][0]; i > 0; i --)
        {
            printf("%d", a[n][i]);
        }    
        puts("");
    }    
    return 0;
}   
// h(n) = (4n-2)/(n+1)*h(n-1)
