#include <bits/stdc++.h>
#define INF 99999
using namespace std;


int main()
{
  int n_machines, n_workers, cost, target;
  cin >> n_machines >> n_workers >> cost >> target;

  int epoch = 1;
  int buy_max;
  int curr = 0;
  int next;
  int global_min = INF;
  while(true)
  {
    curr += n_machines*n_workers;

    //cout << n_machines << " " <<

    cout << n_machines << " " << n_workers << '\n';

    if(epoch + ((target - curr)/(n_machines*n_workers)) < global_min && curr < target)
    {
      //cout << curr <<
      global_min = epoch + ((target-curr)/(n_machines*n_workers));
    }

    if(curr >= target) break;

    buy_max = curr/cost;
  /*  for(int i = 0; i <= buy_max; i++)
    {
      for(int j = 0; j <= buy_max-i; j++)
      {
        if((curr - (i*j) + (curr + i)*(curr + j)) >= target)
        {
          cout << epoch << '\n';
          exit(0);
        }
      }
    }*/

    next = max(0, (buy_max + n_workers - n_machines)/2);
    n_machines += next;
    n_workers += buy_max - next;

    curr -= buy_max*cost;

    epoch++;
  }

  if(epoch > global_min)
  {
    epoch = global_min;
  }

  cout << epoch << '\n';

  return 0;
}
