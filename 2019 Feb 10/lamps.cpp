#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
using namespace std;

//We sort the array of positions in descending order.
//We pick the starting house and see how far we could place the lamp while covering this point,
//and place the lamp there. Now, iterate forward until we hit a house that wouldn't be illuminated by this lamp,
//consider it as the starting house, and perform the process again.
//Time Complexity - O(n) ,
//since we iterate through each house.

int main()
{
    int n,r,needed=0; cin >> n >> r;
    int pos[n]; FOR(i,0,n) cin >> pos[i];

    int curr=0,currr;
    while(curr!=n)
    {
        currr=curr+1;
        while(currr!=n && pos[currr]-pos[curr]<=r) currr++;
        needed++;

        curr=currr-1;
        while(currr!=n && pos[currr]-pos[curr]<=r) currr++;
        curr=currr;
    }

    cout << needed << '\n';

    return 0;
}
