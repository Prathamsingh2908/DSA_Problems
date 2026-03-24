class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> adj(V);
        for(auto& e : edges) {
        adj[e[0]].push_back({e[1], e[2]});
        adj[e[1]].push_back({e[0], e[2]}); // undirected
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(V);
        for(int i = 0; i< V; i++)
            dist[i] = 1e9;
            
            dist[src] = 0;
            pq.push({0,src});
            
            while(!pq.empty()){
                int dis = pq.top().first;
                int node = pq.top().second;
                pq.pop();
                
                for(auto it: adj[node]){
                    int edgeWeight = it.second;
                    int adjNode = it.first;
                
                    if(dis + edgeWeight < dist[adjNode]){
                        dist[adjNode] = dis + edgeWeight;
                        pq.push({dist[adjNode], adjNode});
                    }
                }
            }
        return dist;
    }
};