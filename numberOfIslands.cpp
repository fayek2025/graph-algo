#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> visited(row , vector<bool>(col , false));

        int island = 0;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0 ; j < col; j++)
            {
                if(grid[i][j] == '1')
                {
                    dfs(grid , visited , i , j);
                    island++;
                }
            }
            
        }
        
        
    }

    void dfs(vector<vector<char>> &grid , vector<vector<bool>> &visited , int i , int j)
    {
        if(i >= 0 && i <grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == '1' && !visited[i][j])
        {
            visited[i][j] = true;
            dfs(grid , visited , i+1 , j);
            dfs(grid , visited , i , j+1);
            dfs(grid , visited , i-1 , j);
            dfs(grid , visited , i , j-1);

        }
    }
};
