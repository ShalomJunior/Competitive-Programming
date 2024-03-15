#include <bits/stdc++.h>
using namespace std;

int main() {
    int fc, fh; cin >> fc >> fh;
    int ac, ah; cin >> ac >> ah;
    int f = 3 * fc + fh / 2;
    int a = 3 * ac + ah / 2;
    if (f < a) cout << "Ali";
    else if (f == a) cout << "Draw";
    else cout << "Fatima";
    cout << endl;
}