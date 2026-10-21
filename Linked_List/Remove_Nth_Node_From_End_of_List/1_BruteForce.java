public class Solution {
    /**
     * Definition for singly‑linked list.
     */
    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    public ListNode removeNthFromEnd(ListNode head, int n) {
        // First pass: compute length
        int length = 0;
        ListNode cur = head;
        while (cur != null) {
            length++;
            cur = cur.next;
        }
        int target = length - n; // zero‑based index from start
        // Dummy node to simplify head removal
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        cur = dummy;
        for (int i = 0; i < target; i++) {
            cur = cur.next;
        }
        // Remove node
        cur.next = cur.next.next;
        return dummy.next;
    }
}
