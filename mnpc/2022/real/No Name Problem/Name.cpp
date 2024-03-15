#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, k; cin >> n >> k;
    vector<long long> a(n);
    for (auto& c : a)
        cin >> c;

    int ans = 0;

    int l = 0;
    long long mn = a[0], mx = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] < mn) {
            mn = a[i];
            if (mx - mn > k) {
                int j;
                long long nmx = a[i];
                for (j = i - 1; j >= l; j--) {
                    if (a[j] - mn > k) break;
                    nmx = max(nmx, a[j]);
                }
                l = j + 1;
                mx = nmx;
            }
        }
        else if (a[i] > mx) {
            mx = a[i];
            int j;
            long long nmn = a[i];
            for (j = i - 1; j >= l; j--) {
                if (mx - a[j] > k) break;
                nmn = min(nmn, a[j]);
            }
            l = j + 1;
            mn = nmn;
        }
        ans = max(ans, i - l + 1);
        //cout << "i  = " << i << " l  = " << l << " ans = " << ans << endl;
    }

    cout << ans << endl;
}