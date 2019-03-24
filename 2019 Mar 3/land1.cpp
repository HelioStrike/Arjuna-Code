#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
using namespace std;

//We use binary search here

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    int a[n][m]; FOR(i,0,n) FOR(j,0,m) scanf("%d",&a[i][j]);
    
    int ans=0;
    vector<int> d(m,-1),d1(m),d2(m);
    stack<int> st;

    FOR(i,0,n)
    {
        FOR(j,0,m) if(a[i][j]==0) d[j]=i;
        
        FOR(j,0,m)
        {
            while(!st.empty() && d[st.top()]<=d[j]) st.pop();
            d1[j]=st.empty()?-1:st.top();
            st.push(j);
        }        
        while(!st.empty()) st.pop();

        for(int j=m-1; j>=0; j--)
        {
            while(!st.empty() && d[st.top()]<=d[j]) st.pop();
            d2[j]=st.empty()?-1:st.top();
            st.push(j);
        }
        while(!st.empty()) st.pop();

        FOR(j,0,m) ans=max(ans,min(i-d[j],d2[j]-d1[j]-1));
        
    }

    printf("%d\n",ans);

    return 0;
}