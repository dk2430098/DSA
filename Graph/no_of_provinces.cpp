#include <bits/sdtc++.h>
using namespace std;

class Solution // T.C = o(n) + o(v+2E) ~ o(n) S.C = o(n) + o(n)
{
private:
  void dfs(vector<int> &vis, int node, vector<vector<int>> &list)
  {
    vis[node] = 1;

    for (auto ngh : list[node])
    {
      if (!vis[ngh])
      {
        dfs(vis, ngh, list);
      }
    }
  }

public:
  int findCircleNum(vector<vector<int>> &isConnected)
  {
    int v = isConnected.size();
    vector<vector<int>> list(v);

    for (int i = 0; i < v; i++)
    {
      for (int j = 0; j < v; j++)
      {
        if (isConnected[i][j] == 1 && i != j)
        {
          list[i].push_back(j);
          list[j].push_back(i);
        }
      }
    }

    int count = 0;
    vector<int> vis(v, 0);

    for (int i = 0; i < v; i++)
    {
      if (!vis[i])
      {
        dfs(vis, i, list);
        count++;
      }
    }

    return count;
  }
};