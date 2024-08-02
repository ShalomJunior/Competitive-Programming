#include <bits/stdc++.h>
using namespace std;

const int N = 26;
template<typename T>
class fenwick {
public:
    vector<T> arr;
    fenwick(int n) {
        arr.resize(n + 3);
    }
    void add(int index, T val) {
        for (; index < arr.size(); index += (index & (-index))) {
            arr[index] += val;
        }
    }
    T query(int index) {
        T sum = 0;
        for (; index > 0; index -= (index & (-index))) {
            sum += arr[index];
        }
        return sum;
    }
    T rangeQuery(int left, int right) {
        return query(right) - query(left - 1);
    }
};

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<deque<int>> a(N);
    for (int i = 0; i < n; i++) {
        int j = s[i] - 'a';
        a[j].push_back(i);
    }
    string r = s;
    reverse(r.begin(), r.end());
    long long ans = 0;
    fenwick<int> fen(n);
    for (int i = 0; i < n; i++) {
        int j = r[i] - 'a';
        int id = a[j].front(); a[j].pop_front();
        int moves = i - fen.query(id);
        int new_id = id + moves;
        ans += new_id - i;
        fen.add(id + 1, 1);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
