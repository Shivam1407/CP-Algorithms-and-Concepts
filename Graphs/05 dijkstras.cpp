#include <bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<pair<int, int>>> &adjList, int startNode, int n)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n+1, INT_MAX);

    dist[startNode] = 0;
    pq.push({0, startNode});
    while (!pq.empty())
    {
        int node = pq.top().second;
        pq.pop();

        for (auto neighbour : adjList[node])
        {
            int nextNode = neighbour.first;
            int weight = neighbour.second;

            if (dist[nextNode] > dist[node] + weight)
            {
                dist[nextNode] = dist[node] + weight;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }

    cout << "The shortest distance from node " << startNode << " to all other nodes is: " << endl;

    for (int i = 1; i <= n; i++)
    {
        if (i == startNode)
            continue;
        if (dist[i] == INT_MAX)
            cout << "Node " << i << " is not reachable from the start node." << endl;
        else
            cout << "Distance to node " << i << ": " << dist[i] << endl;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adjList(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
    }

    int startNode;
    cin >> startNode;

    dijkstra(adjList, startNode, n);

    return 0;
}
