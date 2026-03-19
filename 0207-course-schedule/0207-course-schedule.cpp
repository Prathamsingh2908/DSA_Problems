class Solution {
private:
    bool checkCycle(int node, vector<int> adj[], vector<int>& vis, vector<int>& dfsVis) {
        vis[node] = 1;
        dfsVis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (checkCycle(it, adj, vis, dfsVis))
                    return true;
            }
            else if (dfsVis[it]) {
                return true;
            }
        }

        dfsVis[node] = 0; // backtrack
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Step 1: build adjacency list
        vector<int> adj[numCourses];
        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]); // b → a
        }

        // Step 2: same DFS cycle detection
        vector<int> vis(numCourses, 0), dfsVis(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (checkCycle(i, adj, vis, dfsVis))
                    return false; // cycle found → can't finish
            }
        }

        return true; // no cycle → can finish
    }
};