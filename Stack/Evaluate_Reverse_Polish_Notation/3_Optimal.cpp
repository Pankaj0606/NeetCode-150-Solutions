#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // Pre‑allocate an array to act as a stack.
        vector<int> stk(tokens.size());
        int top = 0; // points to next free slot
        for (const string &tok : tokens) {
            if (tok.size() == 1 && (tok[0] == '+' || tok[0] == '-' || tok[0] == '*' || tok[0] == '/')) {
                int b = stk[--top];
                int a = stk[--top];
                int res = 0;
                switch (tok[0]) {
                    case '+': res = a + b; break;
                    case '-': res = a - b; break;
                    case '*': res = a * b; break;
                    case '/': res = a / b; break; // truncates toward zero
                }
                stk[top++] = res;
            } else {
                stk[top++] = stoi(tok);
            }
        }
        return stk[0];
    }
};
