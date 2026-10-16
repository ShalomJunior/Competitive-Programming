#include<bits/stdc++.h>
using namespace std;

const int N = 31;
const int INF = 100;

template<typename T>
class fenwick_min {
public:
    vector<T> arr;
    fenwick_min(int n) {
        arr.resize(n + 3, INF);
    }
    void add(int index, T val) {
        for (; index < arr.size(); index += (index & (-index))) {
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

template<typename T>
class fenwick_max {
public:
    vector<T> arr;
    fenwick_max(int n) {
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
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    auto b = a;
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    fenwick_max<int> fenw_max(n);
    fenwick_min<int> fenw_min(n);
    for (int i = n - 1; i >= 0; i--) {
        int cnt = __builtin_popcount(a[i]);
        int j = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
        int mn = fenw_min.query(j - 1);
        int mx = fenw_max.query(j - 1);
        if (mn == INF) {}
        else {
            if (mn != mx || mx != cnt) {
                cout << "No" << endl;
                return;
            }
        }
        fenw_min.add(j, cnt);
        fenw_max.add(j, cnt);
    }
    cout << "Yes" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}