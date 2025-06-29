#include <bits/sdtc++.h>
using namespace std;

class Solution // T.C = o(n*m)  S.C = o(n*m)
{
private:
  void dfs(vector<vector<int>> &grid, int sr, int sc, int color, vector<vector<bool>> &vis, int oldc)
  {
    vis[sr][sc] = true;
    grid[sr][sc] = color;
    vector<int> delrow = {0, -1, 0, 1};
    vector<int> delcol = {-1, 0, 1, 0};

    for (int i = 0; i < 4; i++)
    {
      int nsr = sr + delrow[i];
      int nsc = sc + delcol[i];

      if (nsr >= 0 && nsr < grid.size() && nsc >= 0 && nsc < grid[0].size() && !vis[nsr][nsc] && grid[nsr][nsc] == oldc)
      {
        vis[nsr][nsc] = true;
        grid[nsr][nsc] = color;
        dfs(grid, nsr, nsc, color, vis, oldc);
      }
    }
  }

public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
  {
    vector<vector<int>> grid = image;
    int n = grid.size(), m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int oldc = grid[sr][sc];

    dfs(grid, sr, sc, color, vis, oldc);

    return grid;
  }
};