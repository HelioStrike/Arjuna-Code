#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define INF 99999999
using namespace std;

//O(n^2) brute search algorithm used here
int main()
{
    int n; scanf("%d",&n);
    int arr[n]; FOR(i,0,n) scanf("%d",&arr[i]);

    int minloss = INF;
    FOR(i,0,n)
    {
        FOR(j,i+1,n)
        {
            if(arr[i] <= arr[j]) continue;
            minloss = min(minloss, arr[i]-arr[j]);
        }
    }
    printf("%d\n",minloss);

    return 0;
}