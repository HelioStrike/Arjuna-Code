#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
using namespace std;

int main()
{
    int n; cin>>n;
    int a[n]; FOR(i,0,n) cin>>a[i];

    for(int i=n-1; i>=0; i--)
    {
        if(a[i]>0)
        {
            FOR(j,i+1,n)
            {
                if(a[j]<0)
                {
                    if(abs(a[i])==abs(a[j])) a[i]=a[j]=0;
                    else if(abs(a[i])<abs(a[j]))
                    {
                        a[i]=0; break;
                    }
                    else if(abs(a[j])<abs(a[i])) a[j]=0;
                }
            }   
        }
    }

    vector<int> rem; FOR(i,0,n) if(a[i]!=0) rem.push_back(a[i]);
    if(!rem.size()) cout<<-1;
    else FOR(i,0,rem.size()) cout<<rem[i]<<' ';
    cout<<'\n';

    return 0;
}