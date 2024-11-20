#include <bits/stdc++.h>
#include <iostream>

using namespace std;
bool visited[1002];
vector<int> adj[1002];
int count_connected_vertices = 0;
int total_connected_vertices = 0;
int max_connected_vertices = 0;
int total_pairs = 0;

void dfs(int special)
{
    count_connected_vertices++;
    visited[special] = true;

    for (int i = 0; i < adj[special].size(); i++)
    {
        if(!visited[adj[special][i]])
        {
            dfs(adj[special][i]);
        }
    }
    
}

int main()
{
    int n , m , k;
    
    cin >> n >> m >> k;
    int special[k];
    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        special[i] = a;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < k; i++)
    {
        count_connected_vertices = 0;
        dfs(special[i]);
        total_connected_vertices += count_connected_vertices;
        max_connected_vertices = max(max_connected_vertices , count_connected_vertices);
        total_pairs += (count_connected_vertices*(count_connected_vertices-1))/2;


    }
    
    int rest = n - total_connected_vertices + max_connected_vertices;
    int final = (rest*(rest-1))/2 - (max_connected_vertices*(max_connected_vertices-1))/2;
    total_pairs += final;
    total_pairs -= m;
    cout << total_pairs <<endl; 
    


}