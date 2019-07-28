#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
using namespace std;

// Consider input strings 's', 't'
// Store characters of t in a map
// Traverse the 2 strings and if they match, we have an arrow,
// else we check the map for matches elsewhere in the string, and its a bow.
// Time Complexity - O(n)

// n - length of string s/t
// a - number of arrows, b - number of bows
// s,t - input strings
// m - map for characters of s
int n,a,b;
string s,t;
map<int,int> m;

int main()
{
    // Taking input
    cin>>s>>t; n=s.length();

    // Storing characters of t in a map
    FOR(i,0,n) m[t[i]]++;

    // Traverse strings and calculate arrows and bows
    FOR(i,0,n)
    {
        if(s[i]==t[i]) a++,m[s[i]]--;
        else if(m[s[i]])  b++,m[s[i]]--;
    }
    cout<<a<<'A'<<b<<'B'<<'\n';

    return 0;
}