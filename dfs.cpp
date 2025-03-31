#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS(int s) {
        vector<bool> discovered(V, false);
        vector<int> parent(V, -1);
        stack<int> st;
        
        st.push(s);
        
        cout << "DFS Traversal: ";
        while (!st.empty()) {
            int u = st.top();
            st.pop();
            
            if (!discovered[u]) {
                discovered[u] = true;
                cout << u << " ";
                
                for (int v : adj[u]) {
                    if (!discovered[v]) {
                        st.push(v);
                        parent[v] = u;
                    }
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    
    g.DFS(0);
    
    return 0;
}
