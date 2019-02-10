#include <iostream>
using namespace std;

int solve_util(int coins[], int checkpoints[], int curr_pos, int num, int curr_gold, int n)
{
  if(num == n) { return 1;}

  int posn = curr_pos%n;
  curr_gold = curr_gold + coins[posn] - checkpoints[posn];

  if(curr_gold >= 0)
  {
    return solve_util(coins, checkpoints, curr_pos + 1, num + 1, curr_gold, n);
  }
  else
  {
    return 0;
  }
}

int main()
{
  int n; cin >> n;
  int coins[n];
  int checkpoints[n];

  for(int i = 0; i < n; i++) { cin >> coins[i] >> checkpoints[i];}

  int curr_coins;
  for(int i = 0; i < n; i++)
  {
    curr_coins = coins[i] - checkpoints[i];
    if(curr_coins < 0) continue;

    if(solve_util(coins, checkpoints, i+1, 1, curr_coins, n))
    {
      cout << 1 << '\n';
      return 1;
    }
  }

  cout << -1 << '\n';
  return 0;
}
