#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
private:
  bool detect(int src, vector<vector<int>> &list, vector<bool> &vis)
  {

    vis[src] = true;
    queue<pair<int, int>> q;
    q.push({src, -1});

    while (!q.empty())
    {
      int node = q.front().first;
      int parent = q.front().second;
      q.pop();

      for (auto ngh : list[node])
      {
        if (vis[ngh] && ngh != parent)
          return true;
        if (!vis[ngh])
        {
          vis[ngh] = true;
          q.push({ngh, node});
        }
      }
    }
    return false;
  }

public:
  bool isCycle(int V, vector<vector<int>> &edges)
  {
    // Code here
    vector<vector<int>> list(V);

    for (int i = 0; i < edges.size(); i++)
    {
      int u = edges[i][0];
      int v = edges[i][1];
      list[u].push_back(v);
      list[v].push_back(u);
    }

    vector<bool> vis(V, false);

    for (int i = 0; i < V; i++)
    {
      if (!vis[i])
        if (detect(i, list, vis))
          return true;
    }

    return false;
  }
};