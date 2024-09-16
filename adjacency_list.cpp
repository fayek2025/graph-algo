#include <bits/stdc++.h>

using namespace std;

class Graph{

    public:
    map <int , list<int>> adjacency_list;

    void add_edge(int u, int v)
    {
        adjacency_list[u].push_back(v);
        adjacency_list[v].push_back(u);
    }

    void print()
    {
        cout << "Adjacency List: " << endl;

        for (auto i : adjacency_list)
        {
            cout << i.first << " : ";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g;

    int n;
    cout << "Enter the number of edges: " << endl;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a;
        int b;
        cin >> a>>b;
        g.add_edge(a , b);
    }

    g.print();
    
}