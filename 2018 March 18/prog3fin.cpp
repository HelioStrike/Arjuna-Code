#include <iostream>
using namespace std;

main()
{
    int num = 1000;
    int incl=0;

    //for each iteration
    while(num--)
    {
        //input 2 strings
        string str1;
        string str2;
        cin >> str1;
        cin >> str2;

        //used to count the number of times each char appears in string 1 and string 2
        //finnums = minimum(str1nums, str2nums)
        int str1nums[26];
        int str2nums[26];
        int finnums[26];

        //initializing all 3 arrays to 0
        for(int i = 0; i < 26; i++)
        {
            str1nums[i] = 0;
            str2nums[i] = 0;
            finnums[i] = 0;
        }

        //counting number of times a particular char has appeared in str1
        for(int i = 0; str1[i]!='\0';i++)
        {
            str1nums[(int)(str1[i]-97)]++;
        }

        //counting number of times a particular char has appeared in str2
        for(int i = 0; str2[i]!='\0';i++)
        {
            str2nums[(int)(str2[i]-97)]++;
        }

        //preparing fin nums
        for(int k = 0; k < 26; k++)
        {
            if(str1nums[k] < str2nums[k])
            {
                finnums[k] = str1nums[k];
            }
            else
            {
                finnums[k] = str2nums[k];
            }
        }

        //printing out the characters
        for(int i = 0; i < 26; i++)
        {
            for(int j = 0; j < finnums[i]; j++)
            {
                cout << (char)(i+97);
            }
        }

        cout << '\n';
    }
}
