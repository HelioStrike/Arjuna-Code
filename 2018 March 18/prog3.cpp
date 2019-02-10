#include <iostream>
#include <vector>
using namespace std;

main()
{
    int num = 1000;
    vector<char> same;
    int incl=0;

    while(num--)
    {
        string str1;
        string str2;
        cin >> str1;
        cin >> str2;

        same.clear();

        for(int i = 0; str1[i]!='\0';i++)
        {
            for(int j = 0; str2[j]!='\0';j++)
            {
                if(str1[i]==str2[j])
                {
                    incl = 0;
                    for(int k = 0; k < same.size(); k++)
                    {
                        if(str1[i] == same[k])
                        {
                            incl = 1;
                            break;
                        }
                    }
                    if(!incl)
                    {
                        same.push_back(str1[i]);
                        incl = 0;
                    }
                }
            }
        }

        for(int k = 0; k < same.size(); k++)
        {
            cout << same[same.size()-k-1];
        }
        cout << '\n';
    }
}
