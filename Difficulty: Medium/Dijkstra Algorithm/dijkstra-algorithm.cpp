class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> adj(V);
        for(auto& e : edges) {
        adj[e[0]].push_back({e[1], e[2]});
        adj[e[1]].push_back({e[0], e[2]}); // undirected
        }
        
        set<pair<int,int>> st;
        vector<int> dist(V, 1e9);

        st.insert({0, src});
        dist[src] = 0;

        while(!st.empty()) {
            auto it = *(st.begin());
            int dis = it.first;
            int node = it.second;
            st.erase(it);

            for(auto it : adj[node]) {
                int adjNode = it.first;
                int edgW = it.second;

                if(dis + edgW < dist[adjNode]) {
                    if(dist[adjNode] != 1e9)
                        st.erase({dist[adjNode], adjNode});

                    dist[adjNode] = dis + edgW;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};
