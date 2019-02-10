#include <iostream>
#include <vector>
using namespace std;

main()
{
    int size;
    cin >> size;

    int num;
    cin >> num;

    //finding individual digits
    vector<int> digits;
    while(num!=0)
    {
        digits.push_back(num%10);
        num /= 10;
    }

    //reversing digits array since 1234 would be stored as 4321 until now
    int temp;
    for(int i = 0; i < digits.size()/2; i++)
    {
        temp = digits[i];
        digits[i] = digits[digits.size()-i-1];
        digits[digits.size()-i-1] = temp;
    }

    //     0
    //     --
    //   1|  |2
    //    |  |
    //     --3
    //   4|  |5
    //    |  |
    //     --
    //      6
    //those are numbers assigned to those segments


    //manually typed in whether the segment would light up for that particular number
    int zones[10][7] = {{1,1,1,0,1,1,1},
    {0,0,1,0,0,1,0},                        //For 1
    {1,0,1,1,1,0,1},                        //  |2
    {1,0,1,1,0,1,1},                        //  |
    {0,1,1,1,0,1,0},                        //
    {1,1,0,1,0,1,1},                        //  |3
    {1,1,0,1,1,1,1},                        //  |
    {1,0,1,0,0,1,0},                        //Only segment 2 and 5 would light up, so the rest are 0
    {1,1,1,1,1,1,1},
    {1,1,1,1,0,1,1}};

    int doit;
    int doit1;
    int doit2;

    //looping over segments
    for(int a = 0; a < 7; a++)
    {
        //if a%3==0 is satisfied, then that segment is a horizontal one
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
        else    //else, its vertical
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
