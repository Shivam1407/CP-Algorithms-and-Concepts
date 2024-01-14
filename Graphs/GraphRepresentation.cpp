#include<bits/stdc++.h>
using namespace std;

void addEdges(vector<vector<int>>& addList, int u, int v)
{
    addList[u].push_back(v);
    addList[v].push_back(u);
}

void printGraph(vector<vector<int>>& addList)
{
    for (int i = 0; i < addList.size(); ++i) {
        cout << "Adjacency list of vertex " << i << ": ";
        for (const int& neighbor : addList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> addList(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdges(addList, u, v);
    }

    cout << "Graph:" << endl;
    printGraph(addList);


        return 0;
}


//               Graph:
// Adjacency list of vertex 0: 
// Adjacency list of vertex 1: 2 3 
// Adjacency list of vertex 2: 1 4 5 
// Adjacency list of vertex 3: 1 4 
// Adjacency list of vertex 4: 2 5 3 
// Adjacency list of vertex 5: 2 4