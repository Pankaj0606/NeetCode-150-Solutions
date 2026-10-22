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
        // 1. Weave copy nodes with original list
        Node cur = head;
        while (cur != null) {
            Node copy = new Node(cur.val);
            copy.next = cur.next;
            cur.next = copy;
            cur = copy.next;
        }
        // 2. Assign random pointers for copies
        cur = head;
        while (cur != null) {
            if (cur.random != null) {
                cur.next.random = cur.random.next;
            } else {
                cur.next.random = null;
            }
            cur = cur.next.next;
        }
        // 3. Unweave to separate the copied list
        Node dummy = new Node(0);
        Node copyCur = dummy;
        cur = head;
        while (cur != null) {
            Node copy = cur.next;
            cur.next = copy.next; // restore original next
            copyCur.next = copy;   // build copied list
            copyCur = copyCur.next;
            cur = cur.next;
        }
        return dummy.next;
    }
}
