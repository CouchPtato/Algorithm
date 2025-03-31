#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii; // (weight, vertex)

void primMST(int V, vector<vector<pii>> &adj) {
    vector<int> key(V, 1e9);   
    vector<int> parent(V, -1);       
    vector<bool> inMST(V, false);  

    priority_queue<pii, vector<pii>, greater<pii>> pq; 
    key[0] = 0;
    pq.push({0, 0}); 

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        if (inMST[u]) continue;
        inMST[u] = true;
        
        for (auto it : adj[u]) {
            int weight = it.first;
            int v = it.second;
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    cout << "Edges in the MST:\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\n";
    }
}

int main() {
    int V = 5; 
    vector<vector<pii>> adj(V);
    
    adj[0].push_back({2, 1});
    adj[1].push_back({2, 0});
    
    adj[0].push_back({3, 3});
    adj[3].push_back({3, 0});
    
    adj[1].push_back({3, 2});
    adj[2].push_back({3, 1});
    
    adj[1].push_back({1, 3});
    adj[3].push_back({1, 1});
    
    adj[1].push_back({4, 4});
    adj[4].push_back({4, 1});
    
    adj[2].push_back({5, 4});
    adj[4].push_back({5, 2});
    
    adj[3].push_back({6, 4});
    adj[4].push_back({6, 3});
    
    primMST(V, adj);
    return 0;
}