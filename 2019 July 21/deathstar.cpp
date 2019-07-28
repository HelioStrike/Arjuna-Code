#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
using namespace std;

// Use binary search on number of hours for Guardians to arrive
// Time Complexity - O(nlogn)

// n - number of solar systems, h - number of hours taken for GotG to arrive, k - speed of eating planets
// a - array for number of planets in solar systems
// l,m,r - left, mid, right for binary search 
// tot - number of hours to consume all planets given speed of 'm'
int n,h,k,l,m,r,tot,a[100010];

int main()
{
    // Taking input
    while(cin>>a[n]) n++;
    n--,h=a[n]; 

    // Use binary search on number of hours
    l=1,r=100000;
    while(l<r)
    {
        m=(l+r)/2,tot=0;
        FOR(i,0,n) tot+=ceil(a[i]*1.0f/m);
        if(tot>h) l=m+1;
        else r=m;
    }
    cout<<r<<'\n';

    return 0;
}