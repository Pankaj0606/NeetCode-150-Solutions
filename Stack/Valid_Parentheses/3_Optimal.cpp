#include <string>
using namespace std;

class Solution {
public:
    bool isValid(const string &s) {
        char stackArr[10000]; // assuming input length <= 10000; can use s.size()
        int top = -1;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stackArr[++top] = c;
            } else {
                if (top < 0) return false;
                char open = stackArr[top--];
                if ((c == ')' && open != '(') ||
                    (c == '}' && open != '{') ||
                    (c == ']' && open != '[')) {
                    return false;
                }
            }
        }
        return top == -1;
    }
};
