import java.util.*;
class Solution {
    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        List<Integer> vals = new ArrayList<>();
        while (l1 != null) {
            vals.add(l1.val);
            l1 = l1.next;
        }
        while (l2 != null) {
            vals.add(l2.val);
            l2 = l2.next;
        }
        Collections.sort(vals);
        ListNode dummy = new ListNode(0);
        ListNode cur = dummy;
        for (int v : vals) {
            cur.next = new ListNode(v);
            cur = cur.next;
        }
        return dummy.next;
    }
}
