#include <bits/stdc++.h>
using namespace std;

int main() {
    int cm, n; cin >> cm >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        cm += a;
    }
    if (!n) printf("It is a lonely day, but I still need to buy %.0fL of Chourba\n", ceil((double)cm * 0.2));

    else printf("I need to buy %.0fL of Chourba\n", ceil((double)cm * 0.2));
}