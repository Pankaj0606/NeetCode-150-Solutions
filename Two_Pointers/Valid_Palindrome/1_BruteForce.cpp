#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string filtered;
        for (char c : s) {
            if (isalnum(static_cast<unsigned char>(c)))
                filtered += static_cast<char>(tolower(static_cast<unsigned char>(c)));
        }
        string rev = filtered;
        reverse(rev.begin(), rev.end());
        return filtered == rev;
    }
};
