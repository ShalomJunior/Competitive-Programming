#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
set<char> vowels = { 'a', 'e', 'i', 'o','u' };

template<typename T>
class fenwick {
public:
    vector<T> arr;
    fenwick(int n) {
        arr.resize(n + 5, INF);
    }
    void add(int index, T val) {
        for (; index < (int)arr.size(); index += (index & (-index))) {
            arr[index] = min(arr[index], val);
        }
    }
    T query(int index) {
        T sum = INF;
        for (; index > 0; index -= (index & (-index))) {
            sum = min(sum, arr[index]);
        }
        return sum;
    }
};

void solve() {
    string s;
    cin >> s;
    for (auto& c : s) c = tolower(c);
    int n = s.length();
    s = "#" + s;
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + (vowels.count(s[i]) ? -1 : 2);
    }
    vector<int> all = pref;
    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());
    int len = 0;
    fenwick<int> fen(n);
    fen.add(lower_bound(all.begin(), all.end(), 0) - all.begin() + 1, 0);
    for (int i = 1; i <= n; i++) {
        int j = lower_bound(all.begin(), all.end(), pref[i]) - all.begin() + 1;
        int l = fen.query(j);
        if (l != INF) len = max(len, i - l);
        fen.add(j, i);
    }
    int cnt = 0;
    for (int i = len; i <= n; i++) {
        if (pref[i] - pref[i - len] >= 0) cnt++;
    }
    if (len) {
        cout << len << " " << cnt;
    }
    else {
        cout << "No solution";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}