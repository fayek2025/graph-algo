#include <bits/stdc++.h>

using namespace std;

class Graph{

    public:
    map<int , list<int>> adjacency_list;

    

    void add_edge(int u, int v)
    {
        adjacency_list[u].push_back(v);
        
    }

    void print (){
        
        for (auto i : adjacency_list)
        {
            cout << i.first << ": ";

            for(auto j : i.second )
            {
                cout << j << " ";
            }
                cout << endl;

        }
    }

    
       
} ;

void DFSres (map<int , list<int>> &adj , vector<bool> &visited , int s) // we have to send actual vector's address not a copy

{
    visited[s] = true;

    cout << s << " ";

    for (int i : adj[s])
    {
        if(visited[i] == false)
        {
            DFSres(adj, visited ,  i);
        }
    }
    
    
}

void DFS (map<int , list<int>> &adj , int s)
{
    vector<bool> visited(adj.size() , false);

    DFSres(adj , visited , s);

}


int main()
{
    Graph g;

    g.add_edge(1, 2);
    g.add_edge(1, 5);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(2 , 4);

    g.print();
    
    int s = 1;

    DFS(g.adjacency_list , s);
    
}