//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// ✅ Kahn’s Algorithm (BFS-based Topological Sort)
class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> in(V, 0), res;
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            in[e[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
            if (!in[i])
                q.push(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            res.push_back(u);
            for (int v : adj[u])
                if (--in[v] == 0)                 
                    q.push(v);
        }
        return res;
    }
};

//{ Driver Code Starts.

int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;

        int x = V;
        vector<vector<int>> adj(V);
        vector<vector<int>> edges;

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            edges.push_back({u, v});
        }

        Solution obj;
        vector<int> res = obj.topoSort(V, edges);
        bool ans = check(x, res, adj);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends