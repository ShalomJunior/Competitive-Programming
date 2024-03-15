#include <bits/stdc++.h>
using namespace std;
int main () {
    int ntests;
    cin >> ntests;
    for (int i = 0; i < ntests; ++ i) {
        int nchanges = 0;
        int nstrings;
        cin >> nstrings;
        set<string> s;
        vector<string> vi;
        string st;
        for (int j = 0; j < nstrings; j ++ ) {
            cin >> st;
            if (!s.count (st)) {
                s.insert (st);
                vi.push_back (st);
                continue;
            }
            for (int k = 0; k < 4; k ++ ) {
                for (int l = 1; l <= 10; l ++) {
                    st [k] = (st [k] - '0' + 1) % 10 + '0';
                    if (!s.count (st)) {
                        nchanges ++;
                        s.insert (st);
                        vi.push_back(st);
                        goto endloop;
                    }
                }
            }
        endloop:  
            continue;
        }
        cout << nchanges << endl;
        for (auto v: vi)
            cout << v << endl;
    }
}
