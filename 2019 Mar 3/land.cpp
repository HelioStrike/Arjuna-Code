#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define MAXN 50
using namespace std;

//DP used here

int dp[MAXN][MAXN]; 

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    int a[n][m]; FOR(i,0,n) FOR(j,0,m) scanf("%d",&a[i][j]);
    
    FOR(i,0,n) dp[i][0]=a[i][0];
    FOR(i,0,m) dp[0][i]=a[0][i];
    
    FOR(i,1,n) FOR(j,1,m) if(a[i][j]) dp[i][j]=min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]))+1;
    int ans=-1; FOR(i,0,n) FOR(j,0,m) ans=max(ans,dp[i][j]);

    printf("%d\n",ans);

    return 0;
}