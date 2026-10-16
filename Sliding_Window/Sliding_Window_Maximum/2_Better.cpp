class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        priority_queue<pair<int,int>> pq; // max-heap by value
        for (int i = 0; i < n; ++i) {
            pq.emplace(nums[i], i);
            if (i >= k - 1) {
                while (!pq.empty() && pq.top().second <= i - k) pq.pop();
                res.push_back(pq.top().first);
            }
        }
        return res;
    }
};
