public class Solution {
    static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }
    public ListNode reverseKGroup(ListNode head, int k) {
        if (head == null || k == 1) return head;
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode prevGroup = dummy;
        while (true) {
            // Find the kth node from prevGroup
            ListNode kth = prevGroup;
            for (int i = 0; i < k && kth != null; ++i) kth = kth.next;
            if (kth == null) break; // less than k nodes left
            ListNode groupNext = kth.next; // node after the group
            // Reverse group
            ListNode prev = groupNext;
            ListNode cur = prevGroup.next;
            while (cur != groupNext) {
                ListNode nxt = cur.next;
                cur.next = prev;
                prev = cur;
                cur = nxt;
            }
            // Connect previous part with reversed head
            ListNode tmp = prevGroup.next; // old head becomes tail
            prevGroup.next = kth;
            prevGroup = tmp; // move to tail for next iteration
        }
        return dummy.next;
    }
}
