#include <iostream>
using namespace std;

int main()
{
  int n; cin >> n;
  int coins[n];
  int checkpoints[n];

  for(int i = 0; i < n; i++) { cin >> coins[i] >> checkpoints[i];}

  int curr_coins;
  int possible;
  for(int i = 0; i < n; i++)
  {
    curr_coins = 0;
    possible = 1;

    for(int j = 0; j < n; j++)
    {
      int posn = (i + j)%n;
      curr_coins += coins[posn] - checkpoints[posn];
      if(curr_coins < 0){ possible = 0; break;}
    }

    if(possible) { cout << i << '\n'; return 0;}
  }

  cout << -1 << '\n';
  return 0;
}
