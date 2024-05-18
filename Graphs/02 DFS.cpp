#include <bits/stdc++.h>
using namespace std;

void addEdges(vector<vector<int>>& adjList, int u, int v)
{
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}
void DFS(vector<vector<int>>& adjList, int u, vector<bool> &visited, vector<int>&path)
{
    visited[u] = 1;
    path.push_back(u);
    bool isLeaf = true;

    for(auto v : adjList[u])
    {
        if(!visited[v])
        {
            isLeaf = false;
            DFS(adjList, v, visited, path);
        }
    }

    if(isLeaf)
    {
        for(auto node : path)
        {
            cout << node << " ";
        }
        cout << endl;
    }
    

    visited[u] = 0;
    path.pop_back();
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjList(n + 1);
    vector<bool> visited(n + 1, false);

    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        addEdges(adjList, u, v);
    }

    int startNode;
    cin >> startNode;
    vector<int> path;
    cout << "Enter the start node for DFS: " << startNode << endl;
    DFS(adjList, startNode, visited, path);

    return 0;
}


// TC = O(V+E)
// SC = O(V) 