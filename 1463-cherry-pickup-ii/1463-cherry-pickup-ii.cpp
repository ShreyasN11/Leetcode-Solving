class Solution {
public:
    int helper(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
        if(j1<0 || j2<0 || j1>c || j2 >c){
            return -10000;
        }
        if(i==r){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int maxi = -10000;

        for(int ni = -1; ni<2; ni++){
            for(int nj = -1; nj<2; nj++){
                int x = 0;
                if(j1==j2) x = grid[i][j1];
                else x = grid[i][j1] + grid[i][j2];
                x+= helper(i+1, j1+ni, j2+nj, r, c, grid, dp);
                maxi = max(maxi, x);

            }
        }
        dp[i][j1][j2] = maxi;
        return maxi;

    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m,-1)));
        return helper(0, 0, m-1, n-1, m-1, grid, dp);

    }
};