#include <bits/stdc++.h>
using namespace std;
string to_str(long long int x) {
  ostringstream o;
  o << x;
  return o.str();
}
long long int to_int(string s) {
  istringstream st(s);
  long long int i;
  st >> i;
  return i;
}
int inp[10000];
double inp2[10000];
int n;
int gn(double al) {
  double rem = al;
  double curs = 0.0;
  for (int i = 0; i < n; i++) {
    double k = inp2[i];
    rem -= (k - curs) * 10.0;
    if (rem < 0.0) return -1;
    if (rem >= 9.99999999999) return 1000000001;
    rem += al;
    curs = k;
  }
  return inp[n - 1] + (int)floor(rem / 10);
}
bool fn() {
  double lft = 10.0, rgt = 100000001.0, md = 10.0;
  while (fabs(rgt - lft) > 1e-7) {
    md = (lft + rgt) / 2.0;
    int el = gn(md);
    if (el == inp[n]) return true;
    if (el < inp[n])
      lft = md;
    else
      rgt = md;
  }
  return false;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> inp2[i];
    inp[i] = int(inp2[i] + .1);
  }
  int d = inp[0];
  if (n > 1) d = inp[n - 1] - inp[n - 2];
  int ct = 0, ans;
  for (int i = max(d - 1000, 1); i < d + 1006; i++) {
    inp[n] = inp[n - 1] + i;
    if (fn()) {
      ct++;
      ans = inp[n];
    }
  }
  assert(ct != 0);
  if (ct == 1) {
    cout << "unique\n";
    cout << ans << endl;
  } else {
    cout << "not unique\n";
  }
  return 0;
}
