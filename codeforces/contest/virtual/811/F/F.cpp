#include <bits/stdc++.h>
using namespace std;

int n, a, b, c;
int is(int len, int x, int y) {
    int ans = 0;
    for (int i = 1; i < x; i++) {
        int deep = x - i;
        if (len - i + deep == y && len + 1 + deep <= n) { ans = i; break; }
    }
    return ans;
}

void f(int start, int mid, int end, int len, int place) {
    cout << "YES" << endl;
    int last = start, q = 4;
    for (int i = 1; i < len; i++) {
        cout << last << " " << ((i == place) ? mid : q) << endl;
        last = ((i == place) ? mid : q++);
    }
    cout << last << " " << end << endl;
    while (q <= n) cout << start << " " << q++ << endl;
}

void g(int start, int mid, int end, int len, int place, int deep) {
    cout << "YES" << endl;
    int last = start, q = 4;
    for (int i = 1; i < len; i++) {
        cout << last << " " << q << endl;
        last = q++;
        if (i == place) {
            int temp = last;
            for (int j = 1; j < deep; j++) {
                cout << temp << " " << q << endl;
                temp = q++;
            }
            cout << temp << " " << mid << endl;
        }
    }
    cout << last << " " << end << endl;
    while (q <= n) cout << start << " " << q++ << endl;
}

void solve() {
    cin >> n >> a >> b >> c;
    int M = max({ a,b,c });
    if (M == a) {
        if (a == b + c) f(1, 3, 2, a, c);
        else {
            int place = is(a, c, b);
            if (place) g(1, 3, 2, a, place, c - place);
            else cout << "NO" << endl;;
        }
    }
    else if (M == b) {
        if (b == a + c) f(2, 1, 3, b, a);
        else {
            int place = is(b, a, c);
            if (place) g(2, 1, 3, b, place, a - place);
            else cout << "NO" << endl;
        }
    }
    else {
        if (c == a + b) f(1, 2, 3, c, a);
        else {
            int place = is(c, a, b);
            if (place) g(1, 2, 3, c, place, a - place);
            else  cout << "NO" << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}