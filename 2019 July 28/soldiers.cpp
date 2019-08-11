#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
using namespace std;

string s,t,p,q;
int x,dp[10010];

int stoin(string k)
{
    int ret=0;
    FOR(i,0,k.length()) ret*=10,ret+=k[i]-'0';
    return ret;
}

string to_str(int k)
{
    string ret="";
    while(k) ret=(char)('0'+(k%10))+ret,k/=10;
    return ret;
}

int main()
{
    t="10001"; memset(dp,16,sizeof(dp)); dp[0]=dp[10000]=0;
    while(cin>>s) dp[stoin(t)]=-1,t=s;
    if(dp[0]==-1) { cout<<-1<<'\n'; return 0; }

    FOR(i,0,10000)
    {
        if(dp[i]==-1) continue;
        p=to_str(i);
        while(p.length()<4) p="0"+p;
        FOR(j,0,4)
        {
            q=p; q[j]+=1;
            if(q[j]>'9') q[j]='0';
            x=stoin(q);
            if(dp[x]==-1) continue;
            dp[x]=min(dp[x],dp[i]+1);
        }
    }

    for(int i=10000;i>0;i--)
    {
        if(dp[i]==-1) continue;
        p=to_str(i);
        while(p.length()<4) p="0"+p;
        if(p.length()>4) p=p.substr(1,4);
        FOR(j,0,4)
        {
            q=p; q[j]-=1;
            if(q[j]<'0') q[j]='9';
            x=stoin(q);
            if(dp[x]==-1) continue;
            dp[x]=min(dp[x],dp[i]+1);
        }
    }
    cout<<(dp[stoin(t)]==269488144?-1:dp[stoin(t)])<<'\n';

    return 0;
}