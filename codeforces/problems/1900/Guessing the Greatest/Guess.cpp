#include <bits/stdc++.h>

using namespace std;

int ask(int l, int r) {
    if (l == r) return l;
    printf("? %d %d\n", l, r);
    int ans; cin >> ans;
    cout.flush();
    return ans;
}

void Left(int n, int sec) {
    int l = sec;
    int minus = sec - 1;
    do {
        minus = minus / 2 + (minus & 1);
        if (ask(l - minus, sec) != sec) {
            l -= minus;
        }
    } while (minus != 1);
    cout << "! " << l - 1 << endl;
}

void Right(int n, int sec) {
    int r = sec;
    int add = (n - sec);
    do {
        add = add / 2 + (add & 1);
        if (ask(sec, r + add) != sec) {
            r += add;
        }
    } while (add != 1);
    cout << "! " << r + 1 << endl;
}

int main() {
    int n; cin >> n;
    if (n == 1) {
        cout << "! " << 1 << endl;
        return 0;
    }

    int sec = ask(1, n);
    bool left = (ask(1, sec) == sec && sec != 1);

    (left) ? Left(n, sec) : Right(n, sec);
}