class Solution {
public:
    int bfs(vector<vector<int>>&adj,int n){
        vector<int> dist(n, INT_MAX);
        queue<int> q;
        q.push(0);
        dist[0] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : adj[node]) {
                if (dist[it] == INT_MAX) {
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }
        return dist[n - 1];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>adj(n);
        for(int i=0; i<n-1; i++){
            adj[i].push_back(i+1);
        }
        vector<int>res;
        for(auto it: queries){
            int src = it[0];
            int dst = it[1];
            adj[src].push_back(dst);
            int x = bfs(adj,n);
            res.push_back(x);            
        }
        return res;
    }
};