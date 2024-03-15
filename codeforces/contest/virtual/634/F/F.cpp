#include <bits/stdc++.h>
using namespace std;

int f(int l, int r) {
    /*
      The number of changed digits is equal to the number of times the last digit of the result is 9.
    */
    int count = 0;
    int last_digit;

    while (l < r) {
        // Get the last digit of l.
        last_digit = l % 10;

        // If the last digit is 9, then one digit will be changed.
        if (last_digit == 9) {
            count++;
        }

        // Divide l by 10 to remove the last digit.
        l /= 10;
    }

    return count;
}
void solve() {
    int l, r; cin >> l >> r;
    cout << f(l, r) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}