#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // Brute‑force: repeatedly find the first operator and collapse three tokens.
        while (tokens.size() > 1) {
            size_t opIdx = 0;
            // locate first operator
            for (size_t i = 0; i < tokens.size(); ++i) {
                const string &t = tokens[i];
                if (t == "+" || t == "-" || t == "*" || t == "/") {
                    opIdx = i;
                    break;
                }
            }
            // operands are at opIdx-2 and opIdx-1
            int a = stoi(tokens[opIdx - 2]);
            int b = stoi(tokens[opIdx - 1]);
            int res = 0;
            const string &op = tokens[opIdx];
            if (op == "+") res = a + b;
            else if (op == "-") res = a - b;
            else if (op == "*") res = a * b;
            else if (op == "/") res = a / b; // truncates toward zero
            // replace the three tokens with the result string
            tokens[opIdx - 2] = to_string(res);
            // erase the two tokens that are now obsolete
            tokens.erase(tokens.begin() + opIdx - 1, tokens.begin() + opIdx + 1);
        }
        return stoi(tokens[0]);
    }
};
