#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define INF 99999999
using namespace std;

//Slightly faster than the maive implemention,
//but requires twice the memory.
//The naiver solution is commented below.
struct GoldPrice { int value, day; };

bool cmp(const GoldPrice& a, const GoldPrice& b)
{
    return (a.value < b.value);
}

//We first sort the (Value, Day) pairs, and begin comparing.
//If in a comparison, the date of the second is smaller than the date of the first
//i.e, a loss is being made and not a profit, we will consider it.
//Since the array is sorted, we only need to find one such pair before moving on
//to the next index of the outer loop.
//Best cases complexity O(nlogn) (because of sorting), worst case O(n^2) (due to 2 loops) 
int main()
{
    int n,v; scanf("%d",&n);
    GoldPrice arr[n]; FOR(i,0,n) { scanf("%d",&v); arr[i] = {v,i}; }
    sort(arr,arr+n,cmp);

    int minloss = INF;
    FOR(i,0,n-1)
    {
        FOR(j,i+1,n)
        {
            if(arr[i].day > arr[j].day) { minloss = min(minloss, arr[j].value-arr[i].value); break;}
        }
    }
    printf("%d\n",minloss);

    return 0;
}

/*
//O(n^2) naive search algorithm used here
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
*/