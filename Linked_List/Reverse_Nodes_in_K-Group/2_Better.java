public class Solution {
    static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }
    // Reverse exactly k nodes and return new head
    private ListNode reverseK(ListNode head, int k) {
        ListNode prev = null;
        ListNode cur = head;
        while (k-- > 0 && cur != null) {
            ListNode nxt = cur.next;
            cur.next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev; // new head of the reversed segment
    }
    public ListNode reverseKGroup(ListNode head, int k) {
        if (head == null || k == 1) return head;
        // Check if there are at least k nodes left
        ListNode ptr = head;
        for (int i = 0; i < k; ++i) {
            if (ptr == null) return head; // not enough nodes
            ptr = ptr.next;
        }
        // Reverse first k nodes
        ListNode newHead = reverseK(head, k);
        // head is now the tail of the reversed segment
        head.next = reverseKGroup(ptr, k);
        return newHead;
    }
}
