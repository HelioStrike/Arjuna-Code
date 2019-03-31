#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
using namespace std;

int n,c,k,ans;
queue<int> q1,q2;

int main()
{
    cin>>n;
    FOR(i,0,n) cin>>c,q1.push(c);
    FOR(i,0,n) cin>>c,q2.push(c);

    k=0;
    while(k<1000 && !q2.empty())
    {
        if(q1.front()!=q2.front()) c=q2.front(),q2.push(c),q2.pop();
        else if(q1.front()==q2.front()) q1.pop(),q2.pop(),ans++;
        k++;
    }

    cout<<(n-ans)<<'\n';

    return 0;
}