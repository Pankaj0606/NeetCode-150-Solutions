class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        java.util.Map<Integer,Integer> freq = new java.util.HashMap<>();
        for(int n: nums) freq.put(n, freq.getOrDefault(n,0)+1);
        java.util.List<java.util.Map.Entry<Integer,Integer>> list = new java.util.ArrayList<>(freq.entrySet());
        list.sort((a,b)->b.getValue()-a.getValue());
        int[] ans = new int[k];
        for(int i=0;i<k;i++) ans[i]=list.get(i).getKey();
        return ans;
    }
}
