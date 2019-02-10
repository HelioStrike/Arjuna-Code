#include <iostream>
using namespace std;

main()
{
  int n, t; cin >> n >> t;
  int arr[n][t];
  int chek[n];
  memset(arr, 0, sizeof(arr[0][0])*n*t);
  memset(chek, 0, sizeof(chek[0])*n);

  int t1, t2; cin >> t1 >> t2;
  chek[t1][0] = 1; chek[t2][0] = 1;

  int pos_found;
  for(int i = 1; i < t; i++)
  {
    cin >> t1 >> t2;
    pos_found = 0;
    for(int j = 0; j < t; j++)
    {
      if(chek[j] == 0) { continuel}
      if(arr[t1][j] == 1)
      {
        arr[t2][j] = 1;
        pos_found = 1;
        break;
      }
      else if (arr[t2][j] == 1)
      {
        arr[t1][j] = 1;
        pos_found = 1;
        break;
      }
    }
  }
}
