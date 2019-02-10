import java.util.Scanner;

class Wolf
{
  static double calcProbs(char map[][], int visited[][], int sec_paths[][], int curr_1, int curr_2, int r, int c, int s)
  {
    double tot = 0;
    int paths = 0;

    int chek_x[] = {1, -1, 0, 0};
    int chek_y[] = {0, 0, 1, -1};

    int x, y;

    for(int i = 0; i < 4; i++)
    {
      x = curr_1+chek_x[i];
      y = curr_2+chek_y[i];

      if(x>=0 && x<r && y>=0 && y<c)
      {
        if(visited[x][y] == 1) { continue;}

        paths += 1;
        visited[x][y] = 1;
        for(int j = 0; j < s; j++)
        {
          if(x==sec_paths[j][0] && y==sec_paths[j][1])
          {
            tot += calcProbs(map, visited, sec_paths, sec_paths[j][0], sec_paths[j][1], r, c, s);
          }
          else if(x==sec_paths[j][2] && y==sec_paths[j][3])
          {
            tot += calcProbs(map, visited, sec_paths, sec_paths[j][2], sec_paths[j][3], r, c, s);
          }
        }

        if(map[x][y]=='F') { tot += 1;}
      }
    }

    return (tot/paths);
  }

  public static void main(String[] args)
  {
    Scanner sc = new Scanner(System.in);
    int r = sc.nextInt();
    int c = sc.nextInt();
    int s = sc.nextInt();

    char map[][] = new char[r][c];
    int visited[][] = new int[r][c];
    for(int i = 0; i < r; i++)
    {
      for(int j = 0; j < c; j++)
      {
        visited[i][j] = 0;
      }
    }

    String inp;
    int curr_1=0, curr_2=0;
    for(int i = 0; i < r; i++)
    {
      inp = sc.next();
      for(int j = 0; j < r; j++)
      {
        map[i][j] = inp.charAt(j);
        if(map[i][j] == 'P') { curr_1 = i; curr_2 = j;}
      }
    }

    int sec_paths[][] = new int[s][4];
    for(int i = 0; i < s; i++)
    {
      for(int j = 0; j < 4; j++)
      {
        sec_paths[i][j] = sc.nextInt();
      }
    }

    System.out.println(calcProbs(map, visited, sec_paths, curr_1, curr_2, r, c, s));
  }
}
