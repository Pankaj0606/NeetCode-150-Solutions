import java.util.*;

class Trie {
    private List<String> words;
    public Trie() {
        words = new ArrayList<>();
    }
    public void insert(String word) {
        words.add(word);
    }
    public boolean search(String word) {
        for (String w : words) {
            if (w.equals(word)) return true;
        }
        return false;
    }
    public boolean startsWith(String prefix) {
        for (String w : words) {
            if (w.startsWith(prefix)) return true;
        }
        return false;
    }
}
