#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
bool t[4 * 2111111];
int n;
string now;
char c[4 * 2111111];
void update(int l, int r, int v = 1, int tl = 1, int tr = 2111111) {
  if (tl > r || tr < l) return;
  if (t[v]) return;
  if (tl == tr) {
    t[v] = 1;
    c[tl - 1] = now[tl - l];
    return;
  }
  int tm = (tl + tr) >> 1;
  update(l, r, v + v, tl, tm);
  update(l, r, v + 1 + v, tm + 1, tr);
  t[v] = t[v + v] && t[v + 1 + v];
}
int main() {
  cin >> n;
  int ma = 0;
  for (long long i = (0); i < (n); i++) {
    cin >> now;
    int k;
    cin >> k;
    int len = now.length() - 1;
    for (long long j = (0); j < (k); j++) {
      int w;
      cin >> w;
      ma = max(ma, w + len);
      update(w, w + len);
    }
  }
  for (long long i = (0); i < (ma); i++)
    if (c[i] >= 'a' && c[i] <= 'z')
      cout << c[i];
    else
      cout << 'a';
  return 0;
}
