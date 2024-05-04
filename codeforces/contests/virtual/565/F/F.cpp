#include <bits/stdc++.h>
#define Mine pair<int,int>
#define F first
#define S second
using namespace std;

const int INF = 1e9;
void solve() {
    int n; cin >> n;
    map<int, int> h;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        h[x]++;
    }
    vector<Mine> vec;
    for (auto& [k, cnt] : h) {
        vec.push_back({ k, cnt });
    }
    int m = vec.size();
    int cnt = vec[0].S, start = 0;
    for (int i = 1, curr = cnt, id = 0; i < m; i++) {
        if (vec[i].F == 1 + vec[i - 1].F) curr += vec[i].S;
        if (vec[i].F != 1 + vec[i - 1].F || vec[i].S == 1 || i == n - 1) {
            if (curr > cnt) {
                cnt = curr;
                start = id;
            }
            curr = vec[i].S;
            id = i;
        }
    }
    cout << cnt << endl;
    multiset<int> ms;
    for (int i = start, one = vec[start].S == 1 ? 2 : 1; i < m; i++) {
        if (i != start && vec[i].F != vec[i - 1].F + 1) break;
        if (vec[i].S == 1) one--;
        while (vec[i].S--) {
            ms.insert(vec[i].F);
        }
        if (!one) break;
    }
    set<int> s(ms.begin(), ms.end());
    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << *it << " ";
        ms.erase(ms.find(*it));
    }
    while (!ms.empty()) {
        cout << *prev(ms.end()) << " ";
        ms.erase(prev(ms.end()));
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}