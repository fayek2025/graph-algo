#include <bits/stdc++.h>

using namespace std;


void bfs(vector<vector<int>> &adj , vector<bool> &visited, int s)
{
    queue<int> q;

    visited[s] = true;
    q.push(s);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        cout << curr << " ";
        for(int neighbours : adj[curr])
        {
            if(!visited[neighbours])
            {
                visited[neighbours] = true;
                q.push(neighbours);
            }
        }

    }

    cout << endl;
    

}

void addEdge(vector<vector<int>> &adj , int s , int d)
{
    adj[s].push_back(d);
    adj[d].push_back(s);
}

int main()
{
    int v = 5;
    vector<vector<int>> adj(v);
    vector<bool> visited(adj.size() , false);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);

    cout << "BFS Starting from 0" << endl;
    bfs(adj , visited, 0)
}