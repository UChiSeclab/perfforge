#include <bits/stdc++.h>
using namespace std;
string pl(string s) {
  int p = (int)s.size() - 1;
  string res;
  while (p >= 0 and s[p] == 'z') p--;
  if (p == -1) {
    res.push_back('a');
    for (int i = 0; i < s.size(); i++) res.push_back('a');
    return res;
  } else {
    res = s;
    res[p]++;
    return res;
  }
}
string min_str(string a, string b) {
  if (a.size() != b.size()) return (a.size() < b.size()) ? a : b;
  return min(a, b);
}
int main() {
  int n;
  cin >> n;
  set<string> q;
  q.insert("");
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < s.size(); j++)
      for (int k = 1; j + k <= s.size(); k++) q.insert(s.substr(j, k));
  }
  string ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
  for (set<string>::iterator it = q.begin(); it != q.end(); ++it) {
    string s = pl(*it);
    if (q.find(s) == q.end()) {
      ans = min_str(ans, s);
    }
  }
  cout << ans << endl;
  return 0;
}
