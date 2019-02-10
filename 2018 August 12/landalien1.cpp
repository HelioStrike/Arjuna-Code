#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool sortrev(const int &a, const int &b)
{
       return (a > b);
}

main()
{
  int n; cin >> n;
  int aliens[n];

  for(int i = 0; i < n; i++)
  {
    cin >> aliens[i];
  }

  sort(aliens, aliens + n, sortrev);

  int max = 0;
  int tot = 0;
  int curr;

  for(int i = 0; i < n; i++)
  {
    tot += aliens[i];
    curr = (n-i)*tot;
    if(curr > max) { max = curr;}
  }
  cout << max << '\n';
}
