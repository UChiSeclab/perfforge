#include <bits/stdc++.h>
using namespace std;
long long n, otv, q, k, a[5100], t[100];
struct pel {
  long long a, b, num;
};
vector<pel> v;
bool operator<(const pel &l, const pel &r) {
  if (l.a != r.a) return l.a < r.a;
  if (l.b != r.b) return l.b < r.b;
  return l.num < r.num;
}
pel f(long long a1, long long a2, long long a3) {
  pel o;
  o.a = -1;
  long long l = 1, r = v.size(), le, re;
  for (int i = 0; i < 21; i++) {
    le = (l + r) / 2;
    if (v[le].a >= a1)
      r = le;
    else
      l = le;
  }
  le = r;
  l = 1, r = v.size();
  for (int i = 0; i < 21; i++) {
    re = (l + r) / 2;
    if (v[re].a <= a1)
      l = re;
    else
      r = re;
  }
  re = l;
  if (v[le].a != a1 || (v[le].a == a1 && v[le].b > a2)) return o;
  for (int i = le; i <= re; i++) {
    if (v[i].b <= a2 && v[i].num != a3) {
      o.a = v[i].a;
      o.b = v[i].b;
      o.num = v[i].num;
      return o;
    } else if (v[i].b > a2)
      break;
  }
  return o;
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  cin >> q;
  for (int i = 0; i < q; i++) cin >> t[i];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= k; j++) {
      pel tmp;
      tmp.a = a[i] * j;
      tmp.b = j;
      tmp.num = i;
      v.push_back(tmp);
    }
  sort(v.begin(), v.end());
  for (int i = 0; i < q; i++) {
    long long fl = 0;
    for (vector<pel>::iterator j = v.begin(); j != v.end(); j++) {
      if ((*j).a > t[i] && fl == 0) {
        fl = -1;
        break;
      }
      if ((*j).a > t[i] && fl != 0) break;
      if ((*j).a == t[i]) {
        if (fl == 0)
          fl = (*j).b;
        else
          fl = min(fl, (*j).b);
      } else {
        pel z = f(t[i] - (*j).a, k - (*j).b, (*j).num);
        if (z.a != -1) {
          if (fl == 0)
            fl = (*j).b + z.b;
          else
            fl = min(fl, (*j).b + z.b);
        }
      }
    }
    if (fl == 0)
      cout << -1 << '\n';
    else
      cout << fl << '\n';
  }
  return 0;
}
