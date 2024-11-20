#include <iostream>
#include<bits/stdc++.h>

using namespace std;
#define V 9

int min_distance(int dist[], bool sptset[])
{

    int min = INT_MAX;
    int min_index;
    for (int i = 0; i < V; i++)
    {
        if(!sptset[i] && dist[i] < min)
        {
            min = dist[i];
            min_index = i;
        }
    }
    
return min_index;




}

void printSolution(int dist[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}


void dikstra (int graph[V][V] , int src)
{
    int dist[V];
    bool spt[V];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        spt[i] = false;
    }

    dist[src] = 0;

    for (int i = 0; i < V; i++)
    {
        int u  = min_distance(dist , spt);
        spt[u] = true;


        for(int j = 0 ; j < V ; j++)
        {
            if(!spt[j] && graph[u][j]
            && dist[u] != INT_MAX &&
            dist[u] + graph[u][j] < dist[j]
            )
            {
                dist[j] =  dist[u] + graph[u][j];
            }
        }
    }

    printSolution(dist);
    
    
}

int main()
{

    /* Let us create the example graph discussed above */
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    // Function call
    dikstra(graph, 0);

    return 0;
}
