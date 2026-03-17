#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
pii readp() {
  int a, b;
  cin >> a >> b;
  if (a > b) {
    swap(a, b);
  }
  return make_pair(a, b);
}
vector<pii> a;
vector<pii> b;
bool read() {
  int n, m;
  if (!(cin >> n >> m)) {
    return 0;
  }
  a.resize(n);
  for (int i = 0; i < int(n); ++i) {
    a[i] = readp();
  }
  b.resize(m);
  for (int i = 0; i < int(m); ++i) {
    b[i] = readp();
  }
  return 1;
}
int both(const pii& x, const pii& y) {
  vi ok;
  for (int r = 0; r < int(10); ++r) {
    int xx = (x.first == r) + (x.second == r);
    int yy = (y.first == r) + (y.second == r);
    if (xx == 1 && yy == 1) {
      ok.push_back(r);
    }
  }
  if (int((ok).size()) == 1) {
    return ok.front();
  }
  return -1;
}
int solve() {
  bool a_know = 1;
  for (int i = 0; i < int(int((a).size())); ++i) {
    set<int> oks;
    for (int j = 0; j < int(int((b).size())); ++j) {
      int cur = both(a[i], b[j]);
      if (cur != -1) {
        oks.insert(cur);
      }
    }
    if (int((oks).size()) > 1) {
      a_know = 0;
    }
  }
  bool b_know = 1;
  for (int i = 0; i < int(int((b).size())); ++i) {
    set<int> oks;
    for (int j = 0; j < int(int((a).size())); ++j) {
      int cur = both(b[i], a[j]);
      if (cur != -1) {
        oks.insert(cur);
      }
    }
    if (int((oks).size()) > 1) {
      b_know = 0;
    }
  }
  set<int> oks;
  for (int i = 0; i < int(int((a).size())); ++i) {
    for (int j = 0; j < int(int((b).size())); ++j) {
      int cur = both(a[i], b[j]);
      if (cur != -1) {
        oks.insert(cur);
      }
    }
  }
  bool i_know = int((oks).size()) == 1;
  assert(!oks.empty());
  if (i_know) {
    return *oks.begin();
  }
  if (a_know && b_know) {
    return 0;
  }
  return -1;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  while (read()) {
    cout << solve() << endl;
  }
  return 0;
}
