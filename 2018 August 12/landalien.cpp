#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int dynamo(int aliens[], int n, int curr, int g)
{
  if(curr == n)
  {
    return 0;
  }

  int a = dynamo(aliens, n, curr+1, g+1);
  int b = g*aliens[curr] + dynamo(aliens, n, curr+1, g);

  return (a>b?a:b);
}

main()
{
  int n; cin >> n;
  int aliens[n];

  for(int i = 0; i < n; i++)
  {
    cin >> aliens[i];
  }

  sort(aliens, aliens + n);

  int g = 1;
  cout << dynamo(aliens, n, 0, g) << '\n';
}
