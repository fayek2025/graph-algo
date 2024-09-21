#include <bits/stdc++.h>

using namespace std;

int isPossible ( vector<vector<int>> &grid , int row , int col )
{
    if(grid[0][0] == 1 || grid[row-1][col-1] == 1)
    {
        return -1;
    }

    queue<pair<int , int>> q;

    vector<vector<int>> dis(row , vector<int>(col , -1));
    
     int dirx[4] = { -1, 0, 1, 0 };
    int diry[4] = { 0, 1, 0, -1 };

    q.push({0 , 0});
    dis[0][0] = 0;

    while (!q.empty())
    {
        pair<int,int> p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int x = p.first + dirx[i];
            int y = p.second + diry[i];


         if (x >= 0 && x < row && y >= 0 && y < col
                && dis[x][y] == -1) {
                
                if(grid[x][y] == 0 || grid[x][y] == 2)
                {
                    dis[x][y] = dis[p.first][p.second] + 1;

                    q.push({x,y});
                }

                if(grid[x][y] == 2)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        /* code */
                        int xx = x + dirx[j];
                        int yy = y + diry[j];
                        
                        if(xx >= 0 && xx < row && yy >= 0 && yy < col)
                        {
                              if(grid[xx][yy] == 1)
                        {
                            grid[xx][yy] = 0;
                        } 

                        }
                      
                    }
                    
                }

            }
        }
        


       
        
    }


     return dis[row-1][col-1];
    
    
}



int main()
{
 
    int n = 3;
    int m = 4;
    vector<vector<int> > grid = { { 0, 1, 2, 1 },
                                  { 2, 1, 0, 0 },
                                  { 0, 2, 1, 0 } };
 
    int result = isPossible (grid , n , m);
 
    // Function Call
    cout << "Output: " << result << endl;
 
    return 0;
}