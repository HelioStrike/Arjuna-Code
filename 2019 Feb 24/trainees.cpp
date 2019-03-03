#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define INF 99999
using namespace std;

//Floyd warshall was used here, as its the easiest to implement.
//Hence, Time Complexity is O(n^3)
//Faster algorithms that could be used here are Djikstra's and Bellman-Ford 

int main()
{
    int n,v,e,v1,v2,c; scanf("%d%d%d",&n,&v,&e);
    int mapp[v][v]; memset(mapp,16,sizeof(mapp));

    FOR(i,0,e)
    {
        scanf("%d%d",&v1,&v2); v1--,v2--;
        mapp[v1][v2]=mapp[v2][v1]=1;
    }

    FOR(i,0,v)
    {
        FOR(j,0,v)
        {
            FOR(k,0,v)
            {
                c=mapp[i][k]+mapp[k][j];
                if(c<mapp[i][j]) mapp[i][j]=c;
            }
        }
    }

    int minm=INF,ans=0;
    FOR(i,0,n)
    {
        if(mapp[i][v-1]<minm) minm=mapp[i][v-1],ans=1;
        else if(mapp[i][v-1]==minm) ans++;
    }
    printf("%d\n",n-ans);

    return 0;
}