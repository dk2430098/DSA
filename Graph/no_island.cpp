#include <bits/sdtc++.h>
using namespace std;

class Solution // T.C = o(n*m)  S.C = o(n*m)
{
private:
  void bfs(int row, int col, vector<vector<char>> &grid, vector<vector<bool>> &vis)
  {
    vis[row][col] = true;
    queue<pair<int, int>> q;
    q.push({row, col});

    vector<int> delRow = {0, -1, 0, 1};
    vector<int> delCol = {-1, 0, 1, 0};
    int n = grid.size();
    int m = grid[0].size();

    while (!q.empty())
    {
      int row = q.front().first;
      int col = q.front().second;
      q.pop();

      for (int i = 0; i < 4; i++)
      {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol])
        {
          vis[nrow][ncol] = true;
          q.push({nrow, ncol});
        }
      }
    }
  }

public:
  int numIslands(vector<vector<char>> &grid)
  {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int cnt = 0;

    for (int row = 0; row < n; row++)
    {
      for (int col = 0; col < m; col++)
      {
        if (!vis[row][col] && grid[row][col] == '1')
        {
          cnt++;
          bfs(row, col, grid, vis);
        }
      }
    }

    return cnt;
  }
};