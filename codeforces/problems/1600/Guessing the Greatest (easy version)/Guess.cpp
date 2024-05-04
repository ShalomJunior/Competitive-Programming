#include <bits/stdc++.h>

using namespace std;

int ask(int l, int r) {
    if (l == r) return l;
    printf("? %d %d\n", l, r);
    cout.flush();
    int ans; cin >> ans;
    return ans;
}

int main() {
    int n; cin >> n;

    int l = 1, r = n;
    int last = ask(l, r);

    while (l < r) {
        int mid = (l + r) / 2;

        int as;

        if (last <= mid) {
            as = ask(l, mid);
            if (as == last && l != mid) {
                r = mid;
            }
            else {
                l = mid + 1;
                last = ask(l, r);
            }
        }
        else {
            as = ask(mid + 1, r);
            if (as == last && mid + 1 != r) {
                l = mid + 1;
            }
            else {
                r = mid;
                last = ask(l, r);
            }
        }

    }

    cout << "! " << l << endl;
}