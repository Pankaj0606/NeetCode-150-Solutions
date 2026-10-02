#include <bits/stdc++.h>\nusing namespace std;\n\nclass Solution {\npublic:\n    int maxArea(vector<int>& height) {\n        int n = height.size();\n        // Pair each height with its index
        vector<pair<int,int>> vec;\n        vec.reserve(n);\n        for (int i = 0; i < n; ++i) vec.emplace_back(height[i], i);\n        // Sort descending by height
        sort(vec.begin(), vec.end(), [](const auto& a, const auto& b){ return a.first > b.first; });\n        int minIdx = vec[0].second;\n        int maxIdx = vec[0].second;\n        int ans = 0;\n        for (size_t k = 1; k < vec.size(); ++k) {\n            int h = vec[k].first;\n            int idx = vec[k].second;\n            // Current best width using any taller line seen so far
            ans = max(ans, h * max(abs(idx - minIdx), abs(idx - maxIdx)));\n            // Update extremes
            minIdx = min(minIdx, idx);\n            maxIdx = max(maxIdx, idx);\n        }\n        return ans;\n    }\n};
