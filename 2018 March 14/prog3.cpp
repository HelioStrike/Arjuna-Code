#include <iostream>
using namespace std;

main()
{
  int l,r;
  cin >> l;
  cin >> r;


  int num;
  int num_steps = 500000;
  int steps[num_steps];

  for(int i = 0; i < num_steps; i++)
  {
    steps[i] = 0;
  }

  int len = 0;
  int max = 0;
  steps[1] = 1;
  steps[2] = 2;

  if(l == 0)
  {
    l++;
  }

  for(int i = l; i <= r; i++)
  {
    num = i;
    len = 0;
    do
    {
      if(steps[num] != 0)
      {
        len += steps[num];
        break;
      }

      if(num&1)
      {
        num = num*3+1;
      }
      else
      {
        num >>= 1;
      }

      len++;
    }while(num!=1);

    steps[i] = len;
    if(len > max)
    {
      max = len;
    }
  }
  cout << max << '\n';
}
