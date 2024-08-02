#include<vector>
#include <iostream>
#include "testlib.h"
#include "assert.h"
using namespace std;

int n, m, test;
vector<int> a;


int checkAns(InStream& in) {
    int res = in.readInt(-1, 1000000, "range of answer");
    cerr << "res = " << res << endl;
    if (res == 0) {
        in.quitf(_wa, "invalid output");
    }
    map<int, int> cnt;
    bool fatiWins = true;
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
        if (cnt[res] < cnt[m]) {
            fatiWins = false;
            break;
        }
    }
    if (fatiWins && res == -1) {
        in.quitf(_wa, "Test case %d: Incorrect, expected Fati to win with a valid f", test + 1);
    }
    if (!fatiWins && res != -1) {
        in.quitf(_wa, "Test case %d: Incorrect, Not expected Fati to win", test + 1);
    }
    return res;
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    int t = inf.readInt();
    std::cerr << "t = " << t << "\n";
    for (test = 0; test < t; ++test) {
        setTestCase(test);
        n = inf.readInt();
        m = inf.readInt();

        a.clear();
        a.resize(n);
        std::cerr << "n = " << n << '\n';
        for (int i = 0; i < n; ++i) {
            a[i] = inf.readInt();
            std::cerr << a[i] << " ";
        }
        cerr << '\n';
        int judge = checkAns(ans);
        int  p = checkAns(ouf);
        std::cerr << "passed" << endl;
        //quitf(_ok, "Test case %d: Correct", test + 1);
    }
    quitf(_ok, "All test cases passed");
}
