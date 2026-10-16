#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    deque<int> bounder, center;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        if (i < x || i >= y) bounder.push_back(val);
        else center.push_back(val);
    }
    int mn = center.empty() ? INF : *min_element(center.begin(), center.end());
    while (!center.empty() && center.front() != mn) {
        center.push_back(center.front());
        center.pop_front();
    }
    while (!bounder.empty() && bounder.front() < mn) {
        cout << bounder.front() << " ";
        bounder.pop_front();
    }
    for (auto& c : center) cout << c << " ";
    while (!bounder.empty()) {
        cout << bounder.front() << " ";
        bounder.pop_front();
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}