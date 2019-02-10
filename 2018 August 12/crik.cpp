#include <iostream>
#include <algorithm>
using namespace std;

main()
{
  int N; cin >> N;
  int others[N];

  int n = 1; int curr;
  cin >> others[0];

  for(int i = 1; i < N; i++)
  {
    cin >> curr;
    if(curr != others[n-1]) { others[n] = curr; n += 1;}
  }

  int k; cin >> k;
  int low, high, mid;
  for(int i = 0; i < k; i++)
  {
    cin >> curr;

    low = 0; high = n-1;
    while(low <= high)
    {
      mid = (low + high)/2;

      if(curr == others[mid])
      {
        break;
      }
      else if(curr > others[mid])
      {
        high = mid-1;
      }
      else
      {
        low = mid+1;
      }
    }

    mid = (low + high)/2;

    if(low > high && mid != low) { mid += 1;}

    cout << (mid+1) << '\n';
  }
}
