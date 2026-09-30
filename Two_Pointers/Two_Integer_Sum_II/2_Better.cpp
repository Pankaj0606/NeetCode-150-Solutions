#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> idx;
        for (int i = 0; i < (int)numbers.size(); ++i) {
            int complement = target - numbers[i];
            if (idx.count(complement)) {
                return {idx[complement] + 1, i + 1};
            }
            idx[numbers[i]] = i;
        }
        return {};
    }
};
