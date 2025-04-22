class Solution {
    public int shortestPath(int[][] grid, int z) {
        int n = grid.length;
        int m = grid[0].length;
        Queue<int[]> q = new LinkedList<>();// i,j,k, dist
        q.add(new int[]{0,0,z,0});
        int [] drow = {1,0,-1,0};
        int [] dcol = {0,-1,0,1};
        int res = 0;
        Set<String> visited = new HashSet<>();
        visited.add(0 + "," + 0 + "," + z);
        while(!q.isEmpty()){
            int[] a = q.poll();
            int x = a[0]; int y = a[1]; int kk = a[2]; int dist = a[3];
            if(x == n-1 && y == m-1) return dist;

            for(int k =0; k<4; k++){
                int dx = x + drow[k];
                int dy = y + dcol[k];
                if(dx>=0 && dx<n && dy>=0 && dy<m){
                    if(grid[dx][dy] == 1){
                        if(kk==0) continue;

                        String key = dx + "," + dy + "," + (kk-1);
                        if(visited.contains(key)) continue;
                        q.add(new int[]{dx,dy,kk-1,dist+1});
                        visited.add(key);
                    }
                    else{
                        String key = dx + "," + dy + "," + kk;
                        if(visited.contains(key)) continue;
                        q.add(new int[]{dx,dy,kk,dist+1});
                        visited.add(key);
                    }
                }
            }
            
        }
        return -1;
    }
}