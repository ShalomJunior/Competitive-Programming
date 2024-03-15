#include <bits/stdc++.h>
using namespace std;

long long get(vector<int> boxes) {
    int n = boxes.size();
    sort(boxes.begin(), boxes.end());
    long long tot = accumulate(boxes.begin(), boxes.end(), 0LL);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = tot / n + (i < n - tot % n ? 0 : 1);
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (boxes[i] > b[i]) ans += boxes[i] - b[i];
    }
    return ans;
}

long long get2(vector<int> rewards) {
    int n = rewards.size();
    sort(rewards.rbegin(), rewards.rend());
    multiset<int> ms(rewards.begin(), rewards.end());
    long long ans = 0;
    for (int i = 0; !ms.empty(); i++) {
        ans += *prev(ms.end()) - i;
        ms.erase(prev(ms.end()));
        while (!ms.empty() && *ms.begin() <= i + 1) {
            ms.erase(ms.begin());
        }
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;

    cout << get2(a) << endl;
}

int main() {
    solve();
}

/*

2 4 1
1
4 4 4 4 4
0
*/