#include <bits/stdc++.h>
#define INF 99999
#define ll long long
#define FOR(i,a,b,c) for(ll i = (a); i < (b); i += (c))
using namespace std;

int main()
{
    ll p,tf,cf=0,c,mini=INF,maxi=-273; cin >> p; int ts[p][2];
    FOR(i,0,p,1) 
    {
        cin >> ts[i][0] >> ts[i][1];
        if(ts[i][0]<mini) mini=ts[i][0];
        if(ts[i][1]>maxi) maxi=ts[i][1];
    }
    FOR(i,mini,maxi+1,1)
    {
        c=0;
        FOR(j,0,p,1) if(i>=ts[j][0]&&i<=ts[j][1]) c++;
        if(c>cf) cf=c,tf=i;
    }
    cout << tf << " " << cf << '\n';
    return 0;
}
/*
7
10 21
15 37
18 24
40 60
12 19
17 25
21 56
10 60
*/