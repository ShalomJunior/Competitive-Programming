#include <bits/stdc++.h>
using namespace std;

void merge(vector <pair<int, int>>& x) {
    int n = x.size();
    if (n == 0) return;
    sort(x.begin(), x.end());
    vector<pair<int, int>> temp;
    int l = x[0].first;
    int r = x[0].second;
    for (int i = 1; i < n; i++) {
        if (x[i].first > r) {
            temp.push_back({ l, r });
            l = x[i].first;
            r = x[i].second;
        }
        else {
            r = max(r, x[i].second);
        }
    }
    temp.push_back({ l, r });
    x = temp;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> g(n);
    vector<int> p;
    for (auto& [l, r] : g) {
        cin >> l >> r;
        p.push_back(l);
        p.push_back(r);
    }
    sort(g.begin(), g.end());
    sort(p.begin(), p.end());
    p.resize(unique(p.begin(), p.end()) - p.begin());
    int m = p.size();
    vector<int> cnt(m);
    vector<bool> b(m);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0, j = 0; i < m; i++) {
        while (!pq.empty() && pq.top() < p[i]) pq.pop();
        b[i] = i ? pq.size() >= k : true;
        while (j < n && g[j].first <= p[i]) pq.push(g[j++].second);
        cnt[i] = pq.size();
    }
    int mx = *max_element(cnt.begin(), cnt.end());
    vector<pair<int, int>> res;
    bool active = false;
    int l, r;
    for (int i = 0; i < m; i++) {
        if (cnt[i] >= k) {
            if (active) {
                if (b[i]) r = i;
                else {
                    res.push_back({ p[l], p[r] });
                    l = r = i;
                }
            }
            else {
                l = r = i;
                active = true;
            }
        }
        else {
            if (active) res.push_back({ p[l], p[r] });
            active = false;
        }
    }
    if (active) res.push_back({ p[l], p[r] });
    merge(res);
    cout << res.size() << endl;
    for (auto& [x, y] : res) cout << x << " " << y << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}


/*
#include <bits/stdc++.h>
using namespace std;

template<typename T>
class fenwick {
public:
    vector<T> arr;
    fenwick(int n) {
        arr.resize(n + 3);
    }
    void add(int index, T val) {
        for (; index < arr.size(); index += (index & (-index))) {
            arr[index] = max(arr[index], val);
        }
    }
    T query(int index) {
        T sum = 0;
        for (; index > 0; index -= (index & (-index))) {
            sum = max(sum, arr[index]);
        }
        return sum;
    }
    T rangeQuery(int left, int right) {
        return query(right) - query(left - 1);
    }
};

void merge(vector <pair<int, int>>& x) {
    int n = x.size();
    if (n == 0) return;
    sort(x.begin(), x.end());
    vector<pair<int, int>> temp;
    int l = x[0].first;
    int r = x[0].second;
    for (int i = 1; i < n; i++) {
        if (x[i].first > r) {
            temp.push_back({ l, r });
            l = x[i].first;
            r = x[i].second;
        }
        else {
            r = max(r, x[i].second);
        }
    }
    temp.push_back({ l, r });
    x = temp;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> g(n);
    vector<int> p;
    for (auto& [l, r] : g) {
        cin >> l >> r;
        p.push_back(l);
        p.push_back(r);
    }
    sort(g.begin(), g.end());
    sort(p.begin(), p.end());
    p.resize(unique(p.begin(), p.end()) - p.begin());
    int m = p.size();
    vector<int> cnt(m);
    vector<bool> b(m);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0, j = 0; i < m; i++) {
        while (!pq.empty() && pq.top() < p[i]) pq.pop();
        b[i] = i ? pq.size() >= k : true;
        while (j < n && g[j].first <= p[i]) pq.push(g[j++].second);
        cnt[i] = pq.size();
        cerr << cnt[i] << " ";
    }
    cerr << endl;
    for (int i = 0; i < m; i++) cerr << (b[i] ? 1 : 0) << " ";
    fenwick<int> fen(m);
    for (auto& [l, r] : g) {
        int i = lower_bound(p.begin(), p.end(), l) - p.begin() + 1;
        int j = lower_bound(p.begin(), p.end(), r) - p.begin() + 1;
        fen.add(i, j);
    }
    cerr << endl;
    int mx = *max_element(cnt.begin(), cnt.end());
    vector<pair<int, int>> res;
    bool active = false;
    int l, r;
    for (int i = 0; i < m; i++) {
        if (cnt[i] >= k) {
            cerr << "fuck" << endl;
            if (active) {
                cerr << "in" << endl;
                cerr << fen.query(l + 1) << " " << i + 1 << endl;
                if (b[i]) r = i;
                else {
                    cerr << "hell" << endl;
                    cerr << p[l] << " " << p[r] << endl;
                    res.push_back({ p[l], p[r] });
                    l = r = i;
                }
            }
            else {
                l = r = i;
                active = true;
            }
        }
        else {
            if (active) res.push_back({ p[l], p[r] });
            active = false;
        }
    }
    if (active) res.push_back({ p[l], p[r] });
    merge(res);
    cout << res.size() << endl;
    for (auto& [x, y] : res) cout << x << " " << y << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}

*/
