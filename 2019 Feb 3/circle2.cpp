#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define INF 99999999
using namespace std;


int main()
{
    int n,start,end; cin >> n;
    int a[n*4]; FOR(i,0,n) { cin >> a[i]; a[i+n]=a[i]; a[i+2*n]=a[i]; a[i+3*n]=a[i];}
    cin >> start >> end; start--; end--;

    int upper=0,lower=0;
    FOR(i,start,end) upper+=a[i];
    FOR(i,end,start+n) lower+=a[i];

    int mindist=INF,sum,sum1,sum2;
    FOR(i,end,start+n+1)
    {
        if(a[i]>=0 && a[i]!=end) break;
        FOR(j,end+n,n+i)
        {
            sum1=sum2=0;
            FOR(k,i,start+n) sum1+=a[k];
            FOR(k,end+n,j) sum2+=a[k];
            sum=2*sum1+upper+2*sum2;
            mindist=min(mindist,sum);
        }
    }

    FOR(i,start+n,end+n+1)
    {
        if(a[i]>=0 && a[i]!=start+n) break;
        FOR(j,2*n+start,n+i+1)
        {
            sum1=sum2=0;
            FOR(k,i,end+n) sum1+=a[k];
            FOR(k,2*n+start,j) sum2+=a[k];
            sum=2*sum1+lower+2*sum2;
            mindist=min(mindist,sum);
        }
    }

    cout << mindist << '\n';

    return 0;
}