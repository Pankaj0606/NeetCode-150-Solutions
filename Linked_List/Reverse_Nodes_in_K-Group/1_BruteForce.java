public class Solution {
    static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }
    public ListNode reverseKGroup(ListNode head, int k) {
        if (head == null || k == 1) return head;
        java.util.ArrayList<ListNode> nodes = new java.util.ArrayList<>();
        for (ListNode cur = head; cur != null; cur = cur.next) {
            nodes.add(cur);
        }
        int n = nodes.size();
        for (int i = 0; i + k <= n; i += k) {
            // reverse the sub‑list in the array view
            for (int l = i, r = i + k - 1; l < r; ++l, --r) {
                ListNode tmp = nodes.get(l);
                nodes.set(l, nodes.get(r));
                nodes.set(r, tmp);
            }
        }
        // re‑link according to new order
        for (int i = 0; i < n - 1; ++i) {
            nodes.get(i).next = nodes.get(i + 1);
        }
        nodes.get(n - 1).next = null;
        return nodes.get(0);
    }
}
