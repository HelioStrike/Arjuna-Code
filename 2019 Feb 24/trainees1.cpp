#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define INF 99999
using namespace std;

//Bellman-ford was used here
//Hence, Time Complexity is O(V*E)

int main()
{
    int n,v,e,v1,v2,c; scanf("%d%d%d",&n,&v,&e);
    int eds[e][2]; FOR(i,0,e) scanf("%d%d",&v1,&v2),eds[i][0]=v1-1,eds[i][1]=v2-1;

    vector<int> d(v,INF); d[v-1]=0;

    FOR(i,0,v)
    {
        FOR(j,0,e)
        {
            if(d[eds[j][0]]<INF) d[eds[j][1]] = min (d[eds[j][1]], d[eds[j][0]] + 1);
            if(d[eds[j][1]]<INF) d[eds[j][0]] = min (d[eds[j][0]], d[eds[j][1]] + 1);
        }
    }


    int minm=INF,ans=0;
    FOR(i,0,n)
    {
        if(d[i]<minm) minm=d[i],ans=1;
        else if(d[i]==minm) ans++;
    }
    printf("%d\n",n-ans);

    return 0;
}