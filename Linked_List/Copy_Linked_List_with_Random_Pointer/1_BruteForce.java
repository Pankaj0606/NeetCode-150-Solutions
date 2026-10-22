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
        // First pass: copy nodes preserving next only
        Node cur = head;
        Node dummy = new Node(0);
        Node copyCur = dummy;
        while (cur != null) {
            copyCur.next = new Node(cur.val);
            copyCur = copyCur.next;
            cur = cur.next;
        }
        Node copyHead = dummy.next;
        // Second pass: set random pointers by linear search (O(N^2))
        Node orig = head;
        Node copy = copyHead;
        while (orig != null) {
            if (orig.random != null) {
                Node target = orig.random;
                Node tOrig = head;
                Node tCopy = copyHead;
                while (tOrig != null && tOrig != target) {
                    tOrig = tOrig.next;
                    tCopy = tCopy.next;
                }
                copy.random = tCopy; // will be null only if not found (shouldn't happen)
            } else {
                copy.random = null;
            }
            orig = orig.next;
            copy = copy.next;
        }
        return copyHead;
    }
}
