#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(const string& s) {
        size_t left = 0;
        size_t right = s.size(); // one past the last valid index
        while (left < right) {
            // move left to next alnum
            while (left < right && !isalnum(static_cast<unsigned char>(s[left]))) ++left;
            // move right backwards to previous alnum
            while (left < right && !isalnum(static_cast<unsigned char>(s[--right]))) {}
            if (left >= right) break;
            if (tolower(static_cast<unsigned char>(s[left])) != tolower(static_cast<unsigned char>(s[right])))
                return false;
            ++left;
        }
        return true;
    }
};
