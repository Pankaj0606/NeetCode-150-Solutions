import java.util.*;
class ListNode {
    int val;
    ListNode next;
    ListNode(int val) { this.val = val; }
}
class Solution {
    public void reorderList(ListNode head) {
        if (head == null) return;
        Deque<ListNode> stack = new ArrayDeque<>();
        for (ListNode cur = head; cur != null; cur = cur.next) {
            stack.push(cur);
        }
        int n = stack.size();
        ListNode cur = head;
        for (int i = 0; i < n / 2; i++) {
            ListNode top = stack.pop();
            ListNode nxt = cur.next;
            cur.next = top;
            top.next = nxt;
            cur = nxt;
        }
        cur.next = null; // terminate
    }
}
