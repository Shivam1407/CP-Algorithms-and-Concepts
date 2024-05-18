#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

struct Edge
{
    int src, dest, wt;

    // Overload the operator for priority_queue
    bool operator>(const Edge &e) const
    {
        return this->wt > e.wt;
    }
};

void MSTusingPRIM(vector<vector<pii>> &adjList, int n)
{
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq; // Min heap    // O(E)
    vector<bool> visited(n, false);
    vector<Edge> mstEdges;

    int totalCost = 0;
    int startNode = 0;
    visited[startNode] = true;
    // ELOGE
    for (auto &neighbour : adjList[startNode])
    {
        int neighbourNode = neighbour.first;
        int weight = neighbour.second;
        pq.push({startNode, neighbourNode, weight});
    }
    // E                          O(ELogE)
    while (!pq.empty())
    {
        //LogE
        Edge currentEdge = pq.top();
        pq.pop();

        if (visited[currentEdge.dest])
            continue;

        visited[currentEdge.dest] = true;
        totalCost += currentEdge.wt;
        mstEdges.push_back(currentEdge);
    // ELogE
        for (auto &neighbour : adjList[currentEdge.dest])
        {
            if (!visited[neighbour.first])
            {
                pq.push({currentEdge.dest, neighbour.first, neighbour.second});
            }
        }
    }

    cout << "The total cost of the minimum spanning tree is: " << totalCost << endl;
    cout << "The edges in the minimum spanning tree are:" << endl;
    for (const auto &edge : mstEdges)
    {
        cout << edge.src << " - " << edge.dest << " : " << edge.wt << endl;
    }
}
int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pii>> adjList(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    MSTusingPRIM(adjList, n);
    return 0;
}