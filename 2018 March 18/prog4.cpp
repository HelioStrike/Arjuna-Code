#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
  int i, j, k;
  int n1 = mid-low+1;
  int n2 = high-mid;

  int L[n1], R[n2];

  for(int i = 0; i < n1; i++)
  {
    L[i] = arr[low+i];
  }

  for(int i = 0; i < n2; i++)
  {
    R[i] = arr[mid+1+i];
  }

  i = 0;
  j = 0;
  k = low;

  while(i < n1 && j < n2)
  {
    if(L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while(i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  while(j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }

}

void mergeSort(int arr[], int low, int high)
{
  if(low < high)
  {
    int mid = (low+high)/2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);

    merge(arr, low, mid, high);
  }
}

main()
{
  int cases;
  cin >> cases;

  int num;
  float med, sum, n;
  while(cases--)
  {
    sum = 0;
    cin >> num;
    int arr[num];
    for(int i = 0; i < num; i++)
    {
      cin >> arr[i];
    }
    mergeSort(arr, 0, num-1);

    if(num%2)
    {
      med = arr[num/2];
    }
    else
    {
      med = ((arr[num/2]+arr[num/2-1])/2);
    }

    for(int i = 0; i < num; i++)
    {
      n = (arr[i]-med);
      if(n < 0)
      {
        n = -n;
      }
      sum += n;
    }
    cout << sum << '\n';
  }
}
