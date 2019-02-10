#include <iostream>
#include <list>
#include <string.h>
#include <cstdlib>
using namespace std;

int stoi(char* cp)
{
    int tot = 0;
    int pos = 0;
    int sign = 1;

    if(cp[0]=='-') { sign = -1; pos = 1;}

    while(cp[pos] != '\0')
    {
        tot = 10*tot + cp[pos] - 48;
        pos++;
    }

    return tot;
}

string to_str(int a)
{
    string out = "";

    while(a >= 1)
    {
        out = (char)(a%10 + 48) + out;
        a /= 10;
    }

    return out;
}

main()
{
    int m,n;
    char inp[1000]; cin >> inp;

    char *token = strtok(inp, ",");

    m = stoi(token);
    token = strtok(NULL, ",");
    n = stoi(token);
    token = strtok(NULL, ",");

    int slots[m][n];

    if(m > 20 || m < 1) {
        cout << "Invalid Input M " << m << '\n'; exit(1);
    } else if (n > 50 || n < 1) {
        cout << "Invalid Input N " << n << '\n'; exit(1);
    }

    for(int i = 0; i < m; i++)
    {
        cin >> inp;
        char* token = strtok(inp, ",");
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
    /*
    list <int> repeats;
    list <int> :: iterator list_iter;
    list <int> :: iterator list_iter2;
    int checker_index;
    */
    for(int i = 0; i < m*n; i++)
    {
        //repeats.erase(repeats.begin(), repeats.end());
        //checker_index = 1;
        largest = -1;
        l_pos = 0;

        for(int j = 0; j < m; j++)
        {
            if(pos[j] >= 0) {
                if(slots[j][pos[j]] > largest) {
                    largest = slots[j][pos[j]]; l_pos = j;
                }
            }
        }

        /*
        for(int j = 0; j < m; j++)
        {
            if(pos[j] >= 0) {
                if(slots[j][pos[j]] == largest) {
                    repeats.push_back(j);
                }
            }
        }

        while(true)
        {
            if(repeats.size() < 2) { break;}

            largest = -1;
            for(list_iter = repeats.begin(); list_iter != repeats.end();)
            {
                if(pos[*list_iter]-checker_index < 0)
                {
                    list_iter2 = list_iter;
                    list_iter2++;
                    repeats.remove(*list_iter);
                    list_iter = list_iter2;
                    continue;
                }

                if(slots[*list_iter][pos[*list_iter]-checker_index] > largest)
                {
                    largest = slots[*list_iter][pos[*list_iter]-checker_index];
                }
                list_iter++;
            }

            if(repeats.size() == 1) { l_pos = *(repeats.begin()); break;}
            if(repeats.size() == 0) { break;}

            for(list_iter=repeats.begin(); list_iter != repeats.end();)
            {
                if(slots[*list_iter][pos[*list_iter]-checker_index] != largest)
                {
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
        } */

        out += to_str(slots[l_pos][pos[l_pos]]);
        pos[l_pos] -= 1;
    }
    cout << out << '\n';
}
