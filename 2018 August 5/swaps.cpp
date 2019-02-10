#include <iostream>
#define MIN(a,b) (a>b?b:a)
using namespace std;

int minimumSwaps(int pos[], int n)
{
  int visited[n];
  for(int i = 0; i < n; i++) { visited[i] = 0;}

  int ans = 0;
  for (int i = 0; i < n; i++)
  {
      if (visited[i] || pos[i] == i) { continue;}

      int size = 0;
      int vis = i;
      while (!visited[vis])
      {
          visited[vis] = 1;

          vis = pos[vis];
          size++;
      }

      ans += (size - 1);
  }

  return ans;
}

main()
{
  int n; cin >> n;
  int arr[n];
  int arr_dec[n];
  int pos[n];
  int pos_dec[n];

  for(int i = 0; i < n; i++) { cin >> arr[i]; arr_dec[i] = arr[i]; pos[i] = i; pos_dec[i] = i;}

  int temp;
  for(int i = 0; i < n-1; i++)
  {
    for(int j = 0; j < n-i-1; j++)
    {
      if(arr[j] > arr[j+1])
      {
        temp = arr[j+1];
        arr[j+1] = arr[j];
        arr[j] = temp;

        temp = pos[j+1];
        pos[j+1] = pos[j];
        pos[j] = temp;
      }
    }
  }

  for(int i = 0; i < n-1; i++)
  {
    for(int j = 0; j < n-i-1; j++)
    {
      if(arr_dec[j] < arr_dec[j+1])
      {
        temp = arr_dec[j+1];
        arr_dec[j+1] = arr_dec[j];
        arr_dec[j] = temp;

        temp = pos_dec[j+1];
        pos_dec[j+1] = pos_dec[j];
        pos_dec[j] = temp;
      }
    }
  }

  int ans_asc = minimumSwaps(pos, n);
  int ans_dec = minimumSwaps(pos_dec, n);
  cout << MIN(ans_asc, ans_dec) << '\n';
}
