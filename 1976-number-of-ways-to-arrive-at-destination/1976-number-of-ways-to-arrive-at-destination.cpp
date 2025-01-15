class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD = 1e9+7;
        vector<vector<pair<int,int>>>adj(n); // node,dist
        for(auto it: roads){
            int x = it[0]; int y = it[1]; int d = it[2];
            adj[x].push_back({y,d});
            adj[y].push_back({x,d});
        }
        priority_queue<pair<int,int>,vector<pair<int, int>>, greater<pair<int, int>>> pq; // dist,node

        vector<int>dist(n,INT_MAX);
        vector<int>ways(n,0);
        ways[0] = 1; dist[0]=0;

        pq.push({0,0});

        while(!pq.empty()){
            int src = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            for(auto it: adj[src]){
                if(d+it.second < dist[it.first]){
                    ways[it.first] = ways[src];
                    dist[it.first] = d+it.second;
                    pq.push({d+it.second,it.first});
                }
                else if(d+it.second == dist[it.first]){
                    ways[it.first] += ways[src];
                    ways[it.first] %= MOD;
                }
            }
        }

        return ways[n-1];
    }
};