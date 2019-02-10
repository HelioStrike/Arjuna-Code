import java.util.Scanner;

class Circular2
{
  public static void main(String[] args)
  {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    String inp = sc.next();
    String substr;

    int max[] = new int[n];
    for(int i = 0; i < n; i++) { max[i] = 1;}

    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j <= n; j++)
      {
        for(int k = j+1; k <= n; k++)
        {
          substr = inp.substring(j, k);
          if(substr.equals(new StringBuilder(substr).reverse().toString()))
          {
            if(substr.length() > max[i]) { max[i] = substr.length();}
          }
        }
      }
      inp = inp.substring(1, n) + inp.charAt(0);
      //System.out.println(inp);
    }

    for(int i = 0; i < n; i++) { System.out.println(max[i]);}
  }
}
