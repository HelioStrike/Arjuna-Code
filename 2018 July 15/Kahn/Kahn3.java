import java.util.*;

class Graph
{
    //Standard graph stuff
    int V;

    List <Integer> adj[];
    public Graph(int V)
    {
        this.V = V;
        adj = new ArrayList[V];
        for(int i = 0; i < V; i++)
            adj[i]=new ArrayList<Integer>();
    }

    public void addEdge(int u,int v)
    {
        adj[u].add(v);
    }

    public ArrayList<Integer> topologicalSort()
    {
        int indegree[] = new int[V];

        for(int i = 0; i < V; i++)
        {
            ArrayList<Integer> temp = (ArrayList<Integer>) adj[i];
            for(int node : temp)
            {
                indegree[node]++;
            }
        }

        //Will hold our output array
        ArrayList<Integer> ans = new ArrayList<Integer>();
        LinkedList<Integer> l = new LinkedList<Integer>();
        LinkedList<Integer> l2;
        for(int i = 0;i < V; i++)
        {
            if(indegree[i]==0) { l.addLast(i);}
        }

        int u;
        int sz;
        int indegree_copy[] = new int[V];

        while(!l.isEmpty())
        {
            l2 = new LinkedList<Integer>(l);
            sz = l.size();
            indegree_copy = indegree.clone();

            for(int i  = 0; i < sz; i++)
            {
              u=l.removeFirst();

              for(int node : adj[u])
              {
                  if(--indegree[node] == 0) {
                      l.addLast(node);
                  }

                  if(l.size() > 1) {
                    for(int j = 0; j < l.size(); j++) {
                      System.out.print(l.get(j) + " ");
                    }
                    System.out.println();

                    for(int elem: l) {
                       if(!ans.contains(elem)) { ans.add(elem);}
                    }
                  }
              }

            }

            for(int i  = 0; i < sz; i++)
            {
              u=l2.removeLast();

              for(int v = adj[u].size() - 1; v >= 0; v--)
              {
                  int node = adj[u].get(v);
                  if(--indegree_copy[node] == 0) {
                      l2.addLast(node);
                  }

                  if(l2.size() > 1) {
                    for(int j = 0; j < l2.size(); j++) {
                      System.out.print(l2.get(j) + " ");
                    }
                    System.out.println();

                    for(int elem: l2) {
                       if(!ans.contains(elem)) { ans.add(elem);}
                    }
                  }
              }

            }


              //If size of queue is greater than 1, toss them into the output array
            if(l.size() > 1) {
              for(int i = 0; i < l.size(); i++) {
                System.out.print(l.get(i) + " ");
              }
              System.out.println();

              for(int elem: l) {
                 if(!ans.contains(elem)) { ans.add(elem);}
              }
            }
        }

        return ans;
    }
}

class Kahn
{
    public static void main(String args[])
    {
        //taking input
        Scanner sc = new Scanner(System.in);
        StringTokenizer st = new StringTokenizer(sc.nextLine(), ",");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        //Invalid cases
        if(n > 26 || n < 1) {
            System.out.println("Invalid Input N "+ n);
            System.exit(0);
        } else if(m > 10 || m < 1) {
            System.out.println("Invalid Input K "+ m);
            System.exit(0);
        }

        //Create new graph
        Graph g=new Graph(n);


        //Creating graph using inputs
        int a, b;
        String mid;
        char z;
        for(int i = 0; i < m; i++) {
          st = new StringTokenizer(sc.nextLine(), ",");
          z = st.nextToken().charAt(0);
          b = Integer.parseInt(Character.toString((char)(z - 17)));
          while(true)
          {
            a = b;
            if(!st.hasMoreTokens()) { break;}
            z = st.nextToken().charAt(0);
            b = Integer.parseInt(Character.toString((char)(z - 17)));
            g.addEdge(a, b);
          }
        }

        //Getting output array
        ArrayList<Integer> ans = g.topologicalSort();
        Collections.sort(ans);

        //Printing output array
        if(ans.size() > 0){
            for(int i = 0; i < ans.size(); i++) {
              System.out.print((char)(Integer.toString(ans.get(i)).charAt(0)+17));
              if(i != ans.size() -1) {
                System.out.print(",");
              }
            }
        } else {
            System.out.println("NA");
        }

    }
}
