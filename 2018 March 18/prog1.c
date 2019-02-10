#include <iostream>
#include <vector>
using namespace std;

main()
{
    int size;
    cin >> size;

    int num;
    cin >> num;

    vector<int> digits;
    while(num!=0)
    {
        digits.push_back(num%10);
        num /= 10;
    }

    int temp;
    for(int i = 0; i < digits.size()/2; i++)
    {
        temp = digits[i];
        digits[i] = digits[digits.size()-i-1];
        digits[digits.size()-i-1] = temp;
    }

    int zones[10][7] = {{1,1,1,0,1,1,1},
    {0,0,1,0,0,1,0},
    {1,0,1,1,1,0,1},
    {1,0,1,1,0,1,1},
    {0,1,1,1,0,1,0},
    {1,1,0,1,0,1,1},
    {1,1,0,1,1,1,1},
    {1,0,1,0,0,1,0},
    {1,1,1,1,1,1,1},
    {1,1,1,1,0,1,1}};

    int doit;
    int doit1;
    int doit2;

    for(int a = 0; a < 7; a++)
    {
        if(a%3==0)
        {
            for(int i = 0; i < digits.size(); i++)
            {
                doit = zones[digits[i]][a];
                if(doit)
                {
                    cout << " ";
                    for(int j = 0; j < size; j++)
                    {
                        cout << "-";
                    }
                    cout << "  ";
                }
                else
                {
                    for(int j = 0; j < size+3; j++)
                    {
                        cout << " ";
                    }
                }
            }
            cout << '\n';
        }
        else
        {
            for(int i = 0; i < size; i++)
            {
                for(int j = 0; j < digits.size(); j++)
                {
                    doit1 = zones[digits[j]][a];
                    doit2 = zones[digits[j]][a+1];

                    if(doit1)
                    {
                        cout << '|';
                    }
                    else
                    {
                        cout << ' ';
                    }

                    for(int i = 0; i < size; i++)
                    {
                        cout << ' ';
                    }

                    if(doit2)
                    {
                        cout << '|';
                    }
                    else
                    {
                        cout << ' ';
                    }
                    cout << ' ';
                }
                cout << '\n';
            }
            a++;
        }
    }
}
