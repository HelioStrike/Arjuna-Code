#include <iostream>
#include <list>
#include <string.h>
#include <stdio.h>
using namespace std;

main()
{
  int cases;
  cin >> cases;
  int board_height, board_width, num;
  list<string> names;
  string inp;
  char c;

  int step_x[8] = {1, 1, -1, -1, 1, -1, 0, 0};
  int step_y[8] = {1, -1, 1, -1, 0, 0, 1, -1};

  while(cases--)
  {
    names.clear();
    cin >> board_height;
    cin >> board_width;

    char board[board_height][board_width];

    getchar();
    for(int i = 0; i < board_height; i++)
    {
      for(int j = 0; j < board_width; j++)
      {
        c = getchar();
        if(c < 97)
        {
          board[i][j] = c + 32;
        }
        else
        {
          board[i][j] = c;
        }
      }
      getchar();
    }

    cin >> num;

    int curr_x, curr_y, run;

    for(int i = 0; i < num; i++)
    {
      cin >> inp;
      for(int i = 0; i < board_height; i++)
      {
        for(int j = 0; j < board_width; j++)
        {
          if(board[i][j]==inp[0])
          {
            for(int k = 0; k < 8; k++)
            {
              for(curr_x = i, curr_y = j, run = 0; (curr_x>=0&&curr_x<board_height&&curr_y>=0&&curr_y<board_width)&&(board[curr_x][curr_y]==inp[run]); curr_x+=step_x[k], curr_y+=step_y[k], run++)
              {
                if(inp[run]==inp[strlen(inp.c_str())-1])
                {
                  cout << i+1 << ' ' << j+1 << '\n';
                }
              }
            }
          }
        }
      }
    }


  }


}
