class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &visited){
        int drow[] = {0,1,0,-1};
        int dcol[] = {-1,0,1,0};
        int sum = 0;
        int n = grid.size(); int m = grid[0].size();
        for(int k =0; k<4; k++){
            int ni = i + drow[k];
            int nj = j + dcol[k];
            if(ni>=0 && ni<n && nj>=0 && nj<m){
                if(grid[ni][nj] && ! visited[ni][nj]){
                    visited[ni][nj] = 1;
                    sum += dfs(ni,nj,grid,visited);
                }
            }
        }
        return sum + grid[i][j];
    }
    int findMaxFish(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m,0));
        int maxi =0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && grid[i][j]){
                    visited[i][j] = 1;
                    int sum = dfs(i,j,grid,visited);
                    maxi = max(sum,maxi);
                }
            }
        }
        return maxi;
    }
};