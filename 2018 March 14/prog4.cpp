#include <iostream>
#include <list>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int vec_find(vector <string> vec, string chek)
{
    for(int i = 0; i != vec.size(); i ++)
    {
        if(vec[i] == chek)
        {
            return i;
        }
    }
    return -1;
}

class AdjListNode
{
    int v;
    string name;
public:
    AdjListNode(int _v, const char* _n) { v=_v; name=_n;}
    int getV() {return v;}
    string getName() { return name;}
};

class Graph
{
    int V;
    list<AdjListNode> *adj;
public:
    Graph(int V);
    void addEdge(int u, int v, const char *n1, const char *n2);
    void getRank(int v, int f, int *rank);
    void getRankUtil(int v, int f, bool visited[], int *rank, int curr_rank);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<AdjListNode>[V];
}

void Graph::addEdge(int u, int v, const char* n1, const char* n2)
{
    if(u!=v)
    {
        int present = 0;
        list<AdjListNode>::iterator i;
        for(i = adj[u].begin(); i != adj[u].end(); i++)
        {
            if(i->getV() == v)
            {
                present = 1;
            }
        }

        if(!present)
        {
            AdjListNode node1(u, n1);
            adj[v].push_back(node1);
            AdjListNode node2(v, n2);
            adj[u].push_back(node2);
        }
    }
}

void Graph::getRank(int v, int f, int *rank)
{
    bool visited[V];
    list<AdjListNode>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); i++)
    {
        for(int j = 0; j < V; j++)
        {
            visited[j] = false;
        }
        getRankUtil(i->getV(), f, visited, rank, 1);
    }
}

void Graph::getRankUtil(int v, int f, bool visited[], int *rank, int curr_rank)
{
    visited[v] = true;

    bool tracker[V];
    for(int j = 0; j < V; j++)
    {
        tracker[j] = visited[j];
    }


    if(v==f)
    {
        if(*rank==-1||curr_rank<*rank)
        {
            *rank = curr_rank;
        }
    }

    list<AdjListNode>::iterator i;
    for(i = adj[v].begin(); i!= adj[v].end(); i++)
    {
        if((visited[i->getV()] == false)&&(i->getV()!=0))
        {
            getRankUtil(i->getV(), f, visited, rank, curr_rank+1);
            for(int j = 0; j < V; j++)
            {
                visited[j] = tracker[j];
            }
        }
    }
}

main()
{
    int cases;
    cin >> cases;

    while(cases--)
    {
        int num_books;
        cin >> num_books;
        int num_authors;
        cin >> num_authors;

        Graph g(num_authors*num_books);
        g.addEdge(0,1,"k","Neil, Gogte");

        vector <string> tokens;
        vector <string> curr_tokens;
        vector <string> old_tokens;
        vector <string> new_tokens;
        tokens.push_back("Neil, Gogte");

        int num, i;
        char line[100];

        cin.ignore();

        while(num_books--)
        {
            curr_tokens.clear();
            new_tokens.clear();
            old_tokens.clear();

            cin.getline(line, sizeof(line));

            string chek = "";

            i = 0;

            num = num_authors;
            num++;
            while(--num)
            {
                chek = "";
                while(!((line[i]>64&&line[i]<91)||(line[i]>96&&line[i]<123)))
                {
                    if(line[i]==':')
                    {
                        goto OK;
                    }
                    i++;
                }

                while(!(line[i]=='.'&&(line[i+1]==','||line[i+1]==':')))
                {
                    chek.push_back(line[i]);
                    i++;
                }

                curr_tokens.push_back(chek);
                tokens.push_back(chek);

                if(vec_find(tokens, chek)==-1)
                {
                    new_tokens.push_back(chek);
                }
                else
                {
                    old_tokens.push_back(chek);
                }
            }
            OK:;

            int linked = 1;

            if(old_tokens.size() == 0)
            {
                linked = 0;
                for(int i = 0; i < curr_tokens.size(); i++)
                {
                    g.addEdge(0, vec_find(tokens, curr_tokens[i])+1, "k", curr_tokens[i].c_str());
                }
            }

            if(linked)
            {
                for(int x = 0; x < curr_tokens.size(); x++)
                {
                    for(int y = 0; y < curr_tokens.size(); y++)
                    {
                        g.addEdge(vec_find(tokens, curr_tokens[y])+1, vec_find(tokens, curr_tokens[x])+1, curr_tokens[y].c_str(), curr_tokens[x].c_str());
                    }
                }
            }
        }

        int rank;

        int x, y;
        char check[100];

        while(num_authors--)
        {
            cin.getline(check, sizeof(check));
            rank = -1;
            y = 0;
            while(check[y]!='\0'){ y++;}

            if(check[y-1]=='.')
            {
              check[y-1] = '\0';

              g.getRank(1, vec_find(tokens,check)+1, &rank);

              x = vec_find(tokens, check);
              check[y-1] = '.';
              cout << check << " ";
            }
            else
            {
              cout << check << " ";
            }

            if(rank==-1||x==-1)
            {
                cout << "infinity" << '\n';
            }
            else if(strcmp(check, "Neil, Gogte.") == 0)
            {
                cout << '0' << '\n';
            }
            else
            {
                cout << rank << '\n';
            }
        }
    }
}
