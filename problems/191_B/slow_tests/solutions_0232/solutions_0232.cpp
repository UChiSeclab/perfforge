#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:200000000")
using namespace std;
template <typename T>
inline T Abs(T x) {
  return (x >= 0) ? x : -x;
}
template <typename T>
inline T sqr(T x) {
  return x * x;
}
template <typename T>
string toStr(T x) {
  stringstream st;
  st << x;
  string s;
  st >> s;
  return s;
}
const int INF = (int)1E9;
const long long INF64 = (long long)1E18;
const long double EPS = 1E-9;
const long double PI = 3.1415926535897932384626433832795;
const int MAXN = 100100;
set<pair<long long, int> > st[2];
long long b, a[MAXN], sum = 0;
int n, k;
void norm() {
  while ((int)st[0].size() > k) {
    pair<long long, int> t = *st[0].begin();
    st[1].insert(t);
    st[0].erase(t);
    sum -= t.first;
  }
  while ((int)st[0].size() < k && !st[1].empty()) {
    pair<long long, int> t = *st[1].rbegin();
    st[0].insert(t);
    st[1].erase(t);
    sum += t.first;
  }
}
void add(int v) {
  sum += a[v];
  st[0].insert(make_pair(a[v], v));
  norm();
}
void erase(int v) {
  if (st[0].count(make_pair(a[v], v))) sum -= a[v];
  st[0].erase(make_pair(a[v], v));
  st[1].erase(make_pair(a[v], v));
  norm();
}
int main() {
  cin >> n >> k >> b;
  k--;
  for (int i = 0; i < (int)(n); i++) {
    scanf("%d", &a[i]);
    if (i + 1 != n) add(i);
  }
  for (int i = 0; i < (int)(n - 1); i++) {
    erase(i);
    if (b - sum < a[i]) {
      cout << i + 1 << endl;
      return 0;
    }
    add(i);
  }
  cout << n << endl;
  return 0;
}
