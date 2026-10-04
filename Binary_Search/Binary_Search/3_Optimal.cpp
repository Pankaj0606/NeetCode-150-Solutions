#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, static_cast<int>(nums.size()) - 1);
    }
private:
    int binarySearch(const vector<int>& nums, int target, int lo, int hi) {
        if (lo > hi) return -1;
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] < target) return binarySearch(nums, target, mid + 1, hi);
        return binarySearch(nums, target, lo, mid - 1);
    }
};
