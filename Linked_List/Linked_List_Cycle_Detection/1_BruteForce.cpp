#include <unordered_set>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        std::unordered_set<ListNode*> visited;
        while (head) {
            if (visited.find(head) != visited.end())
                return true;
            visited.insert(head);
            head = head->next;
        }
        return false;
    }
};
