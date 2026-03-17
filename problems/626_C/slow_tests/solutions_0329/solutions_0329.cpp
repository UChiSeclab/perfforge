#include <bits/stdc++.h>
using namespace std;
int n, m, ans, temp;
set<int> st;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  cin >> n >> m;
  ans = n + m;
  temp = 2;
  while (n) {
    n -= (temp % 6 != 0);
    st.insert(temp);
    temp += 2;
  }
  temp = 3;
  while (m) {
    m -= (temp % 6 != 0);
    st.insert(temp);
    temp += 3;
  }
  for (auto i : st) {
    ans--;
    if (!ans) return cout << i << "\n", 0;
  }
  return 0;
}
