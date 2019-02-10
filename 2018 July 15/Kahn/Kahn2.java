import java.util.*;

class Graph
{
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

    public void topologicalSortUtil(int indegree[], int curr, ArrayList<Integer> ans)
    {
      int indegree_copy[] = indegree.clone();

      ArrayList<Integer> imp = new ArrayList<>();
      int j = 0;
      for(int i  = 0; i < adj[curr].size(); i++) {
        j = 0;
        if(--indegree_copy[adj[curr].get(i)] == 0) {
          j++;
          imp.add(adj[curr].get(i));
          topologicalSortUtil(indegree_copy, adj[curr].get(i), ans);
        }
      }
        if(j > 1) {
          System.out.println(1);
          for(int k = 0; k < V; k++) {
            if(indegree_copy[k] == 0) {
              ans.add(k);
            }
          }
        }

        indegree_copy = indegree.clone();
      }

      /*if(j > 1) {
        for(int node: imp) {
          if(!ans.contains(node)) {
            ans.add(node);
          }
        }*/
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

        ArrayList<Integer> ans = new ArrayList<Integer>();
        Queue<Integer> q = new LinkedList<Integer>();
        for(int i = 0;i < V; i++)
        {
            topologicalSortUtil(indegree, i, ans);
        }

        return ans;
    }
}

class Kahn2
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        StringTokenizer st = new StringTokenizer(sc.nextLine(), ",");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        if(n > 26 || n < 1) {
            System.out.println("Invalid Input N "+ n);
            System.exit(0);
        } else if(m > 10 || m < 1) {
            System.out.println("Invalid Input K "+ m);
            System.exit(0);
        }

        Graph g=new Graph(n);

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

        ArrayList<Integer> ans = g.topologicalSort();
        Collections.sort(ans);

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
