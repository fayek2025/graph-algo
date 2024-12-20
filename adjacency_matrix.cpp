#include <bits/stdc++.h>

using namespace std;

class Graph{

    public:
    vector<vector<int>> adjacency_matrix;

    Graph(int n)
    {
        adjacency_matrix
            = vector<vector<int> >(n, vector<int>(n, 0));
    }

    void add_edge(int u, int v)
    {
        adjacency_matrix[u][v] =1;
        adjacency_matrix[v][u] =1;
    }

    void print (){
        for(int i=0; i <adjacency_matrix.size(); i++)
        {
            cout << i << " : ";
            for(int j=0; j<adjacency_matrix[i].size(); j++)
            {
                if(adjacency_matrix[i][j] == 1)
                {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }
       
} ;


int main()
{
    Graph g(5);
    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(1,3);
    g.add_edge(2,4);
    g.add_edge(3,4);
    g.print();
}