class Solution {
  public:
    bool dfs(int node, int col, vector<int>& color, vector<int> adj[]) {
        color[node] = col;
        for (auto it : adj[node]) {
            if (color[it] == -1) {
                if (dfs(it, !col, color, adj) == false) return false;
            } else if (color[it] == col) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> color(V, -1);
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (dfs(i, 0, color, adj) == false) return false;
            }
        }
        return true;
    }
};