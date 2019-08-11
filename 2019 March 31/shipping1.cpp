#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
using namespace std;

int n,e,v1,v2,s,src,dst,k,inf;

int main()
{
    memset(&inf,16,sizeof(inf));

    cin>>n>>e;
    int g[n][n];
    memset(g,16,sizeof(g));
    FOR(i,0,n) g[i][i]=0;
    FOR(i,0,e)
    {
        cin>>v1>>v2>>s;
        g[v1][v2]=s;
    }
    cin>>src>>dst>>k;

    int dp[k+1][n][n];
    memset(dp,16,sizeof(dp));

    FOR(i,0,k)
    {
        FOR(j,0,n)
        {
            FOR(k,0,n)
            {
                if(i==0 && j==k) dp[i][j][k]=0;
                else if(i==1 && g[j][k]!=inf) dp[i][j][k]=g[j][k];
                else if(i>1)
                {
                    FOR(l,0,n)
                    {
                        if(g[j][l]!=inf && dp[i-1][j][l]!=inf)
                        {
                            dp[i][j][k]=min(dp[i][j][k],g[j][l]+dp[i-1][l][k]);
                        }
                    }
                }
            }
        }
    }

    FOR(i,0,n)
    {
        FOR(j,0,n)
        {
            cout<<dp[1][i][j]<<' ';
        }
        cout<<'\n';
    }

    cout<<dp[k][src][dst]<<'\n';

    return 0;
}