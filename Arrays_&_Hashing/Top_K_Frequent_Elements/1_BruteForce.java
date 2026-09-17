class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        java.util.Map<Integer,Integer> freq = new java.util.HashMap<>();
        for(int n: nums) freq.put(n, freq.getOrDefault(n,0)+1);
        java.util.List<Integer> result = new java.util.ArrayList<>();
        for(int i=0;i<k;i++){
            int maxFreq=0, candidate=0;
            for(java.util.Map.Entry<Integer,Integer> e: freq.entrySet()){
                if(e.getValue()>maxFreq){
                    maxFreq=e.getValue();
                    candidate=e.getKey();
                }
            }
            result.add(candidate);
            freq.remove(candidate);
        }
        int[] ans = new int[result.size()];
        for(int i=0;i<ans.length;i++) ans[i]=result.get(i);
        return ans;
    }
}
