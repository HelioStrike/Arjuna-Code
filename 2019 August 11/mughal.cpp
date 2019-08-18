#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define N 100
using namespace std;

//Graph
//Check direct allies and direct allies of direct allies, and add their strengths
//Time Complexity - O(E) (E is number of edges)

int n,id,v,u,ans,str[N];
string s;
vector<int> g[N];

//string to integer
int stoin(string k)
{
    int ret=0;
    FOR(i,0,k.length()) ret*=10,ret+=k[i]-'0';
    return ret;
}

int main()
{
    cin>>n;
    getline(cin,s);
    FOR(i,0,n)
    {
        getline(cin,s);
        stringstream stream(s);
        string inter;
        getline(stream, inter, ' ');
        id=stoin(inter);
        getline(stream, inter, ' ');
        str[id]=stoin(inter);
        while(getline(stream, inter, ' ')) 
        { 
            g[id].push_back(stoin(inter));
        } 
    }
    cin>>id; ans=str[id];
    FOR(i,0,g[id].size())
    {
        v=g[id][i];
        ans+=str[v];
        FOR(j,0,g[v].size())
        {
            u=g[v][j];
            ans+=str[u];
        }
    }
    cout<<ans<<'\n';

    return 0;
}