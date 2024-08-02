#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        multiset<int> ms;
        for (int i = 0; i < n; i++) {
            ms.insert(nums[i]);
            if (ms.size() == k) res.push_back(*prev(ms.end()));
            if (ms.size() == k) ms.erase(ms.find(nums[i + 1 - k]));
        }
        return res;
    }
};