#include <iostream>
using namespace std;

// Undirected Graph
int main()
{
  int n, m;
  cin >> n >> m;
  int adj[n + 1][n + 1];

  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u][v] = 1;
    adj[v][u] = 1;
  }
}

int main() // -> Weighted
{
  int n, m;
  cin >> n >> m;
  int adj[n + 1][n + 1];

  for (int i = 0; i < m; i++)
  {
    int u, v, wt;
    cin >> u >> v >> wt;
    adj[u][v] = wt;
    adj[v][u] = wt;
  }
}

// Directed Graph
int main()
{
  int n, m;
  cin >> n >> m;
  int adj[n + 1][n + 1];

  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u][v] = 1;
  }
}

int main() // -> Weighted
{
  int n, m;
  cin >> n >> m;
  int adj[n + 1][n + 1];

  for (int i = 0; i < m; i++)
  {
    int u, v, wt;
    cin >> u >> v >> wt;
    adj[u][v] = wt;
  }
}