#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;

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
      if((dictlens[i]!=enclens[j])&&dictlens[i]>enclens[j])
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

  //checking if repeated chars in ciphchars
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

  char ciphchars_track[26];

  for(int i = 0; i < 26; i++)
  {
    ciphchars_track[i] = ciphchars_run[i];
  }

  for(int i = 0; i < num; i++)
  {


    if(dictlens[i]==enclens[curr_elem])
    {
      int k = 0;
      while(enc[curr_elem][k] != '\0')
      {
        if(ciphchars_run[(int)(enc[curr_elem][k]-97)] == '*')
        {
            ciphchars_run[(int)(enc[curr_elem][k]-97)] = dict[i][k];
        }

        k++;
      }

      if(ok(dict, enc, dictlens, enclens, ciphchars, ciphchars_run, num, num_matches, i+1))
      {
        return 1;
      }

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

    string dict[num];
    int dictlens[num];

    int x,y;

    char ciphchars[26];

    for(int i = 0; i < 26; i++)
    {
        ciphchars[i] = '*';
    }

    for(int i = 0; i < num; i++)
    {
        cin >> dict[i];
        x = 0;
        while(dict[i][x] != '\0'){x++;}
        dictlens[i] = x;
    }


    vector<string> enc;
    vector<int> enclens;
    string inp;

    char c;
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


    for(int i = 0; i < enc.size(); i++)
    {
        x = 0;
        while(enc[i][x]!='\0'){ x++;}
        enclens.push_back(x);
    }

    int tmp;
    string tmpstr;
    for(int i = 0; i < enc.size(); i++)
    {
      for(int j = 0; j < enc.size()-i-1; j++)
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

    for(int i = 0; i < num; i++)
    {
      for(int j = 0; j < num-i-1; j++)
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


    int *num_matches = new int;
    *num_matches = numMatch(dict, enc, dictlens, enclens, ciphchars, num);

    if(numMatch(dict, enc, dictlens, enclens, ciphchars, num) != enc.size())
    {
      char ciphchars_run[26];

      for(int i = 0; i < 26; i++)
      {
        ciphchars_run[i] = ciphchars[i];
      }

      ok(dict, enc, dictlens, enclens, ciphchars, ciphchars_run, num, num_matches, 0);
    }

    if(numMatch(dict, enc, dictlens, enclens, ciphchars, num)!=enc.size())
    {
      for(int j = 0; j < 26; j++)
      {
        ciphchars[j] = '*';
      }
    }

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
  }

   /*

    string enc;
    cin.ignore();

    vector<int> enclens;
    char inp[17];

    x = 0;
    while(enc[x] != '\0')
    {
        y = 0;
        while(enc[x] != ' ')
        {
            inp[y] = enc[x];
            x++;
            y++;
        }
        inp[y] = '\0';
        string str(inp);
        encs.push_back(str);
    }

    for(int i = 0; i < encs.size(); i++)
    {
        cout << encs[i] << ' ';
    }
    */
