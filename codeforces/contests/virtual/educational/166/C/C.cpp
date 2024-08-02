#include <bits/stdc++.h>
#define int long long
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
    int n, m;
    cin >> n >> m;
    int N = n + m + 1;
    vector<int> a(N + 1), b(N + 1);
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= N; i++) cin >> b[i];
    fenwick<int> A(N), B(N);
    fenwick<int> X(N), Y(N);
    fenwick<int> SX(N), SY(N);
    for (int i = 1; i <= N; i++) {
        a[i] > b[i] ? A.add(i, 1) : B.add(i, 1);
        a[i] > b[i] ? X.add(i, a[i]) : Y.add(i, b[i]);
        a[i] > b[i] ? SX.add(i, a[i] + b[i]) : SY.add(i, a[i] + b[i]);
    }
    int P = accumulate(a.begin(), a.end(), 0LL);
    int T = accumulate(b.begin(), b.end(), 0LL);
    for (int i = 1; i <= N; i++) {
        a[i] > b[i] ? A.add(i, -1) : B.add(i, -1);
        a[i] > b[i] ? X.add(i, -a[i]) : Y.add(i, -b[i]);
        a[i] > b[i] ? SX.add(i, -(a[i] + b[i])) : SY.add(i, -(a[i] + b[i]));
        int L = 0, R = N;
        while (L < R) {
            int mid = (L + R) / 2;
            int x = A.query(mid + 1);
            int y = B.query(mid + 1);
            (x >= n || y >= m) ? R = mid : L = mid + 1;
        }
        if (A.query(R + 1) == n) {
            int sa = X.query(R + 1);
            int sb = T - (SX.query(R + 1) - sa);
            sb -= b[i];
            cout << sa + sb << " ";
        }
        else {
            int sb = Y.query(R + 1);
            int sa = P - (SY.query(R + 1) - sb);
            sa -= a[i];
            cout << sa + sb << " ";
        }
        a[i] > b[i] ? A.add(i + 1, 1) : B.add(i + 1, 1);
        a[i] > b[i] ? X.add(i + 1, a[i]) : Y.add(i + 1, b[i]);
        a[i] > b[i] ? SX.add(i + 1, a[i] + b[i]) : SY.add(i + 1, a[i] + b[i]);
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}




// #include <bits/stdc++.h>
// #define int long long
// using namespace std;

// template<typename T>
// class fenwick {
// public:
//     vector<T> arr;
//     fenwick(int n) {
//         arr.resize(n + 3);
//     }
//     void add(int index, T val) {
//         for (; index < arr.size(); index += (index & (-index))) {
//             arr[index] += val;
//         }
//     }
//     T query(int index) {
//         T sum = 0;
//         for (; index > 0; index -= (index & (-index))) {
//             sum += arr[index];
//         }
//         return sum;
//     }
//     T rangeQuery(int left, int right) {
//         return query(right) - query(left - 1);
//     }
// };

// void solve() {
//     int n, m;
//     cin >> n >> m;
//     int N = n + m + 1;
//     vector<int> a(N + 1), b(N + 1);
//     for (int i = 1; i <= N; i++) cin >> a[i];
//     for (int i = 1; i <= N; i++) cin >> b[i];
//     fenwick<int> A(N), B(N);
//     fenwick<int> X(N), Y(N);
//     fenwick<int> SX(N), SY(N);
//     for (int i = 1; i <= N; i++) {
//         a[i] > b[i] ? A.add(i, 1) : B.add(i, 1);
//         a[i] > b[i] ? X.add(i, a[i]) : Y.add(i, b[i]);
//         a[i] > b[i] ? SX.add(i, a[i] + b[i]) : SY.add(i, a[i] + b[i]);
//     }
//     int P = accumulate(a.begin(), a.end(), 0LL);
//     int T = accumulate(b.begin(), b.end(), 0LL);
//     for (int i = 1; i <= N; i++) {
//         //cerr << "i = " << i << endl;
//         a[i] > b[i] ? A.add(i, -1) : B.add(i, -1);
//         a[i] > b[i] ? X.add(i, -a[i]) : Y.add(i, -b[i]);
//         a[i] > b[i] ? SX.add(i, -(a[i] + b[i])) : SY.add(i, -(a[i] + b[i]));
//         // assert(X.rangeQuery(i, i) == 0);
//         // assert(Y.rangeQuery(i, i) == 0);
//         // assert(A.rangeQuery(i, i) == 0);
//         // assert(B.rangeQuery(i, i) == 0);

//         int L = 0, R = N;
//         while (L < R) {
//             int mid = (L + R) / 2;
//             int x = A.query(mid + 1);
//             int y = B.query(mid + 1);
//             (x >= n || y >= m) ? R = mid : L = mid + 1;
//         }
//         cerr << "r = " << R << endl;
//         if (A.query(R + 1) == n) {
//             int sa = X.query(R + 1);
//             int sb = T - (SX.query(R + 1) - sa);
//             sb -= b[i];
//             //cerr << Y.query(N + 1) << endl;
//             cerr << sa << " # " << sb << endl;
//             //cout << sa + sb << " ";
//         }
//         else {
//             int sb = Y.query(R + 1);
//             int sa = P - (SY.query(R + 1) - sb);
//             sa -= a[i];
//             //cerr << X.query(N) << endl;
//             cerr << SY.query(R + 1) << endl;
//             cerr << sa << " -> " << sb << endl;

//             //cout << sa + sb << " ";
//         }
//         a[i] > b[i] ? A.add(i + 1, 1) : B.add(i + 1, 1);
//         a[i] > b[i] ? X.add(i + 1, a[i]) : Y.add(i + 1, b[i]);
//         a[i] > b[i] ? SX.add(i + 1, a[i] + b[i]) : SY.add(i + 1, a[i] + b[i]);
//     }
//     cout << endl;
//     cerr << endl;
// }

// signed main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t; cin >> t;
//     while (t--) solve();
// }