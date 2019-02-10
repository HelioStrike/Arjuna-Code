#include <iostream>
using namespace std;

main()
{
  int n; cin >> n;
  int sum;

  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < i+1; j++)
    {
      sum = 0;
      for(int k = n; k > 5 - j - 1; k--) { sum += k;}

      if(j%2==0) { cout << (sum - n + i + 1) << " ";}
      else { cout << (sum - i + j) << " ";}
    }
    cout << '\n';
  }
}
