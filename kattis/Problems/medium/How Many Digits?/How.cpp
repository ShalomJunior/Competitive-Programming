#include<bits/stdc++.h>
#define db double 
#define ll long long

using namespace std;

const int N = 1e6 + 5;

vector<ll> v(N);

void compute() {
    db ans = 1.;
    v[0] = 1;
    for (int i = 1; i < N; i++) {
        ans += log10(i);
        v[i] = (ll)ans;
    }
}

int main() {
    compute();
    int n;
    while (cin >> n) cout << v[n] << endl;
}