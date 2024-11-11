class Solution {
public:
    int helper(int i1, int j1, int i2, int j2, vector<vector<int>>& grid, vector<vector<vector<vector<int>>>>&dp, int n){
        if(i1>=n || i2>=n || j1>=n || j2>=n || grid[i1][j1] == -1 || grid[i2][j2] == -1) return -10000;
        if (i1 == n-1 && j1 == n-1 && i2==n-1 && j2==n-1) return grid[i1][j1];
        if(dp[i1][j1][i2][j2] != -1) return dp[i1][j1][i2][j2];
        int cherries = 0;
        if(i1==i2 && j1==j2) cherries += grid[i1][j1]; 
        else cherries += grid[i1][j1] + grid[i2][j2];
        int a = helper(i1+1,j1,i2+1,j2,grid,dp,n);
        int b = helper(i1+1,j1,i2,j2+1,grid,dp,n);
        int c = helper(i1,j1+1,i2+1,j2,grid,dp,n);
        int d = helper(i1,j1+1,i2,j2+1,grid,dp,n);
        return dp[i1][j1][i2][j2] = cherries + max({a,b,c,d});
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<vector<int>>>>dp(n,vector<vector<vector<int>>>(n,vector<vector<int>>(n, vector<int>(n, -1))));
        int result = helper(0,0,0,0,grid,dp,n);
        return max(0, result);
    }
};