#include <bits/stdc++.h>
using namespace std;
template <class F, class T>
T convert(F a, int p = -1) {
  stringstream ss;
  if (p >= 0) ss << fixed << setprecision(p);
  ss << a;
  T r;
  ss >> r;
  return r;
}
const int oo = int(1e9) + 7;
const int dx[] = {1, 0, 0, -1};
const int dy[] = {0, -1, 1, 0};
const int N = int(2e5) + 10;
int n, t;
bool ok;
set<string> f;
string s, res, cur;
queue<string> q;
int main() {
  cin >> n;
  while (n--) {
    cin >> s;
    t = s.length();
    for (int i = 0; i < (t); ++i)
      for (int j = (i), _b = (t - 1); j <= _b; ++j) {
        res = "";
        for (int k = (i), _b = (j); k <= _b; ++k) res = res + s[k];
        f.insert(res);
      }
  }
  q.push("");
  while (!q.empty()) {
    cur = q.front();
    q.pop();
    for (int ch = ('a'), _b = ('z'); ch <= _b; ++ch) {
      res = cur + char(ch);
      if (!f.count(res)) {
        cout << res;
        return 0;
      }
      q.push(res);
    }
  }
  return 0;
}
