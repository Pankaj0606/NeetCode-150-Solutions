/**
 * Definition for singly-linked list.
 */
public class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode reverseList(ListNode head) {
        return reverseRec(head, null);
    }
    private ListNode reverseRec(ListNode curr, ListNode prev) {
        if (curr == null) return prev;
        ListNode nxt = curr.next;
        curr.next = prev;
        return reverseRec(nxt, curr);
    }
}
