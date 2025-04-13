class Solution {
    public List<Integer> eventualSafeNodes(int[][] graph) {
        int n = graph.length;
        List<Integer>[] adj = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }
        int[] indegree = new int[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<graph[i].length; j++){
                int src = i; int des = graph[i][j];
                adj[des].add(src);
                indegree[src]++;
            }
        }
        List<Integer> topo = new ArrayList<>();
        Queue<Integer>queue = new LinkedList<>();

        for(int i=0; i<n; i++){
            if(indegree[i] == 0) queue.offer(i);
        }

        while(!queue.isEmpty()){
            int src = queue.poll();
            for(int x: adj[src]){
                indegree[x]--;
                if(indegree[x] == 0){
                    queue.offer(x);
                }
            }
            topo.add(src);
        }
        Collections.sort(topo);
        return topo;
    }
}