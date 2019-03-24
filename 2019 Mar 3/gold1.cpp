#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
using namespace std;


int main()
{
    float n,k,ans; scanf("%f%f",&n,&k);
    printf("%d\n",(int)ceil(n*(1-(1.0f/k))));

    return 0;
}