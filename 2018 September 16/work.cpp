#include <iostream>
using namespace std;

int main()
{
  int rows, n;
  int bob, tom;
  int bob_pos, tom_pos;

  for(int row = 0; row < rows; row++)
  {
    cin >> n;
    int arr[n];
    int tot = 0;
    for(int i = 0; i < n; i++) { cin >> arr[i]; tot += arr[i];}

    bob_pos = 0; tom_pos = n-1;
    bob = arr[bob_pos]; tom = arr[tom_pos];

    while(1)
    {
      
    }
  }

  return 0;
}
