class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        java.util.Map<Integer,Integer> freq = new java.util.HashMap<>();
        for(int n: nums) freq.put(n, freq.getOrDefault(n,0)+1);
        java.util.PriorityQueue<java.util.Map.Entry<Integer,Integer>> pq =
            new java.util.PriorityQueue<>(java.util.Comparator.comparingInt(java.util.Map.Entry::getValue));
        for(java.util.Map.Entry<Integer,Integer> e: freq.entrySet()){
            pq.offer(e);
            if(pq.size()>k) pq.poll();
        }
        int[] ans = new int[k];
        int idx=0;
        while(!pq.isEmpty()){
            ans[idx++]=pq.poll().getKey();
        }
        return ans;
    }
}
