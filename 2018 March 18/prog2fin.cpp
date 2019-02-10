#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

//The backtrack part is pretty inefficient. Will be optimized (hopefully)tomorrow(the tomorrow for 19/3/2018) as its pretty late now

//gives out how many words are mapped correctly
int numMatch(string dict[], vector<string> enc, int dictlens[], vector<int> enclens, char ciphchars[26], int num)
{
    int n = 0;
    int x;
    int same;
    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j < enc.size(); j++)
        {
            x = 0;
            same = 1;
            if((dictlens[i]!=enclens[j])&&(dictlens[i]>enclens[j]))
            {
                break;
            }

            if(dictlens[i] < enclens[j])
            {
                continue;
            }

            while(dict[i][x]!='\0')
            {
                if(dict[i][x]!=ciphchars[(int)(enc[j][x]-97)])
                {
                    same = 0;
                    break;
                }
                x++;
            }
            if(same)
            {
                n++;
            }
        }
    }
    return n;
}

//does the magical part of the program.
int ok(string dict[], vector<string> enc, int dictlens[], vector<int> enclens, char ciphchars[26], char ciphchars_run[26], int num, int *num_matches, int curr_elem)
{
    int n = numMatch(dict, enc, dictlens, enclens, ciphchars_run, num);
    if(n > *num_matches)
    {
        *num_matches = n;
        for(int i = 0; i < 26; i++)
        {
            ciphchars[i] = ciphchars_run[i];
        }
    }

    if(*num_matches==enc.size())
    {
        return 1;
    }

    //if mapping gets repeated, return
    for(int x = 0; x < 26; x++)
    {
        for(int y = x+1; y < 26; y++)
        {
            if(ciphchars_run[x]=='*')
            {
                break;
            }

            if(ciphchars_run[y]!='*')
            {
                if(ciphchars_run[x]==ciphchars_run[y])
                {
                    return 0;
                }
            }
        }
    }

    //if number of matches is greater than the previous one,
    //copy running ciphchars yo orginal ciphchars

    char ciphchars_track[26];

    //array for backtracking
    for(int i = 0; i < 26; i++)
    {
        ciphchars_track[i] = ciphchars_run[i];
    }

    //go over the whole dict
    for(int i = 0; i < num; i++)
    {
        if(dictlens[i]==enclens[curr_elem])
        {
            //go forward by fitting the next word to ciphchars
            int k = 0;
            while(enc[curr_elem][k] != '\0')
            {
                if(ciphchars_run[(int)(enc[curr_elem][k]-97)]=='*')
                {
                    ciphchars_run[(int)(enc[curr_elem][k]-97)] = dict[i][k];
                }
                k++;
            }
            if(ok(dict, enc, dictlens, enclens, ciphchars, ciphchars_run, num, num_matches, i+1))
            {
                return 1;
            }

            //backtrack
            for(int j = 0; j < 26; j++)
            {
                ciphchars_run[j] = ciphchars_track[j];
            }
        }
    }
}

main()
{
    int num;
    cin >> num;

    //dictionary variables
    string dict[num];
    int dictlens[num];

    int x,y;

    //maps i-th alphabet to ciphchars[i]
    char ciphchars[26];

    for(int i = 0; i < 26; i++)
    {
        ciphchars[i] = '*';
    }

    //inputting dict and lengths of each word
    for(int i = 0; i < num; i++)
    {
        cin >> dict[i];
        x = 0;
        while(dict[i][x] != '\0'){x++;}
        dictlens[i] = x;
    }

    //Cipher text variables
    vector<string> enc;
    vector<int> enclens;
    string inp;

    char c;
    //String isn't quite necessary here, but its 1 am now
    //Will sort of help in the end but not quite worth the cost.
    char str[80];

    x = 0;
    y = 0;
    while(true)
    {
        y = 0;
        cin >> inp;
        enc.push_back(inp);

        while(inp[y] != '\0')
        {
            str[x] = inp[y];
            x++;
            y++;
        }
        str[x] = ' ';
        x++;

        c = getchar();
        if(c=='\0'||c=='\n')
        {
            break;
        }
    }
    str[x] = '\0';

   //calculating lengths of words in cipher text
    for(int i = 0; i < enc.size(); i++)
    {
        x = 0;
        while(enc[i][x]!='\0'){ x++;}
        enclens.push_back(x);
    }

    //temp variables for bubble-sorting by length of words
    int tmp;
    string tmpstr;

    //Why bubblesort? Its the easiest one to use
    //sorting dict words and lengths by length of variables, in descending order
    for(int i = 0; i < enc.size(); i++)
    {
        for(int j = 0; j < enc.size(); j++)
        {
            if(enclens[j]<enclens[j+1])
            {
                tmp = enclens[j];
                enclens[j] = enclens[j+1];
                enclens[j+1] = tmp;

                tmpstr = enc[j];
                enc[j] = enc[j+1];
                enc[j+1] = tmpstr;
            }
        }
    }

   //sorting ciphertext words and lengths by length, in descending order
    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j < num; j++)
        {
            if(dictlens[j]<dictlens[j+1])
            {
                tmp = dictlens[j];
                dictlens[j] = dictlens[j+1];
                dictlens[j+1] = tmp;

                tmpstr = dict[j];
                dict[j] = dict[j+1];
                dict[j+1] = tmpstr;
            }
        }
    }
    int same = 0; //to see if the word length is unique
    int asdf = 0; //to see if mapping repeats
    //if there are unique word-lengths, map them immediately
    for(int i = 0; i < num; i++)
    {
        for(int j = i+1; j < num; j++)
        {
            if(dictlens[i] == dictlens[j])
            {
                same = 1;
                break;
            }
        }

        if(!same)
        {
            for(int j = 0; j < enclens.size(); j++)
            {
                if(dictlens[i] == enclens[j])
                {
                    int k = 0;
                    while(enc[j][k] != '\0')
                    {
                        if(ciphchars[(int)(enc[j][k]-97)] == '*'||(ciphchars[(int)(enc[j][k]-97)] == dict[i][k]))
                        {
                            ciphchars[(int)(enc[j][k]-97)] = dict[i][k];
                        }

                        k++;
                    }
                }
            }
        }
    }

   //if the mapping gets repeated, revert ciphchars to stars
    for(int i = 0; i < 26; i++)
    {
        for(int j = i+1; j < 26; j++)
        {
            if(ciphchars[i]=='*')
            {
                break;
            }

            if(ciphchars[j]!='*')
            {
                if(ciphchars[i]==ciphchars[j])
                {
                    asdf = 1;
                }
            }
        }
    }

    //equating to stars
    if(asdf)
    {
        for(int i = 0; i < 26; i++)
        {
            ciphchars[i] = '*';
        }
    }

    //num_matches = number of that are mapped correctly
    int *num_matches = new int;
    *num_matches = numMatch(dict, enc, dictlens, enclens, ciphchars, num);

    //and here the magic happens
    if(*num_matches!=enc.size())
    {
        //running version of ciphchars
        char ciphchars_run[26];
        for(int i = 0; i < 26; i++)
        {
            ciphchars_run[i] = ciphchars[i];
        }
        //does the magic
        ok(dict, enc, dictlens, enclens, ciphchars, ciphchars_run, num, num_matches, 0);
    }

    //if not all words match correctly, equate ciphchars to stars
    if(numMatch(dict, enc, dictlens, enclens, ciphchars, num)!=enc.size())
    {
        for(int j = 0; j < 26; j++)
        {
            ciphchars[j] = '*';
        }
    }

    //apply ciphchars to cipher text and print out
    int k = 0;
    while(str[k]!='\0')
    {
        if(str[k] == ' ')
        {
            cout << ' ';
        }
        else
        {
            cout << (char)(ciphchars[(int(str[k]-97))]);
        }
        k++;
    }

    cout << '\n';
}
