#include <bits/sdtc++.h>
using namespace std;

class Solution // T.C = o(n*m*log(n*m) + n*m*4)  S.C = o(n*m)
{
private:
  void dfs(int row, int col, vector<vector<bool>> &vist, vector<vector<int>> &grid, vector<pair<int, int>> &ans, int brow, int bcol)
  {
    int n = grid.size();
    int m = grid[0].size();
    vector<int> delRow = {0, -1, 0, 1};
    vector<int> delCol = {-1, 0, 1, 0};

    ans.push_back({row - brow, col - bcol});
    vist[row][col] = true;

    for (int i = 0; i < 4; i++)
    {
      int nrow = row + delRow[i];
      int ncol = col + delCol[i];

      if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !vist[nrow][ncol] && grid[nrow][ncol] == 1)
      {
        dfs(nrow, ncol, vist, grid, ans, brow, bcol);
      }
    }
  }

public:
  int countDistinctIslands(vector<vector<int>> &grid)
  {
    // code here
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> vist(n, vector<bool>(m, false));
    set<vector<pair<int, int>>> islands;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (!vist[i][j] && grid[i][j] == 1)
        {
          vector<pair<int, int>> ans;
          dfs(i, j, vist, grid, ans, i, j);
          islands.insert(ans);
        }
      }
    }

    return islands.size();
  }
};
