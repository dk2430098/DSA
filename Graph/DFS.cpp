#include <bits/sdtc++.h>
using namespace std;

class Solution // T.C = o(n) + o(2E)  S.C = o(n)
{
private:
  void dfs(vector<vector<int>> &adj, vector<int> &list, vector<bool> &vis, int node)
  {
    vis[node] = true;
    list.push_back(node);

    for (auto ngh : adj[node])
    {
      if (!vis[ngh])
      {
        dfs(adj, list, vis, ngh);
      }
    }
  }

public:
  int dfsOfGraph(vector<vector<int>> &adj)
  {
    int v = adj.size();
    vector<bool> vis(v, false);
    vector<int> list;

    dfs(adj, list, vis, 0);
  }
};
