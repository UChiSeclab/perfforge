#include <bits/stdc++.h>
template <typename T>
T mymax(T x, T y) {
  return (x > y ? x : y);
}
using namespace std;
const int N = 1000005;
int c = 1;
void solve() {
  string s, t;
  cin >> s >> t;
  int n1 = s.size(), n2 = t.size();
  auto has_subseq = [&](string cs) {
    int j = 0;
    for (int i = 0; i < (int)cs.size(); i++) {
      if (cs[i] == t[j]) j++;
    }
    return (j == n2);
  };
  int ans = 0;
  for (int i = 0; i < n1; i++) {
    for (int j = i; j < n1; j++) {
      string temp = "";
      for (int k = 0; k < i; k++) {
        temp += s[k];
      }
      for (int k = j + 1; k < n1; k++) {
        temp += s[k];
      }
      if (has_subseq(temp)) {
        ans = max(ans, j - i + 1);
      } else
        break;
    }
  }
  printf("%d\n", ans);
}
int main() {
  solve();
  return 0;
}
