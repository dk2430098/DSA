#include <bits/sdtc++.h>
using namespace std;

class Solution
{ // T.C = o(n*m) S.C = o(n*m)
private:
  void DFS(int row, int col, vector<vector<int>> &grid, vector<vector<bool>> &vist)
  {
    int n = grid.size();
    int m = grid[0].size();
    vist[row][col] = true;
    vector<int> delRow = {0, -1, 0, 1};
    vector<int> delCol = {-1, 0, 1, 0};

    for (int i = 0; i < 4; i++)
    {
      int nrow = row + delRow[i];
      int ncol = col + delCol[i];

      if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vist[nrow][ncol] && grid[nrow][ncol] == 1)
      {
        DFS(nrow, ncol, grid, vist);
      }
    }
  }

public:
  int numEnclaves(vector<vector<int>> &grid)
  {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> vist(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
      // first col
      if (!vist[i][0] && grid[i][0] == 1)
        DFS(i, 0, grid, vist);

      // last col
      if (!vist[i][m - 1] && grid[i][m - 1] == 1)
        DFS(i, m - 1, grid, vist);
    }

    for (int j = 0; j < m; j++)
    {
      // first row
      if (!vist[0][j] && grid[0][j] == 1)
        DFS(0, j, grid, vist);

      // last row
      if (!vist[n - 1][j] && grid[n - 1][j] == 1)
        DFS(n - 1, j, grid, vist);
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (!vist[i][j] && grid[i][j] == 1)
          count++;
      }
    }

    return count;
  }
};