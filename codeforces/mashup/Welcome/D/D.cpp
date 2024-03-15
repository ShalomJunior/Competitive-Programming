#include <bits/stdc++.h>

using namespace std;

void ask(int l, int r, int& ans) {
    printf("? %d %d\n", l, r);
    cout.flush();
    cin >> ans;
}

int main() {
    int n; cin >> n;
    int l = 1, r = n;

    int q;
    while (l < r) {
        ask(l, r, q);
        int mid = (l + r) / 2;
        int nxt;
        if (q <= mid) {
            if (l == mid)l++;
            else {
                ask(l, mid, nxt);
                if (nxt == q) r = mid;
                else l = mid + 1;
            }
        }
        else {
            if (mid + 1 == r)r--;
            else {
                ask(mid + 1, r, nxt);
                if (nxt == q) l = mid + 1;
                else r = mid;
            }
        }
    }
    cout << "! " << l << endl;
}