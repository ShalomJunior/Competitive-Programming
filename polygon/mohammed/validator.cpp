#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int t = inf.readInt(1, 10000, "t");
    std::cerr << "t = " << t << "\n";

    inf.readEoln();

    for (int test = 0; test < t; ++test) {
        setTestCase(test);
        int n = inf.readInt(1, 200000, "n");
        inf.readSpace();
        int m = inf.readInt(1, 1000000, "m");
        inf.readEoln();

        for (int i = 0; i < n; ++i) {
            int ai = inf.readInt(1, 1000000, "a[i]");
            if (i < n - 1) {
                inf.readSpace();
            }
        }
        inf.readEoln();
    }
    inf.readEof();
    return 0;
}
