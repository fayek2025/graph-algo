#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (dfs(board, visited, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, string word, int i, int j, int k) {
        // First, check if indices are out of bounds
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
            return false;
        }
        
        // Check if the current character matches the word[k] and if the cell is already visited
        if (board[i][j] != word[k] || visited[i][j]) {
            return false;
        }

        // If we've matched all characters in the word, return true
        if (k == word.size() - 1) {
            return true;
        }

        // Mark the current cell as visited
        visited[i][j] = true;

        // Explore in all four directions
        bool found = dfs(board, visited, word, i + 1, j, k + 1) ||
                     dfs(board, visited, word, i - 1, j, k + 1) ||
                     dfs(board, visited, word, i, j + 1, k + 1) ||
                     dfs(board, visited, word, i, j - 1, k + 1);

        // Backtrack: Unmark the current cell
        visited[i][j] = false;

        return found;
    }
};
