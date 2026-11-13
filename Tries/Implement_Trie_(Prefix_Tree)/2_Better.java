import java.util.*;

class Trie {
    private static class Node {
        boolean isEnd = false;
        Map<Character, Node> child = new HashMap<>();
    }
    private Node root;
    public Trie() {
        root = new Node();
    }
    public void insert(String word) {
        Node node = root;
        for (char c : word.toCharArray()) {
            node.child.putIfAbsent(c, new Node());
            node = node.child.get(c);
        }
        node.isEnd = true;
    }
    public boolean search(String word) {
        Node node = root;
        for (char c : word.toCharArray()) {
            node = node.child.get(c);
            if (node == null) return false;
        }
        return node.isEnd;
    }
    public boolean startsWith(String prefix) {
        Node node = root;
        for (char c : prefix.toCharArray()) {
            node = node.child.get(c);
            if (node == null) return false;
        }
        return true;
    }
}
