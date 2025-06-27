#include <iostream>
#include <vector>
using namespace std;

// Undirected Graph
int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> adj[n + 1];

  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
}

int main() // -> weighted
{
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> adj[n + 1];

  for (int i = 0; i < m; i++)
  {
    int u, v, wt;
    cin >> u >> v >> wt;
    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt});
  }
}

// Directed Graph
int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> adj[n + 1];

  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
}

int main() // -> weighted
{
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> adj[n + 1];

  for (int i = 0; i < m; i++)
  {
    int u, v, wt;
    cin >> u >> v >> wt;
    adj[u].push_back({v, wt});
  }
}