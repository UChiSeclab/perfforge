#include <bits/stdc++.h>
using namespace std;
string s, w;
int ans;
bool sub(string t) {
  int i = 0, j = 0;
  while (i < w.size() && j < t.size()) {
    if (w[i] == t[j]) i++;
    j++;
  }
  return (i == w.size());
}
void Suhaib_Sawalha() {
  cin >> s >> w;
  string t, f;
  int n = s.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      t = s.substr(0, i);
      f = s.substr(j, n);
      if (sub(t + f)) ans = max(ans, j - i);
      if (sub(t)) ans = max(ans, n - i);
    }
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int _;
  Suhaib_Sawalha();
  return 0;
}
