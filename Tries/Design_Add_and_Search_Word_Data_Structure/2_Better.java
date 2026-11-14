import java.util.*;

public class WordDictionary {
    private Map<Integer, List<String>> bucket;
    public WordDictionary() {
        bucket = new HashMap<>();
    }
    public void addWord(String word) {
        int len = word.length();
        bucket.computeIfAbsent(len, k -> new ArrayList<>()).add(word);
    }
    public boolean search(String word) {
        int len = word.length();
        List<String> list = bucket.get(len);
        if (list == null) return false;
        for (String w : list) {
            if (matches(w, word)) return true;
        }
        return false;
    }
    private boolean matches(String w, String pattern) {
        for (int i = 0; i < w.length(); i++) {
            char pc = pattern.charAt(i);
            if (pc != '.' && w.charAt(i) != pc) return false;
        }
        return true;
    }
}
