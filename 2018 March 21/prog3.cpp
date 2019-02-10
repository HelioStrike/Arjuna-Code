#include <iostream>
using namespace std;

main()
{
  int cases;
  int storage[10];
  int memory[1000];
  int ins, a, b;

  for(int i = 0; i < 10; i++)
  {
    storage[i] = 0;
  }

  for(int i = 0; i < 1000; i++)
  {
    memory[i] = 0;
  }

  cin >> cases;
  cin >> num;

  while(cases--)
  {

    for(int i = 0; i < 10; i++)
    {
      storage[i] = 0;
    }

    for(int i = 0; i < 1000; i++)
    {
      memory[i] = 0;
    }

    int i = 0;
    while((i!=10)&&(num!=100))
    {
      cin >> num;

      b = num%10;
      num /= 10;
      a = num%10;
      num /= 10;
      ins = num%10;
      num /= 10;

      if(ins = 1)
      {
        isGoto = 1;
      }

      i++;
    }
  }
}
