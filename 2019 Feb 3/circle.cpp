#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define INF 99999999
using namespace std;


int main()
{
    int n,start,end,curr,curr2; cin >> n;
    int a[n]; FOR(i,0,n) cin >> a[i];
    cin >> start >> end; start--; end--;

    int upper=0,lower=0;

    curr=start;
    while(curr!=end)
    {
        upper+=a[curr]; curr=(curr+1)%n;
    }

    curr=(start-1+n)%n; lower=a[curr];
    while(curr!=end)
    {
        curr=(curr-1+n)%n; lower+=a[curr]; 
    }

    //cout << upper << " " << lower << '\n';

    int upper_min=0,lower_min=0,left_curr,right_curr;

    left_curr=0; right_curr=upper-left_curr; curr2=start;
    do
    {
        //cout << left_curr << " " << right_curr << '\n';
        right_curr-=a[curr2];
        upper_min=min(upper_min,left_curr+right_curr);
        curr2=(curr2+1)%n;
    } while(((curr2-1+n)%n)!=end);

    curr=start;
    while(curr!=end)
    {
        left_curr+=a[curr]; right_curr=upper-left_curr; curr2=(curr+1)%n;
        while(((curr2-1+n)%n)!=end)
        {
            //cout << left_curr << " " << right_curr << '\n';
            right_curr-=a[curr2];
            upper_min=min(upper_min,left_curr+right_curr);
            curr2=(curr2+1)%n;
        }
        curr=(curr+1)%n;
    }

    //cout << (upper_min) << '\n';

    left_curr=0;right_curr=lower-left_curr; curr2=(start-1+n)%n;
    while((curr2%n)!=end)
    {
        right_curr-=a[curr2];
        cout << left_curr << " " << right_curr << " " << curr2 << '\n';
        lower_min=min(lower_min,left_curr+right_curr);
        curr2=(curr2-1+n)%n;
    } 


    curr=start; left_curr=0; right_curr=lower-left_curr; curr2=curr;
    while(curr!=end)
    {
        while((curr2%n)!=end)
        {
            cout << left_curr << " " << right_curr << " " << curr2 << '\n';
            right_curr-=a[curr2];
            lower_min=min(lower_min,left_curr+right_curr);
            curr2=(curr2-1+n)%n;
        }
        left_curr+=a[curr]; right_curr=lower-left_curr; curr2=curr;
        curr=(curr-1+n)%n;
    }

    while((curr2%n)!=end)
    {
        cout << left_curr << " " << right_curr << " " << curr2 << '\n';
        right_curr-=a[curr2];
        lower_min=min(lower_min,left_curr+right_curr);
        curr2=(curr2-1+n)%n;
    }


    lower_min = min(lower_min, lower);
    upper_min = min(upper_min, upper);

    //cout << upper_min << " " << lower_min << '\n';
    int ans =  min(upper+2*lower_min,lower+2*upper_min);
    cout << ans << '\n';

    return 0;
}