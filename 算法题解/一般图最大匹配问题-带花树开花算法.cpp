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

const int N = 505;

int n,m,cnt,Num[105][7],fa[N],pre[N],Mark[N],mat[N],vis[N];

queue <int> Q;
vector <int> v[N];

inline int Getfa(int x)
{
    return x == fa[x] ? x : fa[x] = Getfa(fa[x]);
}

inline int getint()
{
    char ch = getchar(); int ret = 0;
    while (ch < '0' || '9' < ch) ch = getchar();
    while ('0' <= ch && ch <= '9')
        ret = ret * 10 + ch - '0',ch = getchar();
    return ret;
}

void Build()
{
    n = getint(); m = getint();
    while (m--)
    {
        int x = getint(),y = getint();
        v[x].push_back(y); v[y].push_back(x);
    }
}

inline void Augment(int p)
{
    while (p != -1)
    {
        int tmp = mat[pre[p]]; mat[p] = pre[p];
        mat[pre[p]] = p; p = tmp;
    }
}

inline void Rebuild(int x,int y,int lca)
{
    while (Getfa(x) != lca)
    {
        pre[x] = y;
        if (fa[x] == x) fa[x] = lca;
        if (fa[mat[x]] == mat[x]) fa[mat[x]] = lca;
        if (Mark[mat[x]] == 1) {Q.push(mat[x]); Mark[mat[x]] = 0;}
        y = mat[x]; x = pre[y];
    }
}

inline void Link(int x,int y)
{
    ++cnt; int p = Getfa(x);
    for (;;)
    {
        vis[p] = cnt; p = mat[p];
        if (p == -1) break; p = Getfa(pre[p]);
    }
    int lca; p = Getfa(y);
    for (;; p = Getfa(pre[mat[p]]))
        if (vis[p] == cnt) {lca = p; break;}
    Rebuild(x,y,lca); Rebuild(y,x,lca);
}

inline int BFS(int s)
{
    for (int i = 1; i <= n; i++)
        fa[i] = i,Mark[i] = pre[i] = -1;
    while (!Q.empty()) Q.pop(); Mark[s] = 0; Q.push(s);
    while (!Q.empty())
    {
        int k = Q.front(); Q.pop();
        for (int i = 0; i < v[k].size(); i++)
        {
            int to = v[k][i];
            if (Getfa(to) == Getfa(k)) continue;
            if (Mark[to] == -1)
            {
                Mark[to] = 1; pre[to] = k;
                if (mat[to] == -1)
                {
                    Augment(to); return 1;
                }
                Mark[mat[to]] = 0; Q.push(mat[to]);
            }
            else if (Mark[to] == 0) Link(to,k);
        }
    }
    return 0;
}

int main()
{
    #ifdef DMC
        freopen("DMC.txt","r",stdin);
    #endif

    int Ans = 0; Build();
    for (int i = 1; i <= n; i++) mat[i] = -1;
    for (int i = 1; i <= n; i++)
        if (mat[i] == -1) Ans += BFS(i);
    cout << Ans << endl;
    for (int i = 1; i <= n; i++)
        printf("%d%c",mat[i] == -1 ? 0 : mat[i],i == n ? '\n' : ' ');
    return 0;
}
