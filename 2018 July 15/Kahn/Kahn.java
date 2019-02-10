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
            if(indegree[i]==0)
                q.add(i);
        }

        int cnt = 0;

        while(!q.isEmpty())
        {
            int u=q.poll();

            for(int node : adj[u])
            {
                if(--indegree[node] == 0 && adj[node].size() != 0)
                    q.add(node);
            }

            if(q.size() > 1) {
              for(int elem: q) {
                ans.add(elem);
              }
            }
            cnt++;
        }

        return ans;
    }
}

class Kahn
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        StringTokenizer st = new StringTokenizer(sc.nextLine(), ",");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

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
        for(int i = 0; i < ans.size(); i++) {
          System.out.println((char)(Integer.toString(ans.get(i)).charAt(0)+17));
        }

    }
}
