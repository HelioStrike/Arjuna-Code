#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
using namespace std;

//The first 0 in the original array will be the first 0 in the sorted array. 
//Finding that distance will give us the number of seconds needed.
//We will an extra second everytime we encounter a zero with a zero to its right.
//Time Complexity - O(n)

int main()
{
    int n,zeros=0; cin >> n;
    int arr[n]; FOR(i,0,n) { cin >> arr[i]; zeros+=(arr[i]==0); }
    
    int yee=(arr[n-1]==1);
    int first_zero=(arr[n-1]==0)?n-1:-1;
    int extra=0;
    for(int i=n-2;i>=0;i--) 
    { 
        if(arr[i]==1) yee=1;
        else
        {
            first_zero=i;
            if(yee && arr[i+1]==0) extra+=1;
        }
    }
    cout << (first_zero==-1?0:n+extra-zeros-first_zero) << '\n';

    return 0;
}

/*
//Bubblesort used here. If no swaps, we have our answer.

int main()
{
    int n,swaps,epoch=0; cin >> n;
    int a[n]; FOR(i,0,n) cin >> a[i];
    for(epoch=0;epoch<n;epoch++)
    {
        swaps=0;
        FOR(j,0,n-1)
        {
            if(a[j]<a[j+1]) { swap(a[j],a[j+1]); swaps++; j++;}
        }
        if(!swaps) break;
    }
    cout << epoch << '\n';

    return 0;
}
*/
