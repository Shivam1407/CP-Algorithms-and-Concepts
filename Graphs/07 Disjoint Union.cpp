#include <bits/stdc++.h>

using namespace std;

class DisJoint
{
private:
    vector<int> parent;
    vector<int> size;

public:
    DisJoint(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; ++i)
        {
            parent[i] = i;
        }
    }

    int findPar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }

    void UnionBySize(int u, int v)
    {
        u = findPar(u);
        v = findPar(v);
        if (u != v)
        {
            if (size[u] < size[v])
            {
                parent[u] = v;
                size[v] += size[u];
            }
            else
            {
                parent[v] = u;
                size[u] += size[v];
            }
        }
    }

    void printGraph()
    {
        cout << "Node\tParent\tSize" << endl;
        for (int i = 1; i < parent.size(); ++i)
        {
            cout << i << "\t" << parent[i] << "\t" << size[i] << endl;
        }
    }
};

int main()
{
    int n = 10;
    DisJoint ds(n);

    ds.UnionBySize(1, 2);
    ds.UnionBySize(2, 3);
    ds.UnionBySize(6, 7);
    ds.UnionBySize(5, 6);
    ds.UnionBySize(3, 7);
    ds.UnionBySize(4, 5);

    // print parent and size array
    

    cout << "Find(3): " << ds.findPar(3) << endl; // Output: representative of the set containing 3
    cout << "Find(5): " << ds.findPar(5) << endl; // Output: representative of the set containing 5
    cout << "Find(2): " << ds.findPar(2) << endl; // Output: representative of the set containing 2

    ds.printGraph();

    return 0;
}
