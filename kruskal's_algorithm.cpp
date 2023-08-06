#include <bits/stdc++.h>

bool cmp(vector<int> &a, vector<int> &b)
{

  return a[2] < b[2];
}

void makeset(vector<int> &parent, vector<int> &rank, int n)
{

  for (int i = 0; i < n; i++)
  {
    parent[i] = i;
    rank[i] = 0;
  }
}

int find_parent(vector<int> &parent, int node)
{

  if (parent[node] == node)
    return node;

  else
  {
    return parent[node] = find_parent(parent, parent[node]);
  }
}

void union_set(int u, int v, vector<int> &parent, vector<int> &rank)
{

  v = find_parent(parent, v);
  u = find_parent(parent, u);

  if (rank[u] > rank[v])
  {

    parent[v] = u;
  }

  else if (rank[u] < rank[v])
  {

    parent[u] = v;
  }

  else
  {
    parent[u] = v;
    rank[v]++;
  }
}

int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
  sort(edges.begin(), edges.end(), cmp);

  vector<int> parent(n);
  vector<int> rank(n);
  int ans = 0;

  makeset(parent, rank, n);

  int size = edges.size();

  for (int i = 0; i < size; i++)
  {

    int u = find_parent(parent, edges[i][0]);
    int v = find_parent(parent, edges[i][1]);
    int wt = edges[i][2];

    if (u != v)
    {

      union_set(u, v, parent, rank);
      ans += wt;
    }
  }

  return ans;
}


