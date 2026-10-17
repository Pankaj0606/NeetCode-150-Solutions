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
        if (head == null) return null;
        java.util.List<ListNode> nodes = new java.util.ArrayList<>();
        for (ListNode cur = head; cur != null; cur = cur.next) {
            nodes.add(cur);
        }
        for (int i = nodes.size() - 1; i > 0; --i) {
            nodes.get(i).next = nodes.get(i - 1);
        }
        nodes.get(0).next = null;
        return nodes.get(nodes.size() - 1);
    }
}
