#include<bits/stdc++.h>
using namespace std;

const int N = 25;
const int T = 305;
int dp[N][T];
class Solution {
public:
    void work(set<int> s, int t, bool f) {
        for (auto& c : s) {

        }
    }
    bool canIWin(int N, int T) {
        set<int> s;
        for (int i = 0; i < N; i++) s.insert(i + 1);
        work(s, T, true);
    }
};