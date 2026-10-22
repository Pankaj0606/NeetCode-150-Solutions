import java.util.*;

class Node {
    int val;
    Node next;
    Node random;
    Node(int _val) { val = _val; next = null; random = null; }
}

class Solution {
    public Node copyRandomList(Node head) {
        if (head == null) return null;
        Map<Node, Node> map = new HashMap<>();
        // First pass: copy nodes
        Node cur = head;
        while (cur != null) {
            map.put(cur, new Node(cur.val));
            cur = cur.next;
        }
        // Second pass: assign next and random
        cur = head;
        while (cur != null) {
            Node copy = map.get(cur);
            copy.next = (cur.next != null) ? map.get(cur.next) : null;
            copy.random = (cur.random != null) ? map.get(cur.random) : null;
            cur = cur.next;
        }
        return map.get(head);
    }
}
