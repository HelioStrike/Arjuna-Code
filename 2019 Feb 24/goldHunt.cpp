#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
using namespace std;

//We use dynamic programming to solve the problem.
//Time complexity - O(n^2)

int main()
{
    int n,c; scanf("%d",&n);
    int mapp[n][n]; FOR(i,0,n) FOR(j,0,n) scanf("%d",&mapp[i][j]);

    FOR(i,1,n)
    {
        FOR(j,0,n)
        {
            c=mapp[i-1][j];
            if(j>0) c=max(c,mapp[i-1][j-1]);
            if(j<n-1) c=max(c,mapp[i-1][j+1]);
            mapp[i][j]+=c;
        }
    }

    int ans=0;
    FOR(i,0,n) ans=max(ans,mapp[n-1][i]);

    printf("%d\n",ans);

    return 0;
}