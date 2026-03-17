#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int t[n];
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  if (n == 1) {
    cout << m - t[0];
    return 0;
  }
  int ans = 0;
  for (int k = 0; k < n * n * n; k++) {
    set<int> st;
    for (int i = 0; i < n; i++) {
      if (st.count(t[i]) == 0 && t[i] < m) {
        st.insert(t[i]);
        t[i]++;
      }
    }
    if (st.size()) {
      ans++;
    }
  }
  cout << ans;
  return 0;
}
