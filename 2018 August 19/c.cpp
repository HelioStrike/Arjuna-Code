#include <iostream>
using namespace std;

main()
{
  int n, w; cin >> n >> w;
  int arr[n];
  for(int i = 0; i < n; i++) { cin >> arr[i];}

  int tot = 10000000;
  int curr_tot, curr_pos;
  for(int i = 0; i < w; i++)
  {
    curr_tot = 0;
    curr_pos = i;
    while(curr_pos < n)
    {
      curr_tot += arr[curr_pos];
      curr_pos += (2*w+1);
    }
    if(curr_tot < tot) { tot = curr_tot;}
  }
  cout << tot << '\n';
}
