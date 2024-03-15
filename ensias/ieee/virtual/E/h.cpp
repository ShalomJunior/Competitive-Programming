#include <bits/stdc++.h>

using namespace std;

const int N = 100;
vector<int> db(N);


void compute(){
    for (int i = 0; i < N; i++){
        db[i] = N-i;
    }
}

void out(vector<int> &v){
    for(auto &c:v) cout << c << " ";
    cout << endl;
}
int main(){
    int n; cin >> n;
    vector<int> v(n);
    iota(v.begin(), v.end(), 0);
    
    out(v);
    sort(v.begin(),v.end(), [&](int i, int j){
            return db[i] < db[j];
    });
    out(v);
}
