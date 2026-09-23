#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        const string pairs[3] = {"()", "{}", "[]"};
        bool changed = true;
        while (changed) {
            changed = false;
            for (const string &p : pairs) {
                size_t pos = s.find(p);
                if (pos != string::npos) {
                    s.erase(pos, 2);
                    changed = true;
                }
            }
        }
        return s.empty();
    }
};
