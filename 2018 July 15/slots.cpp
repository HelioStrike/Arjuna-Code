#include <iostream>
using namespace std;

main()
{
  int m, n; cin >> m; cin >> n;
  int slots[m][n];

  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      cin >> slots[i][j];
    }
  }

  int pos[m];
  for(int i = 0; i < m; i++) { pos[i] = n-1;}

  string out = "";
  int largest;
  int l_pos;
  for(int i = 0; i < m*n; i++)
  {
    largest = -1;
    for(int j = 0; j < m; j++)
    {
      if(pos[j] >= 0) {
        if(slots[j][pos[j]] > largest) { largest = slots[j][pos[j]]; l_pos = j;}
      }
    }

    for(int j = 0; j < m; j++)
    {
      if(pos[j] >= 0) {
        if(slots[j][pos[j]] > largest) { largest = slots[j][pos[j]]; l_pos = j;}
      }
    }

    out += to_string(largest);
    pos[l_pos] -= 1;
  }

  cout << out << '\n';
}
