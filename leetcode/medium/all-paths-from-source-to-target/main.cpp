#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<vector<int>> ans;
        function<void(int, vector<int>&)> dfs = [&](int r, vector<int>& O) {
            O.push_back(r);
            if (r == n - 1) {
                ans.push_back(O);
            }
            else {
                for (auto& c : adj[r]) {
                    dfs(c, O);
                }
            }
            O.pop_back();
            };
        vector<int> O;
        dfs(0, O);
        return ans;
    }
};