public class Solution {
    public boolean isValid(String s) {
        String[] pairs = {"()", "{}", "[]"};
        boolean changed = true;
        while (changed) {
            changed = false;
            for (String p : pairs) {
                int idx = s.indexOf(p);
                if (idx != -1) {
                    s = s.substring(0, idx) + s.substring(idx + 2);
                    changed = true;
                }
            }
        }
        return s.isEmpty();
    }
}
