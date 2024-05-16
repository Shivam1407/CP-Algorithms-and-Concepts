#include <bits/stdc++.h>
using namespace std;

void addEdges(vector<vector<int>> &adjList, int u, int v)
{
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjList(n + 1);
    vector<bool> visited(n + 1, false);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdges(adjList, u, v);
    }
}