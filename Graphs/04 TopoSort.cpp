#include <bits/stdc++.h>
using namespace std;

void addEdges(vector<vector<int>> &adjList, int u, int v)
{
    adjList[u].push_back(v);
    
}


void TopoSortUntill(vector<vector<int>> &adjList, int u, vector<bool> &visited, stack<int> &st)
{
    visited[u] = 1;
    for (auto v : adjList[u])
    {
        if (!visited[v])
        {
            visited[v] = 1;
            TopoSortUntill(adjList, v, visited, st);
        }
    }
    st.push(u);
}


void topologicalSort(vector<vector<int>> &adjList, int n)
{
    vector<bool> visited(n + 1, false);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            visited[i] = 1;
            TopoSortUntill(adjList, i, visited, st);
        }
    }
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

}



int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjList(n + 1);
    

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdges(adjList, u, v);
    }
    cout << "Topological sorting of the graph: ";
    topologicalSort(adjList, n);
}







// till we dont reach a node that has indegree = 0 we keep pushing into the stack.