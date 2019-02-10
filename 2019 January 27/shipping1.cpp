#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define MAXN 20000
using namespace std;

//Sorry about the bruteforce. I'll start working on a segment tree solution now

int mapx[4*MAXN];
int lazy[4*MAXN];

void push(int v)
{
    t[v*2] = lazy[v]/2;
}

void update(int v, int tl, int tr, int l, int r)
{
    if(l > r) return;
    if(tl == l && tr == r)
    {
        mapx[v] = lazy[v] = tr-tl+1;
        return;
    }
    push(v);
    int tm = (tl+tr)/2;
    update(2*v, tl, tm, l, min(tm,r));
    update(2*v+1, tm+1, tr, max(l,tm+1), r);
    return;
}

int query(int v, int tl, int tr, int l, int r)
{
    if(tl == tr) 
    {
        return mapx[v];
    }

}

int main()
{
    int n,startp,endp; cin >> n >> startp >> endp;

    int x,p;
    FOR(i,0,n)
    {
        cin >> x >> p;
        update(1,startp-1,endp+1,max(x-p,startp),min(x+p,endp));
    }

    cout << (endp - startp - mapx[1] - 1) << '\n';

    return 0;
}