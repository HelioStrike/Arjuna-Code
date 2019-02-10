#include <iostream>
#include <stdio.h>
using namespace std;

/*
2 Predators and Prey

David King, a budding scientist, has designed a small game of wars with three types of characters Vofnan, Nural and Baf.
These that live in different colonies arranged in the form of a grid.
Each type of character regularly wages wars against other characters living one step away (in any of the four directions)
from its colony. A war can continue for n-days. In the wars, Vofnanians can defeat Nurals only,
Nurals can defeat Bafs only and Bafs can defeat Vofnanians only.
The winner occupies the loser’s colony. The toughest survives till end of the war.

Write a program to accept number of days of a war, size of grid colony (rows and columns are always equal)
and occupants (first letter of the name), and display the name of the character separated by a space and
total number of new colonies won (indicated by +) and lost (indicated by -) for each character in separate line.
The order of output is always V, N and B.

For any invalid input, display invalid input followed by input values given.

sample input :
2 4 4
VVNB
BBNN
VVBN
BBVV

sample output :
V -1
N +1
B 0


sample input :
-1 4 4

sample output :
invalid input -1 4 4

*/

main()
{
    int num_days; cin >> num_days;
    int rows; cin >> rows;
    int cols; cin >> cols;

    if(!(num_days>0&&rows>0&&cols>0)) { cout << "invalid input " << num_days << ' ' << rows << ' ' << cols << '\n'; return 0; }

    char map[rows][cols];
    int v1 = 0; int b1 = 0; int n1 = 0;
    int v2 = 0; int b2 = 0; int n2 = 0;

    getchar();
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            map[i][j] = getchar();
            if(map[i][j]=='V') { v1++;}
            else if(map[i][j]=='B') { b1++;}
            else if(map[i][j]=='N') { n1++;}
        }
        getchar();
    }

    int moves_x[4] = {1, 0, 0, -1};
    int moves_y[4] = {0, 1, -1, 0};

    char map_prev[rows][cols];
    int next_x, next_y;

    for(int x = 0; x < num_days; x++)
    {
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                map_prev[i][j] = map[i][j];
            }
        }

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                for(int k = 0; k < 4; k++)
                {
                    next_x = i + moves_x[k];
                    next_y = j + moves_y[k];
                    if(next_x>=0&&next_x<rows&&next_y>=0&&next_y<cols)
                    {
                        if(map_prev[i][j]=='V')
                        {
                            if(map_prev[next_x][next_y]=='B'){ map[i][j] = 'B'; break;}
                        }

                        if(map_prev[i][j]=='B')
                        {
                            if(map_prev[next_x][next_y]=='N'){ map[i][j] = 'N'; break;}
                        }

                        if(map_prev[i][j]=='N')
                        {
                            if(map_prev[next_x][next_y]=='V'){ map[i][j] = 'V'; break;}
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(map[i][j]=='V') { v2++;}
            else if(map[i][j]=='B') { b2++;}
            else if(map[i][j]=='N') { n2++;}
        }
    }

    v2 -= v1;
    b2 -= b1;
    n2 -= n1;

    if(v2>0)
    {
        cout << "V " << '+' << v2 << '\n';
    }
    else
    {
        cout << "V " << v2 << '\n';
    }

    if(n2>0)
    {
        cout << "N " << '+' << n2 << '\n';
    }
    else
    {
        cout << "N " << n2 << '\n';
    }

    if(b2>0)
    {
        cout << "B " << '+' << b2 << '\n';
    }
    else
    {
        cout << "B " << b2 << '\n';
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << map[i][j];
        }
        cout << '\n';
    }
}
