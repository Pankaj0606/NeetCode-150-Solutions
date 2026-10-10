#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        // Ensure A is the smaller array
        if (A.size() > B.size()) return findMedianSortedArrays(B, A);
        int m = A.size();
        int n = B.size();
        int totalLeft = (m + n + 1) / 2; // number of elements in left partition
        int lo = 0, hi = m;
        while (lo <= hi) {
            int i = lo + (hi - lo) / 2; // partition A
            int j = totalLeft - i;      // partition B
            int Aleft = (i == 0) ? INT_MIN : A[i-1];
            int Aright = (i == m) ? INT_MAX : A[i];
            int Bleft = (j == 0) ? INT_MIN : B[j-1];
            int Bright = (j == n) ? INT_MAX : B[j];
            if (Aleft <= Bright && Bleft <= Aright) {
                // Correct partition
                if ((m + n) % 2 == 1) {
                    return double(max(Aleft, Bleft));
                } else {
                    return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
                }
            } else if (Aleft > Bright) {
                // Move left in A
                hi = i - 1;
            } else {
                // Move right in A
                lo = i + 1;
            }
        }
        throw runtime_error("Logic error – should never reach here");
    }
};
