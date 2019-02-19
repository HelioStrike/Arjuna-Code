#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
using namespace std;

//We sort the costs in reverse order
//Each friend buys the expensive frames first and then moves on to the cheaper ones
//Time Complexity - O(nlog(n)),
//nlog(n) is because of the initialsorting, the main part of the algorithm runs in O(n)

int main()
{
    int nframes,nfriends; cin >> nframes >> nfriends;
    int costs[nframes]; FOR(i,0,nframes) cin >> costs[i];
    sort(costs,costs+nframes,greater<int>());

    int tot=0;
    FOR(i,0,nframes/nfriends+1)
    {
        FOR(j,0,nfriends)
        {
            if(j+i*(nfriends)>=nframes) continue;
            tot+=(i+1)*costs[j+i*(nfriends)];
        }
    }
    cout << tot << '\n';

    return 0;
}
