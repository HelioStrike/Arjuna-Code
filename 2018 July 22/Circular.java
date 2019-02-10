import java.util.Scanner;

class Node
{
  char data;
  int pos;
  Node next;
  Node prev;

  Node(char data, Node next, Node prev, int pos)
  {
    this.data = data;
    this.next = next;
    this.prev = prev;
    this.pos = pos;
  }
}

class Circular
{
  public static void main(String[] args)
  {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    String inp = sc.next();

    //Creating entry node
    Node entry = new Node(inp.charAt(0), null, null, 0);

    //Creating circular double linked list
    Node prev = entry;
    for(int i = 1; i < n; i++)
    {
      Node next = new Node(inp.charAt(i), null, prev, i);
      prev.next = next;
      prev = next;
    }

    entry.prev = prev;
    prev.next = entry;

    int max[] = new int[n];

    for(int i = 0; i < n; i++) { max[i] = 1;}

    Node curr_next = entry;
    Node curr_prev = entry.prev;
    Node curr_next_next;
    Node curr_prev_prev;

    for(int i = 0; i < n; i++)
    {
      curr_next_next = curr_next;
      curr_prev_prev = curr_prev;

      if(curr_next_next.data == curr_prev_prev.data)
      {
        for(int j = 1; j <= n/2; j++)
        {
          if(curr_next_next.data != curr_prev_prev.data)
          {
             break;
          }


          if(curr_next_next.pos < curr_prev_prev.pos)
          {
            if(i >= n/2)
            {
              for(int k = curr_next.pos+1; k <= curr_prev.pos; k++)
              {
                if((j*2) > max[k])
                {
                   max[k] = j*2;
                }
              }
            }
            else
            {
              for(int k = i+j; k <= n-j+i; k++)
              {
                if((j*2) > max[k])
                {
                   max[k] = j*2;
                }
              }
            }
          }
          else
          {
            for(int k = 0; k <= curr_prev_prev.pos; k++)
            {
              if(j*2 > max[k])
              {
                max[k] = j*2;
              }
            }

            for(int k = curr_next_next.pos+1; k < n; k++)
            {
              if(j*2 > max[k])
              {
                max[k] = j*2;
              }
            }
          }

          curr_next_next = curr_next_next.next;
          curr_prev_prev = curr_prev_prev.prev;
        }
      }

      curr_prev = curr_next;
      curr_next = curr_next.next;
    }

    Node curr = entry;
    for(int i = 0; i < n; i++)
    {
      curr_next = curr.next;
      curr_prev = curr.prev;
      for(int j = 1; j <= n/2; j++)
      {
        if(curr_next.data != curr_prev.data)
        {
           break;
        }

        if(curr_next.pos < curr_prev.pos)
        {
          if(i > n/2)
          {
            for(int k = curr_next.pos+1; k <= curr_prev.pos; k++)
            {
              if((j*2+1) > max[k])
              {
                 max[k] = j*2+1;
              }
            }
          }
          else
          {
            for(int k = i+j+1; k < n-j+i; k++)
            {
              if((j*2+1) > max[k])
              {
                 max[k] = j*2+1;
              }
            }
          }
        }
        else
        {
          for(int k = 0; k <= curr_prev.pos; k++)
          {
            if((j*2+1) > max[k])
            {
               max[k] = j*2+1;
            }
          }

          for(int k = curr_next.pos+1; k < n; k++)
          {
            if((j*2+1) > max[k])
            {
               max[k] = j*2+1;
            }
          }
        }

        curr_next = curr_next.next;
        curr_prev = curr_prev.prev;
      }
      curr = curr.next;
    }

    for(int i = 0; i < n; i++)
    {
      System.out.println(max[i]);
    }
  }
}

//abccaba

//baabcca
