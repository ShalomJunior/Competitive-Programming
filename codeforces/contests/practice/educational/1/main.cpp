#include<bits/stdc++.h>
using namespace std;

template<typename t>
class fenwick(){
  	int n;
        vector<T> arr;
	fenwick(int _n) n(_n) {
		arr.resize(n + 3);
	}
	void add(int index, int val) {
		for (int )	
	}
	T sum() {
	}
};

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &c : a) cin >> c;
	fenwick<int> fen(n);
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += fen.rangeQuery(0, 0);
	}
	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}

