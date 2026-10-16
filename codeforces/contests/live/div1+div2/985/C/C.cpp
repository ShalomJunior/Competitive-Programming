#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 2);
    vector<int> s(n + 2);
    vector<int> mx(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1];
        if (a[i] < s[i - 1]) s[i]--;
        else if (a[i] > s[i - 1]) s[i]++;
        mx[i] = max(mx[i - 1], s[i]);
    }
    auto check = [&](int mid) {
        int need = mid;
        for (int i = n + 1; i > 1; i--) {
            if (i <= n) {
                if (a[i] >= need) need--;
                else if (a[i] < need) need++;
            }
            if (mx[i - 2] >= need)
                return true;
        }
        return false;
        };
    int L = 0, R = n;
    while (L < R) {
        int mid = (L + R) / 2;
        if (check(mid)) {
            if (L == mid) check(R) ? L = R : R = L;
            else L = mid;
        }
        else R = mid - 1;
    }
    cout << L << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}



/*


#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 2);
    vector<int> s(n + 2);
    vector<int> mx(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1];
        if (a[i] < s[i - 1]) s[i]--;
        else if (a[i] > s[i - 1]) s[i]++;
        mx[i] = max(mx[i - 1], s[i]);
        cerr << s[i] << " ";
    }
    cerr << endl;
    auto check = [&](int mid) {
        cerr << "mid = " << mid << endl;
        int need = mid;
        for (int i = n + 1; i > 1; i--) {
            if (i <= n) {
                if (a[i] >= need) need--;
                else if (a[i] < need) need++;
            }
            if (mx[i - 2] >= need) {
                cerr << i - 2 << " " << mx[i - 2] << " " << need << endl;
                return true;

            }
        }
        cerr << "false" << endl;
        return false;
        };
    int L = 0, R = n;
    while (L < R) {
        cerr << L << " -> " << R << endl;
        int mid = (L + R) / 2;
        if (check(mid)) {
            if (L == mid) check(R) ? L = R : R = L;
            else L = mid;
        }
        else R = mid - 1;
        cerr << endl;
    }
    cout << "ans " << L << endl;
    cerr << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
*/