class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;
        boolean[] visited = new boolean[t.length()];
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            boolean found = false;
            for (int j = 0; j < t.length(); j++) {
                if (!visited[j] && t.charAt(j) == c) {
                    visited[j] = true;
                    found = true;
                    break;
                }
            }
            if (!found) return false;
        }
        return true;
    }
}
