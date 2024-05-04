#include <bits/stdc++.h>
using namespace std;

const int N = 26;
const int INF = 1e9;

char q1(int i) {
    cout << "? 1 " << i << endl;
    cout.flush();
    char x; cin >> x;
    return x;
}

int q2(int l, int r) {
    cout << "? 2 " << l << " " << r << endl;
    cout.flush();
    int x; cin >> x;
    return x;
}

void solve() {
    int n;
    cin >> n;
    vector<int> p(N, n + 1);
    vector<char> s(n + 1);
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++) {
        cnt[i] = q2(1, i);
        if (cnt[i - 1] < cnt[i]) {
            s[i] = q1(i);
        }
        else {
            vector<pair<int, char>> vec;
            for (int j = 0; j < N; j++) {
                if (p[j] != n + 1) {
                    vec.push_back({ p[j], 'a' + j });
                }
            }
            sort(vec.begin(), vec.end());
            int m = vec.size();
            int L = 0, R = m - 1;
            while (L + 1 < R) {
                int mid = (L + R) / 2;
                int x = m - mid + 1;
                q2(vec[mid].first, i) == x ? R = mid - 1 : L = mid;
            }
            if (L < R) {
                q2(vec[R].first, i) == (m - R + 1) ? R = L : L = R;
            }
            s[i] = vec[L].second;
        }
        p[s[i] - 'a'] = i;
    }
    cout << "! ";
    for (int i = 1; i <= n; i++)cout << s[i];
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
//guess
//1 234


/*

#include <bits/stdc++.h>
using namespace std;

const int N = 26;
const int INF = 1e9;

char q1(int i) {
    cout << "? 1 " << i << endl;
    cout.flush();
    char x; cin >> x;
    return x;
}

int q2(int l, int r) {
    cout << "? 2 " << l << " " << r << endl;
    cout.flush();
    int x; cin >> x;
    return x;
}

void solve() {
    int n;
    cin >> n;
    vector<int> p(N, n + 1);
    vector<char> s(n + 1);
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++) {
        cnt[i] = q2(1, i);
        cerr << cnt[i - 1] << " " << cnt[i] << endl;
        if (cnt[i - 1] < cnt[i]) {
            cerr << "-> " << endl;
            s[i] = q1(i);
        }
        else {
            cerr << "|| " << endl;
            vector<pair<int, char>> vec;
            for (int j = 0; j < N; j++) {
                if (p[j] != n + 1) {
                    vec.push_back({ p[j], 'a' + j });
                }
            }
            sort(vec.begin(), vec.end());
            int m = vec.size();
            assert(m <= N);
            int use = 0;
            cerr << "m = " << m << endl;
            int L = 0, R = m - 1;
            while (L < R) {
                cerr << L << " " << R << endl;
                int mid = (L + R) / 2;
                cerr << "mid = " << mid << endl;
                int x = m - mid + 1;
                //cerr << "q2 " << q2(mid, i) << " " << x << endl;
                q2(vec[mid].first, i) == x ? R = mid - 1 : L = mid;

                if (q2(vec[mid].first, i) == x) R = mid - 1, use++;
                else {
                    cerr << "#" << endl;
                    if (L == mid) q2(vec[R].first, i) == (m - R + 1) ? R = L : L = R, use++;
                    else L = mid;
                }
            }
            cerr << "end " << endl;
            cerr << L << endl;
            s[i] = vec[L].second;
            assert(use <= 5);
        }
        p[s[i] - 'a'] = i;
    }
    cout << "! ";
    for (int i = 1; i <= n; i++)cout << s[i];
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}*/