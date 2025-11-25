#include <bits/stdc++.h>
using namespace std;

// int comparisons = 0;

// int partition(vector<int> &Array, int start, int end)
// {
//     int x = Array[end];
//     int i = start - 1;

//     for (int j = start; j <= end - 1; j++)
//     {
//         comparisons++;
//         if (Array[j] <= x)
//         {
//             i = i + 1;
//             swap(Array[i], Array[j]);
//         }
//     }
//     swap(Array[i+1], Array[end]);
//     return (i+1);
// }

// int randomizedPartition(vector<int> &Array, int start, int end)
// {
//     int j = start + rand() % (end - start + 1);
//     swap(Array[end], Array[j]);
//     return partition(Array, start, end);
// }

// void quickSort(vector<int> &A, int p, int r)
// {
//     if (p < r)
//     {
//         int q = randomizedPartition(A, p, r);
//         quickSort(A, p, q - 1);
//         quickSort(A, q + 1, r);
//     }
// }

// int main()
// {
//     vector<int> A = {8,7,6,5,4,3,2,1,0};
//     int n = A.size();

//     quickSort(A, 0, n - 1);
    
//     for (int x : A)
//     {
//         cout << x << " ";
//     }

//     cout << "\nComparisons: " << comparisons;

//     return 0;
// }

// int rSelect(vector<int> &A, int p, int r, int i)
// {
//     comparisons++;
//     if (p == r) // if there is only one element.
//     {
//         return A[p];
//     }

//     int q = randomizedPartition(A, p, r);
//     int k = q - p + 1;

//     comparisons++;
//     if (i == k)
//     {
//         return A[q];
//     }
//     else if (i < k)
//     {
//         rSelect(A, p, q - 1, i);
//     }
//     else
//     {
//         rSelect(A, q + 1, r, i - k);
//     }
    
// }

// int main()
// {
//     vector<int> A = {8,7,6,5,4,3,2,1,0};
//     int n = A.size();
//     int i = 5;

//     int result = rSelect(A, 0, n - 1, i);

//     cout << i << "-th smallest element: " << result;
//     cout << "\nComparisons: " << comparisons;

//     return 0;
// }

struct Edge
{
    int u, v, w;
};

struct DSU
{
    vector<int> parent, rank;

    DSU (int n)
    {
        parent.resize(n);
        rank.assign(n, 0);

        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if(parent[x] == x)
        {
            return x;
        }
        return parent[x] = find(parent[x]); // path compression
    }

    void unite(int x, int y)
    {
        x = find(x);
        y = find(y);

        if(x == y) return;

        if(rank[x] < rank[y])
            parent[x] = y;
        else if(rank[y] < rank[x])
            parent[y] = x;
        else
        {
            parent[y] = x;
            rank[x]++;
        }
    }
};

int main() 
{
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<Edge> edges(E);

    cout << "Enter edges (u v w) with vertices numbered 0 to " << V - 1 << ":\n";

    for (int i = 0; i < E; i++) 
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) 
    {
        return a.w < b.w;
    });

    DSU dsu(V);
    int mstWeight = 0;
    vector<Edge> mstEdges;

    for (auto &e : edges) 
    {
        if (dsu.find(e.u) != dsu.find(e.v)) 
        {
            dsu.unite(e.u, e.v);
            mstEdges.push_back(e);
            mstWeight += e.w;
        }
    }

    cout << "Edges in MST:\n";
    for (auto &e : mstEdges) 
    {
        cout << e.u << " - " << e.v << " (weight " << e.w << ")\n";
    }
    cout << "Total weight of MST: " << mstWeight << "\n";

    return 0;
}