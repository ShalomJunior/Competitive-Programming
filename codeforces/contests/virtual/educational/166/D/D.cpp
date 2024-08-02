#include <bits/stdc++.h>
using namespace std;

template<typename T>
const T& Max(const T& a, const T& b) {
    return max(a, b);
}

template<typename T, const T& (*op)(const T&, const T&)>
class sparseTable {
public:
    vector<vector<T>> st;
    sparseTable(vector<T> vals) {
        int n = vals.size();
        int rows = __lg(n) + 1;
        st.resize(rows);
        st[0] = vals;
        for (int j = 1; j < rows; j++) {
            st[j].resize(n);
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[j][i] = op(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
    T query(int l, int r) {
        int j = __lg(r - l + 1);
        return op(st[j][l], st[j][r - (1 << j) + 1]);
    }
};

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> x(n);
    vector<int> X(n);
    map<int, vector<int>> ids;
    for (int i = 0; i < n; ++i) {
        x[i] = (s[i] == '(' ? 1 : -1);
        X[i] = (i ? X[i - 1] : 0) + x[i];
        ids[X[i]].push_back(i);
    }
    sparseTable<int, Max> g(X);
    long long ans = 0;
    map<int, int> h;
    for (int i = 0; i < n - 1; i++) {
        int cnt = i ? X[i - 1] : 0;
        if (cnt > 0) {
            auto vec = ids[cnt];
            int m = vec.size();
            int L = ++h[cnt], R = m - 1;
            if (L >= m) continue;
            while (L < R) {
                int mid = (L + R) / 2;
                if (g.query(i, vec[mid]) - cnt <= cnt) {
                    if (L == mid) g.query(i, vec[R]) - cnt <= cnt ? L = R : R = L;
                    else L = mid;
                }
                else R = mid - 1;
            }
            if (g.query(i, vec[L]) - cnt <= cnt) {
                ans += L - h[cnt] + 1;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}


/*
#include <bits/stdc++.h>
using namespace std;

template<typename T>
const T& Max(const T& a, const T& b) {
    return max(a, b);
}

template<typename T, const T& (*op)(const T&, const T&)>
class sparseTable {
public:
    vector<vector<T>> st;
    sparseTable(vector<T> vals) {
        int n = vals.size();
        int rows = __lg(n) + 1;
        st.resize(rows);
        st[0] = vals;
        for (int j = 1; j < rows; j++) {
            st[j].resize(n);
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[j][i] = op(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
    T query(int l, int r) {
        int j = __lg(r - l + 1);
        return op(st[j][l], st[j][r - (1 << j) + 1]);
    }
};

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> x(n);
    vector<int> y(n);
    vector<int> X(n);
    vector<int> Y(n);
    map<int, vector<int>> ids;
    for (int i = 0; i < n; ++i) {
        x[i] = (s[i] == '(' ? 1 : -1);
        X[i] = (i ? X[i - 1] : 0) + x[i];
        ids[X[i]].push_back(i);
    }
    sparseTable<int, Max> g(X);
    long long ans = 0;
    map<int, int> h;
    for (int i = 0; i < n - 1; i++) {
        int cnt = i ? X[i - 1] : 0;
        if (cnt > 0) {
            auto vec = ids[cnt];
            int m = vec.size();
            cerr << "m = " << m << endl;
            int L = ++h[cnt], R = m - 1;
            cerr << "L = " << L << endl;
            if (L >= m) continue;
            cerr << vec[L] << endl;
            cerr << "i = " << i << endl;
            while (L < R) {
                int mid = (L + R) / 2;
                cerr << "mid = " << mid << endl;
                cerr << i << endl;
                cerr << vec[mid] << endl;
                if (g.query(i, vec[mid]) - cnt <= cnt) {
                    if (L == mid) g.query(i, vec[R]) - cnt <= cnt ? L = R : R = L;
                    else L = mid;
                }
                else R = mid - 1;
            }
            cerr << h[cnt] << " " << L << endl;
            cerr << "b  = " << cnt << endl;
            if (g.query(i, vec[L]) - cnt <= cnt) {
                cerr << g.query(i, vec[L]) - cnt << " " << cnt << endl;
                cerr << "in" << endl;
                ans += L - h[cnt] + 1;
            }
        }
    }
    cout << "#" << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}*/