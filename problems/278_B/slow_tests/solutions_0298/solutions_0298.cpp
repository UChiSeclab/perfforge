#include <bits/stdc++.h>
using namespace std;
namespace round170 {
namespace B {
inline string next(string a) {
  for (int i = (int)a.size() - 1; i >= 0; --i) {
    if (a[i] == 'z') {
      a[i] = 'a';
      if (i == 0) a = "a" + a;
    } else {
      ++a[i];
      return a;
    }
  }
  return a;
}
inline bool cmp(const string& a, const string& b) {
  if (a.size() == b.size()) return a < b;
  return a.size() < b.size();
}
int solve(istream& in) {
  int n;
  in >> n;
  set<string> q;
  string s;
  string ans;
  for (int i = 0; i < n; ++i) {
    in >> s;
    for (int j = 0; j < (int)s.size(); ++j)
      for (int k = j + 1; k <= (int)s.size(); ++k) {
        string t;
        for (int z = j; z < k; ++z) t += s[z];
        q.insert(t);
      }
  }
  vector<string> v(q.begin(), q.end());
  sort(v.begin(), v.end(), cmp);
  int i = 0;
  s = v[i];
  if (s != "a")
    ans = "a";
  else {
    for (++i; i < (int)v.size(); ++i) {
      s = next(s);
      if (v[i] != s) {
        ans = s;
        break;
      }
    }
    if (ans.empty()) {
      ans = next(v.back());
    }
  }
  cout << ans << endl;
  return 999;
}
}  // namespace B
}  // namespace round170
int main() {
  ios_base::sync_with_stdio(false);
  int status = 0;
  do {
    status = round170::B::solve(cin);
  } while (0);
  return 0;
}
