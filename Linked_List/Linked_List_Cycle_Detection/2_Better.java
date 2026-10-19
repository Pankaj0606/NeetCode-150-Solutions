class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; next = null; }
}
public class Solution {
    public boolean hasCycle(ListNode head) {
        if (head == null) return false;
        ListNode prev = null;
        ListNode curr = head;
        while (curr != null) {
            ListNode nextNode = curr.next;
            curr.next = prev; // reverse link
            prev = curr;
            curr = nextNode;
            if (curr == null) {
                restore(prev);
                return false;
            }
            if (curr == head) {
                restore(prev);
                return true;
            }
        }
        return false; // never reached
    }
    private void restore(ListNode node) {
        ListNode prev = null;
        while (node != null) {
            ListNode nextNode = node.next;
            node.next = prev;
            prev = node;
            node = nextNode;
        }
    }
}
