#include <iostream>
using namespace std;

int main()
{
  int n; cin >> n;
  int arr[n];
  int chek[n];
  for(int i = 0; i < n; i++) { cin >> arr[i]; chek[i] = 0;}
  int change, prev;

  int epoch = 0;
  while(1)
  {
    change = 0;
    prev = arr[0];
    for(int i = 1; i < n; i++)
    {
      if(!chek[i])
      {
        if(arr[i] > prev)
        {
          chek[i] = 1;
          change = 1;
        }
        prev = arr[i];
      }
    }

    epoch++;
    if(!change) { break;}
  }
  cout << (epoch-1) << '\n';

  return 0;
}
