#include <bits/sdtc++.h>
using namespace std;

class Solution
{
public:
  vector<int> BFS(int v, vector<vector<int>> &adj)
  {
    vector<int> vis(v, 0);
    vis[0] = 1;
    queue<int> q;
    q.push(0);

    vector<int> bfs;

    while (!q.empty())
    {
      int node = q.front();
      q.pop();
      bfs.push_back(node);

      for (auto nbr : adj[node])
      {
        if (!vis[nbr])
        {
          vis[nbr] = 1;
          q.push(nbr);
        }
      }
    }

    return bfs;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> adj = {
      {2, 3, 1},
      {0},
      {0, 4},
      {0},
      {2}};

  vector<int> result = sol.BFS(5, adj);

  for (int x : result)
    cout << x << " ";
  cout << endl;

  return 0;
}
