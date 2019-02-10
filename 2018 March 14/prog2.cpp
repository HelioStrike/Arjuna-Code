#include <iostream>
using namespace std;

main()
{
  int num_days, num_bus;
  cin >> num_days;
  cin >> num_bus;

  int days[num_days];
  for(int i = 0; i < num_days; i++)
  {
    days[i] = 0;
  }
  int strike[num_bus];

  for(int i = 0; i < num_bus; i++)
  {
    cin >> strike[i];
  }

  for(int i = 0; i < num_bus; i++)
  {
    for(int j = strike[i]-1; j < num_days; j+=strike[i])
    {
      if((j%7!=5) && (j%7!=6) && (days[j]!=1))
      {
        days[j] = 1;
      }
    }
  }

  int sum = 0;
  for(int i = 0; i < num_days; i++)
  {
    sum += days[i];
  }
  cout << sum << '\n';
}
