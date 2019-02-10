#include <iostream>
using namespace std;

main()
{
    int cases;
    int num_books;
    int num_authors;

    cin >> cases;
    cin >> num_books;
    cin >> num_authors;

    string name_list[num_authors*num_books];
    string rank_list[num_authors*num_books];

    int i = 0;
    int j = 0;

    name_list[0] = "Neil, Gogte";
    rank_list[0] = 1;

    string inf;
    string chek;
    char c;
    int k;
    int l;

    while(num_books--)
    {
      cin >> inf;
      k=0;
      while(num_authors--)
      {
        l = 0;
        while((c=inf[k]) != '.')
        {
          chek[l] = inf[k];
          k++;
          l++;
          cout <<  k << ' ' << inf[k] << ' ' << l << ' ' << chek[l] << '\n';
        }
        chek[l] = '\0';
        k += 2;
        cout << chek << '\n';
      }
    }

}
