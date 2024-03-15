#include <bits/stdc++.h>
using namespace std;

int hashFunction(string s) {
    int hash = 0;
    for (int i = 0; i < s.length(); i++) {
        hash += (i + 1) * (s[i] - 'a' + 1);
    }
    return hash;
}

void go() {
    stack<int> st;
    st.push(78);
    st.pop();
    st.push(44);
    st.push(12);
    st.push(18);
    st.pop();
    st.push(19);
    st.pop();
    st.pop();
    st.push(12);
    st.push(28);
    while (!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }
}

int main() {
    go();
}
