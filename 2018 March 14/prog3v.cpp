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

  int len1 = 1;
  int max1 = 0;
  int len2 = 0;
  int max2 = 0;
  steps[1] = 1;
  steps[2] = 2;

  if(l == 0)
  {
    l++;
  }

  for(int i = l; i <= r; i++)
  {
    num = i;
    len1 = 1;
    while(num!=1)
    {
      if(num&1)
      {
        num = num*3+1;
      }
      else
      {
        num >>= 1;
      }

      len1++;
    }

    num = i;
    len2 = 0;
    while(num!=1)
    {
      if(steps[num] != 0)
      {
        len2 += steps[num];
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

      len2++;
    }
    if(len1 > max1)
    {
      max1 = len1;
    }

    if(len2 > max2)
    {
      max2 = len2;
    }

    if(len1 != len2)
    {
      cout << len1 << ' ' << len2 << ' ' << i << '\n';
    }
  }
}
