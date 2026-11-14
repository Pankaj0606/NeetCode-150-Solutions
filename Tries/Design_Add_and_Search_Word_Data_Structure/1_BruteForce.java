import java.util.*;

public class WordDictionary {
    private List<String> words;
    public WordDictionary() {
        words = new ArrayList<>();
    }
    public void addWord(String word) {
        words.add(word);
    }
    public boolean search(String word) {
        for (String w : words) {
            if (matches(w, word)) return true;
        }
        return false;
    }
    private boolean matches(String w, String pattern) {
        if (w.length() != pattern.length()) return false;
        for (int i = 0; i < w.length(); i++) {
            char pc = pattern.charAt(i);
            if (pc != '.' && w.charAt(i) != pc) return false;
        }
        return true;
    }
}
