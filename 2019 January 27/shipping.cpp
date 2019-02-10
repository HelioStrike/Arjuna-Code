#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define MAXN 20000
using namespace std;

//Sorry about the naive solution. I'll start working on a segment tree solution now

int mapx[MAXN];

int main()
{
    int n,startp,endp; scanf("%d%d%d",&n,&startp,&endp);

    int x,p;
    FOR(i,0,n)
    {
        scanf("%d%d",&x,&p);
        FOR(i,max(x-p,startp),min(x+p,endp)) mapx[i] += 1;
    }

    int tot = 0;
    FOR(i,startp,endp) tot += (mapx[i]==0); 

    /*
    FOR(i,0,MAXN)
    {
        if(mapx[i]==0 && mapx[i+1]>0) cout << (i+1) << '\n';
        else if(mapx[i]>0 && mapx[i+1]==0) cout << (i) << '\n';
    }
    */

    printf("%d\n",tot);

    return 0;
}