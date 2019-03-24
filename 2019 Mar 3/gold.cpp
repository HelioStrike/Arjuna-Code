#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
using namespace std;

//We use binary search here

int main()
{
    int n,k,curr,rem; scanf("%d%d",&n,&k);
    int l=1,m,h=99999999;
    
    while(l<=h)
    {
        m=(l+h)/2;
        curr=m,rem=m;
        while(rem>k) curr+=rem/k,rem=rem/k+(rem%k);
        if(curr==n) break;
        else if(curr>n) h=m-1;
        else l=m+1;
    }

    printf("%d\n",m);

    return 0;
}