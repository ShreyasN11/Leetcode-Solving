class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({0,{0,0}});
        vector<int> drow = {1,0,-1,0};
        vector<int> dcol = {0,-1,0,1};
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0] = 0;
        while(!pq.empty()){
            int obs = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            for(int k=0; k<4; k++){
                int ni = i + drow[k];
                int nj = j + dcol[k];
                if(ni>=0 && ni<n && nj>=0 && nj<m){
                    if(ni == n-1 && nj == m-1) return obs;
                    if(dist[ni][nj] > obs + grid[ni][nj]){
                        pq.push({obs+grid[ni][nj],{ni,nj}});
                        dist[ni][nj] = obs+grid[ni][nj];
                    }
                    //pq.push({obs+grid[ni][nj],{ni,nj}});
                }
            }
        }
        return m*n -2;
    }
};