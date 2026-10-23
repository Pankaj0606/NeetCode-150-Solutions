import java.util.*;

/** Definition for singly‑linked list. */
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

class Solution {
    // Brute‑force: convert to strings, add as big integers, rebuild list
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        StringBuilder sb1 = new StringBuilder();
        StringBuilder sb2 = new StringBuilder();
        while (l1 != null) { sb1.append(l1.val); l1 = l1.next; }
        while (l2 != null) { sb2.append(l2.val); l2 = l2.next; }
        sb1.reverse();
        sb2.reverse();
        String s1 = sb1.toString();
        String s2 = sb2.toString();
        StringBuilder res = new StringBuilder();
        int i = s1.length() - 1, j = s2.length() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry != 0) {
            int sum = carry;
            if (i >= 0) sum += s1.charAt(i--) - '0';
            if (j >= 0) sum += s2.charAt(j--) - '0';
            res.append((char)('0' + (sum % 10)));
            carry = sum / 10;
        }
        // res now holds digits in reverse order (least‑significant first)
        ListNode dummy = new ListNode(0);
        ListNode cur = dummy;
        for (int k = 0; k < res.length(); k++) {
            cur.next = new ListNode(res.charAt(k) - '0');
            cur = cur.next;
        }
        return dummy.next;
    }
}
