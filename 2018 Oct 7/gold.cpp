#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n; cin >> n;
  list<int> containers;

  int curr;
  for(int i = 0; i < n; i++)
  {
    cin >> curr;
    containers.push_back(curr);
  }

  int mini;
  int roundd = 0;
  list<int>::iterator it;
  list<int>::iterator prev;
  while(containers.size() > 1)
  {
    roundd++;
    mini = distance(containers.begin(), min_element(containers.begin(), containers.end()));

    for(it = containers.begin(); it != containers.end();)
    {
      if(*it <= mini+1)
      {
        prev = it;
        it++;
        containers.erase(prev);
        continue;
      }
      *it -= (mini+1);
      it++;
    }

    /*
    for(it = containers.begin(); it != containers.end(); it++)
    {
      cout << (*it) << " ";
    }
    cout << '\n';
    */
  }

  if(containers.size() > 0) cout << "Henry ";
  else cout << "Garry ";
  cout << roundd << '\n';

  return 0;
}
