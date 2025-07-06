#include <bits/sdtc++.h>
using namespace std;

class Solution // T.C = o(n+2E) S.C = o(n) + o(n)-> stack space
{
private:
  bool dfs(pair<int, int> node, vector<vector<int>> &adj, vector<bool> &vis)
  {
    int ver = node.first;
    int par = node.second;

    vis[ver] = true;

    for (auto ngh : adj[ver])
    {
      if (vis[ngh] && par != ngh)
        return true;
      if (!vis[ngh])
      {
        if (dfs({ngh, ver}, adj, vis))
          return true;
      }
    }
    return false;
  }

public:
  bool isCycle(int V, vector<vector<int>> &edges)
  {
    // Code here
    vector<vector<int>> adj(V);
    vector<bool> vis(V, false);

    for (int i = 0; i < edges.size(); i++)
    {
      int u = edges[i][0];
      int v = edges[i][1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    for (int i = 0; i < V; i++)
    {
      if (!vis[i])
      {
        if (dfs({i, -1}, adj, vis))
          return true;
      }
    }

    return false;
  }
};