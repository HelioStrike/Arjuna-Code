#include <bits/stdc++.h>
#define INF 99999
using namespace std;

int num_steps(int n_machines, int n_workers, int cost, int target, int curr, int epoch, int max_epochs)
{
  if(epoch > max_epochs) return INF;

  curr += n_machines*n_workers;
  if(curr >= target) return epoch;

  int min = INF;
  int buy_max = curr/cost;
  int temp;
  int ok;

  for(int i = 0; i <= buy_max; i++)
  {
    ok = 0;
    if(i == 0) ok = 1;
    for(int j = ok; j <= buy_max-i; j++)
    {
      temp = num_steps(n_machines+i, n_workers+j, cost, target, curr-cost*(i+j), epoch+1, max_epochs);
      if(temp < min)
      {
        min = temp;
      }
    }
  }

  return min;
}

int main()
{
  int n_machines, n_workers, cost, target;
  cin >> n_machines >> n_workers >> cost >> target;

  int n_machines_test = n_machines, n_workers_test = n_workers;
  int max_epochs = 1;
  int buy_max;
  int curr = 0;
  while(true)
  {
    curr += n_machines_test*n_workers_test;
    if(curr >= target) break;

    buy_max = curr/cost;

    n_machines_test += max(0, n_workers_test - n_machines_test);
    n_workers_test += buy_max - max(0, n_workers_test - n_machines_test);

    curr -= buy_max*cost;

    max_epochs++;
  }

  int tot = 1 + num_steps(n_machines, n_workers, cost, target, 0, 0, max_epochs);

  if(tot > max_epochs) tot = max_epochs;

  cout << tot << '\n';

  return 0;
}
