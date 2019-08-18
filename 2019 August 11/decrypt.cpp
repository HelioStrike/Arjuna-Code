#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
using namespace std;

//Used DP
//dp[n] = dp[n-1] (if s[n-1] is not 0) + dp[n-2] (if substring is <= 26)
//Time Complexity - O(n)

//string to integer
int stoin(string k)
{
    int ret=0;
    FOR(i,0,k.length()) ret*=10,ret+=k[i]-'0';
    return ret;
}

int fun()
{
    string s; cin>>s; int n=s.length();
    if(n==0 || s[0]=='0') return 0;
    FOR(i,0,n-1) if(s[i+1]=='0' && (s[i]=='0' || s[i]>'2')) return 0;
    int dp[n+1]; memset(dp,0,sizeof(dp)); dp[0]=1;
    FOR(i,0,n-1)
    {
        if(s[i]!='0') 
        {
            dp[i+1]+=dp[i];
            if(stoin(s.substr(i,2))<=26) dp[i+2]+=dp[i];
        }
    }
    if(s[n-1]!='0') dp[n]+=dp[n-1];
    return dp[n];
}

int main()
{
    cout<<fun()<<'\n';
    return 0;
}