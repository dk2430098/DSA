#include <bits/sdtc++.h>
using namespace std;

class Solution // T.C = o(n*m)  S.C = o(n*m)
{
private:
  int bfs(vector<vector<int>> &grid, vector<vector<bool>> &vis)
  {
    int time = 0;
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<pair<int, int>, int>> q;

    for (int row = 0; row < n; row++)
    {
      for (int col = 0; col < m; col++)
      {
        if (grid[row][col] == 2)
        {
          q.push({{row, col}, 0});
          vis[row][col] = true;
        }
      }
    }

    vector<int> delRow = {0, -1, 0, 1};
    vector<int> delCol = {-1, 0, 1, 0};

    while (!q.empty())
    {
      int row = q.front().first.first;
      int col = q.front().first.second;
      time = q.front().second;
      q.pop();

      for (int i = 0; i < 4; i++)
      {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
        {
          vis[nrow][ncol] = true;
          grid[nrow][ncol] = 2;
          q.push({{nrow, ncol}, (time + 1)});
        }
      }
    }

    return time;
  }

public:
  int orangesRotting(vector<vector<int>> &grid)
  {
    vector<vector<int>> save = grid;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    int min_time = bfs(grid, vis);

    for (int row = 0; row < n; row++)
    {
      for (int col = 0; col < m; col++)
      {
        if (grid[row][col] == 1)
        {
          return -1;
        }
      }
    }

    return min_time;
  }
};