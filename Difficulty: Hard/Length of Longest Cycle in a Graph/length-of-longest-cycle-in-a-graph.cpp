class Solution {
public:
    int longestCycle(int V, vector<vector<int>>& edges) {
        
        vector<int> adj(V, -1);
        
        // Convert to single outgoing edge format
        for(auto &e : edges) {
            adj[e[0]] = e[1];
        }
        
        vector<bool> visited(V, false);
        vector<bool> pathVisited(V, false);
        vector<int> time(V, 0);
        
        int ans = -1;
        
        for(int i = 0; i < V; i++) {
            if(visited[i]) continue;
            
            int node = i;
            int step = 0;
            
            while(node != -1 && !visited[node]) {
                visited[node] = true;
                pathVisited[node] = true;
                time[node] = step++;
                
                node = adj[node];
            }
            
            // Cycle check
            if(node != -1 && pathVisited[node]) {
                ans = max(ans, step - time[node]);
            }
            
            // Cleanup pathVisited
            node = i;
            while(node != -1 && pathVisited[node]) {
                pathVisited[node] = false;
                node = adj[node];
            }
        }
        
        return ans;
    }
};