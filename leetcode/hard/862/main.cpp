#include<bits/stdc++.h>
#define i64 long long 
using namespace std;

template<typename T>
class sum {
public:
    int n;
    vector<T> pref;
    sum(vector<T>& arr) {
        n = arr.size();
        pref.resize(n);
        pref[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            pref[i] = pref[i - 1] + arr[i];
        }
    }
    T query(int l, int r) {
        assert(l >= 0 && r < n);
        return pref[r] - (l ? pref[l - 1] : 0);
    }
};

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<i64> a(nums.begin(), nums.end());
        sum<i64> g(a);
        auto go = [&](int mid) {
            for (int i = 0; i + mid - 1 < n; i++) {
                if (g.query(i, i + mid - 1) >= k) return true;
            }
            return false;
            };
        int L = 1, R = n;
        while (L < R) {
            int mid = (L + R) / 2;
            go(mid) ? R = mid : L = mid + 1;
        };
        return go(R) ? R : -1;
    }
};



int main() {
    Solution solution;
    vector<int> a = { 1, 2 };
    cout << solution.shortestSubarray(a, 4) << endl;;
}