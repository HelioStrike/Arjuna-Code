#include <iostream>
using namespace std;

main()
{
  int n, t; cin >> n >> t;
  int buyers[n][2];
  int baskets[t][3];

  for(int i = 0; i < n; i++)
  {
    cin >> buyers[i][0] >> buyers[i][1];
  }

  for(int i = 0; i < t; i++)
  {
    baskets[i][0] = 1;
    cin >> baskets[i][1] >> baskets[i][2];
  }

  int tot = 0;
  int curr_min;
  for(int i = 0; i < n; i++)
  {
    curr_min = -1;
    for(int j = 0; j < t; j++)
    {
      if(baskets[j][0] == 0) { continue;}
      else
      {
        if(curr_min == -1 && baskets[j][1] > buyers[i][0] && baskets[j][2] < buyers[i][1]) { curr_min = j;}
        else if(baskets[j][1] >= buyers[i][0] && baskets[j][2] <= buyers[i][1])
        {
          if(baskets[j][1] < baskets[curr_min][1] || baskets[j][2] > baskets[curr_min][2])
          {
            curr_min = j;
          }
          else if(baskets[j][1] == baskets[curr_min][1] && baskets[j][2] > baskets[curr_min][2])
          {
            curr_min = j;
          }
          else if(baskets[j][1] < baskets[curr_min][1] && baskets[j][2] == baskets[curr_min][2])
          {
            curr_min = j;
          }
        }
      }
    }

    if(curr_min != -1)
    {
      tot += 1;
      baskets[curr_min][0] = 0;
    }
  }
  cout << tot << '\n';
}
