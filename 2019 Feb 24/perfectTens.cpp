#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
using namespace std;

//Normal string comparing is used here.
//As there are k strings of size n,
//the complexity is O(n*k)

int main()
{
    int n,k,curr=0,ans=0; string s="",c; scanf("%d%d",&n,&k);
    FOR(i,0,n) s=s+"H";

    while(k--)
    {
        cin>>c; 
        if(c==s) curr++,ans=max(curr,ans);
        else curr=0;
    }
    printf("%d\n",ans);

    return 0;
}