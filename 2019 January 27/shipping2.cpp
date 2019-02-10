#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define MAXN 100
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    return (a.first < b.first);
}

int main()
{
    int n,startp,endp; scanf("%d%d%d",&n,&startp,&endp);
    vector<pair<int, int> > ranges; endp -= 1;

    int x,p;
    FOR(i,0,n)
    {
        scanf("%d%d",&x,&p);
        ranges.push_back(make_pair(max(x-p,startp), min(x+p-1,endp)));
    }
    sort(ranges.begin(), ranges.end(), cmp);

    int tot = endp-startp+1,curr_low,curr_high;
    FOR(i,0,ranges.size())
    {
        curr_low = ranges[i].first;
        curr_high = ranges[i].second;
        while(i<ranges.size()-1 && curr_high+1>=ranges[i+1].first)
        {
            curr_high = max(curr_high,ranges[i+1].second); i++;
        }
        //cout << curr_low << " " << curr_high << '\n';
        tot -= curr_high-curr_low+1;
    }
    printf("%d\n",tot);

    return 0;
}