#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // adjacency list
        vector<vector<int>> adj(numCourses);
        vector<bool> visited(numCourses, false);
        vector<bool> recStack(numCourses, false);  // To detect cycles in the DFS path

        // Building the adjacency list from prerequisites
        for (auto pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }

        // Perform DFS on each node
        for (int i = 0; i < numCourses; i++) {
            if (dfs(adj, visited, recStack, i)) {
                return false;  // Cycle detected, not possible to finish all courses
            }
        }
        
        return true;  // No cycle detected, all courses can be finished
    }

    // DFS function to detect a cycle
    bool dfs(vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack, int s) {
        if (recStack[s]) {
            // A cycle is detected
            return true;
        }
        
        if (visited[s]) {
            // Already fully processed this node, no need to visit again
            return false;
        }

        // Mark the current node as visited and add it to the recursion stack
        visited[s] = true;
        recStack[s] = true;

        // Visit all the neighbors of the current node
        for (int neighbor : adj[s]) {
            if (dfs(adj, visited, recStack, neighbor)) {
                return true;
            }
        }

        // Remove the current node from the recursion stack (backtrack)
        recStack[s] = false;
        return false;
    }
};
