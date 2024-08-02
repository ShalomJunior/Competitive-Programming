#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        set<pair<int, int>> L, R;
        int i = 0;
        int j = n - 1;
        long long ans = 0;
        vector<bool> taken(n);
        while (k--) {
            while (L.size() < candidates && i < n) {
                if (!taken[i]) {
                    L.insert({ costs[i], i });
                }
                i++;
            }
            while (R.size() < candidates && j >= 0) {
                if (!taken[j]) {
                    R.insert({ costs[j], j });
                }
                j--;
            }
            int mn = INF;
            int p = -1;
            if (L.begin()->first != R.begin()->first) {
                if (L.begin()->first < R.begin()->first) {
                    mn = L.begin()->first;
                    p = L.begin()->second;
                }
                else {
                    mn = R.begin()->first;
                    p = R.begin()->second;
                }
            }
            else {
                mn = L.begin()->first;
                p = min(L.begin()->second, R.begin()->second);
            }
            ans += mn;
            taken[p] = true;
            L.erase({ mn, p });
            R.erase({ mn, p });
        }
        return ans;
    }
};