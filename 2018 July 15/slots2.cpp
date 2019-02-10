#include <iostream>
#include <list>
#include <string.h>
using namespace std;

main()
{
  int m, n;
  char inp[1000];

  cin >> inp;

  char *token = strtok(inp, ",");

  m = stoi(token);
  token = strtok(NULL, ",");
  n = stoi(token);
  token = strtok(NULL, ",");

  int slots[m][n];

  if (m > 20) {
    cout << "Invalid Input M " << m << '\n'; exit(1);
  } else if (n > 50) {
    cout << "Invalid Input N " << n << '\n'; exit(1);
  }

  for(int i = 0; i < m; i++) {
    cin >> inp;

    char *token = strtok(inp, ",");

    for(int j = 0; j < n; j++)
    {
        slots[i][j] = stoi(token);
        token = strtok(NULL, ",");
    }
  }

  int pos[m];
  for(int i = 0; i < m; i++) { pos[i] = n-1;}

  string out = "";
  int largest;
  int l_pos;
  list <int> repeats;
  list <int> :: iterator list_iter;
  list <int> :: iterator list_iter2;
  int checker_index;
  int checker_largest;
  for(int i = 0; i < m*n; i++)
  {
    checker_index = 1;
    repeats.erase(repeats.begin(), repeats.end());

    largest = -1;
    l_pos = 0;

    for(int j = 0; j < m; j++)
    {
      if(pos[j] >= 0) {
        if(slots[j][pos[j]] > largest) { largest = slots[j][pos[j]]; l_pos = j;}
      }
    }

    for(int j = 0; j < m; j++)
    {
      if(pos[j] >= 0) {
        if(slots[j][pos[j]] == largest) { repeats.push_back(j);}
      }
    }

    while(true) {

      if(repeats.size() < 2) { break;}

      largest = -1;
      for(list_iter = repeats.begin(); list_iter != repeats.end();) {
        if(pos[*list_iter]-checker_index < 0)
        {
          list_iter2 = list_iter;
          list_iter2++;
          repeats.remove(*list_iter);
          list_iter = list_iter2;
          continue;
        }
        if(slots[*list_iter][pos[*list_iter]-checker_index] > largest) { largest = slots[*list_iter][pos[*list_iter]-checker_index];}
        list_iter++;
      }

      if(repeats.size() == 1) { l_pos = *(repeats.begin());break;}
      if(repeats.size() == 0) { break;}


      for(list_iter = repeats.begin(); list_iter != repeats.end();) {
        if(slots[*list_iter][pos[*list_iter]-checker_index] != largest) {
          list_iter2 = list_iter;
          list_iter2++;
          repeats.remove(*list_iter);
          list_iter = list_iter2;
          continue;
        }
        list_iter++;
      }

      if(repeats.size() == 0) { break;}
      l_pos = *(repeats.begin());
      checker_index += 1;
    }

    out += to_string(slots[l_pos][pos[l_pos]]);
    pos[l_pos] -= 1;
  }

  cout << out << '\n';
}
