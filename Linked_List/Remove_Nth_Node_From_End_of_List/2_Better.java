public class Solution {
    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    public ListNode removeNthFromEnd(ListNode head, int n) {
        java.util.Stack<ListNode> stack = new java.util.Stack<>();
        ListNode cur = head;
        while (cur != null) {
            stack.push(cur);
            cur = cur.next;
        }
        // Pop n nodes to reach predecessor
        for (int i = 0; i < n; i++) {
            if (!stack.isEmpty()) stack.pop();
        }
        // If stack empty, delete head
        if (stack.isEmpty()) {
            return head.next;
        }
        ListNode prev = stack.peek();
        prev.next = prev.next.next;
        return head;
    }
}
