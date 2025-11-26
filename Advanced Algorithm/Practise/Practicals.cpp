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

// struct Edge
// {
//     int u, v, w;
// };

// struct DSU
// {
//     vector<int> parent, rank;

//     DSU (int n)
//     {
//         parent.resize(n);
//         rank.assign(n, 0);

//         for(int i = 0; i < n; i++)
//         {
//             parent[i] = i;
//         }
//     }

//     int find(int x)
//     {
//         if(parent[x] == x)
//         {
//             return x;
//         }
//         return parent[x] = find(parent[x]); // path compression
//     }

//     void unite(int x, int y)
//     {
//         x = find(x);
//         y = find(y);

//         if(x == y) return;

//         if(rank[x] < rank[y])
//             parent[x] = y;
//         else if(rank[y] < rank[x])
//             parent[y] = x;
//         else
//         {
//             parent[y] = x;
//             rank[x]++;
//         }
//     }
// };

// int main() 
// {
//     int V, E;

//     cout << "Enter number of vertices: ";
//     cin >> V;
//     cout << "Enter number of edges: ";
//     cin >> E;

//     vector<Edge> edges(E);

//     cout << "Enter edges (u v w) with vertices numbered 0 to " << V - 1 << ":\n";

//     for (int i = 0; i < E; i++) 
//     {
//         cin >> edges[i].u >> edges[i].v >> edges[i].w;
//     }

//     // Sort edges by weight
//     sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) 
//     {
//         return a.w < b.w;
//     });

//     DSU dsu(V);
//     int mstWeight = 0;
//     vector<Edge> mstEdges;

//     for (auto &e : edges) 
//     {
//         if (dsu.find(e.u) != dsu.find(e.v)) 
//         {
//             dsu.unite(e.u, e.v);
//             mstEdges.push_back(e);
//             mstWeight += e.w;
//         }
//     }

//     cout << "Edges in MST:\n";
//     for (auto &e : mstEdges) 
//     {
//         cout << e.u << " - " << e.v << " (weight " << e.w << ")\n";
//     }
//     cout << "Total weight of MST: " << mstWeight << "\n";

//     return 0;
// }

struct Edge 
{
    int u, v, w;
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

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    const int INF = INT_MAX;
    vector<int> dist(V, INF);
    dist[src] = 0;

    // Relax edges V-1 times
    for (int i = 1; i <= V - 1; i++) 
    {
        for (auto &e : edges) 
        {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    // Check for negative weight cycles
    bool hasNegativeCycle = false;
    for (auto &e : edges) 
    {
        if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) 
        {
            hasNegativeCycle = true;
            break;
        }
    }

    if (hasNegativeCycle) {
        cout << "Graph contains a negative weight cycle.\n";
    } else {
        cout << "Shortest distances from source " << src << ":\n";
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << " : ";
            if (dist[i] == INF) cout << "INF\n";
            else cout << dist[i] << "\n";
        }
    }

    return 0;
}

// void computeLPS(const string &pat, vector<int> &lps) 
// {
//     int m = pat.size();
//     lps.assign(m, 0);

//     int len = 0; // length of previous longest prefix suffix
//     int i = 1;

//     while (i < m) 
//     {
//         if (pat[i] == pat[len]) 
//         {
//             len++;
//             lps[i] = len;
//             i++;
//         } 
//         else 
//         {
//             if (len != 0) 
//             {
//                 len = lps[len - 1];
//             } 
//             else 
//             {
//                 lps[i] = 0;
//                 i++;
//             }
//         }
//     }
// }

// void KMPSearch(const string &text, const string &pat) 
// {
//     int n = text.size();
//     int m = pat.size();
//     if (m == 0) 
//     {
//         cout << "Empty pattern.\n";
//         return;
//     }

//     vector<int> lps;
//     computeLPS(pat, lps);

//     int i = 0; // index for text
//     int j = 0; // index for pattern

//     bool found = false;
//     while (i < n) 
//     {
//         if (text[i] == pat[j]) 
//         {
//             i++;
//             j++;
//         }

//         if (j == m) 
//         {
//             cout << "Pattern found at index " << (i - j) << "\n";
//             found = true;
//             j = lps[j - 1]; // continue searching
//         } 
//         else if (i < n && text[i] != pat[j]) 
//         {
//             if (j != 0) 
//             {
//                 j = lps[j - 1];
//             } 
//             else 
//             {
//                 i++;
//             }
//         }
//     }

//     if (!found) 
//     {
//         cout << "Pattern not found\n";
//     }
// }

// int main() 
// {
//     string text, pat;

//     cout << "Enter text: ";
//     getline(cin, text);
//     if (text.empty()) getline(cin, text); // handle leftover newline

//     cout << "Enter pattern: ";
//     getline(cin, pat);

//     KMPSearch(text, pat);

//     return 0;
// }
