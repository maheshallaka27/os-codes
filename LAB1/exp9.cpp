#include <bits/stdc++.h>
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
    }

    bool dfs(int node, vector<int> &vis, vector<int> &rec) {
        vis[node] = 1;
        rec[node] = 1;

        for (int v : adj[node]) {
            if (!vis[v] && dfs(v, vis, rec)) return true;
            else if (rec[v]) return true;
        }

        rec[node] = 0;
        return false;
    }

    bool isCycle() {
        vector<int> vis(V, 0), rec(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, rec)) return true;
            }
        }
        return false;
    }
};

int main() {
    int p, e;
    cin >> p >> e;

    Graph g(p);

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    if (g.isCycle()) cout << "Deadlock detected";
    else cout << "No deadlock";

    return 0;
}