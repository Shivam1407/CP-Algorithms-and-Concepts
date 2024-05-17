#include <bits/stdc++.h>
using namespace std;

void addEdges(vector<vector<int>> &adjList, int u, int v)
{
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}


void BFS(vector<vector<int>> &adjList, int u, vector<bool> &visited){
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(auto v : adjList[node]){
            if(!visited[v])
            {
                visited[v] = 1;
                q.push(v);
            }
        }
    }
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

    int startNode;
    cin >> startNode;
    cout << "Enter the start node for BFS: " << startNode << endl;
    BFS(adjList, startNode, visited);
    return 0;
}