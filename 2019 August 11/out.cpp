#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
using namespace std;

//Used DP
//dp[n] = dp[n-1] (last ball was a hit) + dp[n-2] (last ball was a miss) + dp[n-3] (last 2 balls were misses)
//Time Complexity - O(n)

int main()
{
    int n; cin>>n;
    int dp[n+2]; memset(dp,0,sizeof(dp));
    dp[0]=dp[1]=1;
    FOR(i,2,n+2)
    {
        dp[i]=dp[i-1]+dp[i-2];
        if(i>=3) dp[i]+=dp[i-3];
    }
    cout<<dp[n+1]<<'\n';

    return 0;
}