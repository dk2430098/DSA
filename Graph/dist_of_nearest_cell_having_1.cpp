#include <bits/sdtc++.h>
using namespace std;

class Solution
{ // T.C = o(n*m) S.C = o(n*m)
private:
  void solve(vector<vector<int>> &dist, vector<vector<int>> &grid)
  {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> vist(n, vector<bool>(m, false));

    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] == 1)
        {
          vist[i][j] = true;
          q.push({{i, j}, 0});
        }
      }
    }

    vector<int> delRow = {0, -1, 0, 1};
    vector<int> delCol = {-1, 0, 1, 0};

    while (!q.empty())
    {
      int row = q.front().first.first;
      int col = q.front().first.second;
      int curr_dist = q.front().second;
      q.pop();

      dist[row][col] = curr_dist;

      for (int i = 0; i < 4; i++)
      {
        int newRow = row + delRow[i];
        int newCol = col + delCol[i];

        if (newRow < n && newRow >= 0 && newCol < m && newCol >= 0 && !vist[newRow][newCol])
        {
          vist[newRow][newCol] = true;
          q.push({{newRow, newCol}, curr_dist + 1});
        }
      }
    }
  }

public:
  // Function to find distance of nearest 1 in the grid for each cell.
  vector<vector<int>> nearest(vector<vector<int>> &grid)
  {
    // Code here
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dist(n, vector<int>(m, 0));

    solve(dist, grid);

    return dist;
  }
};