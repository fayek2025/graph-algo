#include <bits/stdc++.h>
using namespace std;
 
int bfs(vector<vector<int>> &adj, vector<bool> &visited, int city, int fuel)
{
    queue<int> q;
    visited[city] = true;
    q.push(city);
    int count = 0;
 
    while (!q.empty() && fuel > 0)
    {
        int size = q.size(); // Current level size
        for (int i = 0; i < size; i++)
        {
            int curr = q.front();
            q.pop();
 
            for (int nei : adj[curr])
            {
                if (!visited[nei])
                {
                    visited[nei] = true;
                    q.push(nei);
                    
                }
            }
        }
        fuel--; // After processing a level, decrement fuel
    }

    for (auto value : visited)
    {
        if(value == true)
        {
            count++;
        }
    }
    
 
    return count;
}
 
int main()
{
    int N, M, K, C;
    cin >> N >> M >> K >> C;
 
    vector<vector<int>> adj(N+2); // Initialize adjacency list with N (number of cities)
    
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    vector<bool> visited(N+5, false); // Initialize visited array with size N
    
    int result = bfs(adj, visited, C, K); // Pass city C and fuel K to BFS
    
    cout << result << endl;
 
    return 0;
}