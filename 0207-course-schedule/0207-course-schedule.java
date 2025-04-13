class Solution {
    public boolean canFinish(int numcourses, int[][] prereq) {
        int[] indegree = new int[numcourses];
        List<Integer>[] adj = new ArrayList[numcourses];
        List<Integer> topo = new ArrayList<>();
        for (int i = 0; i < numcourses; i++) {
            adj[i] = new ArrayList<>();
        }

        for(int i=0; i<prereq.length; i++){
            int src = prereq[i][0]; 
            int des = prereq[i][1];
            adj[des].add(src);
            indegree[src]++;
        }

        Queue<Integer> queue = new LinkedList<>();

        for(int i=0; i<numcourses; i++){
            if(indegree[i] == 0){
                queue.offer(i);
            }
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

        return topo.size() == numcourses;

    }
}