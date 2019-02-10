#include <iostream>
#include <stdio.h>
using namespace std;

main()
{
  char board[8][8];
  string line;
  int white_x;
  int white_y;
  int black_x;
  int black_y;

  for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 8; j++)
    {
      board[i][j] = getchar();
      if(board[i][j]=='K')
      {
        white_x = i;
        white_y = j;
      }

      if(board[i][j]=='k')
      {
        black_x = i;
        black_y = j;
      }
    }
    getchar();
  }

  int step_x[8] = {1, 1, -1, -1, 1, -1, 0, 0};
  int step_y[8] = {1, -1, 1, -1, 0, 0, 1, -1};

  int knight_x[8] = {2, 2, -2, -2, 1, 1, -1, -1};
  int knight_y[8] = {1, -1, 1, -1, 2, -2, 2, -2};

  int curr_x;
  int curr_y;

  int whiteUnsafe = 0;

  for(int i = 0; i < 4; i++)
  {
    for(curr_x = white_x, curr_y = white_y; (curr_x>=0&&curr_x<8&&curr_y>=0&&curr_y<8); curr_x+=step_x[i], curr_y+=step_y[i])
    {
      if(board[curr_x][curr_y]=='P')
      {
        break;
      }

      if(board[curr_x][curr_y]=='b'||board[curr_x][curr_y]=='q')
      {
        whiteUnsafe = 1;
        break;
      }
    }
    if(whiteUnsafe)
    {
      break;
    }
  }

  if(!whiteUnsafe)
  {
    for(int i = 4; i < 8; i++)
    {
      for(curr_x = white_x, curr_y = white_y; (curr_x>=0&&curr_x<8&&curr_y>=0&&curr_y<8); curr_x+=step_x[i], curr_y+=step_y[i])
      {
        if(board[curr_x][curr_y]=='P')
        {
          break;
        }

        if(board[curr_x][curr_y]=='r'||board[curr_x][curr_y]=='q')
        {
          whiteUnsafe = 1;
          break;
        }
      }
      if(whiteUnsafe)
      {
        break;
      }
    }
  }

  if(!whiteUnsafe)
  {
    for(int i = 0; i < 8; i++)
    {
      curr_x = white_x + knight_x[i];
      curr_y = white_y + knight_y[i];

      if(curr_x>=0&&curr_x<8&&curr_y>=0&&curr_y<8)
      {
        if(board[curr_x][curr_y]=='n')
        {
          whiteUnsafe = 1;
        }
      }
    }
  }

  int blackUnsafe = 0;

  for(int i = 0; i < 4; i++)
  {
    for(curr_x = black_x, curr_y = black_y; (curr_x>=0&&curr_x<8&&curr_y>=0&&curr_y<8); curr_x+=step_x[i], curr_y+=step_y[i])
    {
      if(board[curr_x][curr_y]=='p')
      {
        break;
      }

      if(board[curr_x][curr_y]=='B'||board[curr_x][curr_y]=='Q')
      {
        blackUnsafe = 1;
        break;
      }
    }
    if(blackUnsafe)
    {
      break;
    }
  }

  if(!blackUnsafe)
  {
    for(int i = 4; i < 8; i++)
    {
      for(curr_x = black_x, curr_y = black_y; (curr_x>=0&&curr_x<8&&curr_y>=0&&curr_y<8); curr_x+=step_x[i], curr_y+=step_y[i])
      {
        if(board[curr_x][curr_y]=='p')
        {
          break;
        }

        if(board[curr_x][curr_y]=='R'||board[curr_x][curr_y]=='Q')
        {
          blackUnsafe = 1;
          break;
        }
      }
      if(blackUnsafe)
      {
        break;
      }
    }
  }

  if(!blackUnsafe)
  {
    for(int i = 0; i < 8; i++)
    {
      curr_x = black_x + knight_x[i];
      curr_y = black_y + knight_y[i];

      if(curr_x>=0&&curr_x<8&&curr_y>=0&&curr_y<8)
      {
        if(board[curr_x][curr_y]=='N')
        {
          blackUnsafe = 1;
        }
      }
    }
  }

  if(!blackUnsafe&&!whiteUnsafe)
  {
    cout << "all is well." << '\n';
  }
  else if(blackUnsafe)
  {
    cout << "black king is under threat" << '\n';
  }
  else
  {
    cout << "white king is under threat" << '\n';
  }
}
