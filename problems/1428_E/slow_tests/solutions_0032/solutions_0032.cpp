#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
template <typename T>
void smax(T &a, T b) {
  if (a < b) a = b;
}
template <typename T>
void smin(T &a, T b) {
  if (a > b) a = b;
}
template <typename T>
T pw(T a, T b) {
  T p = 1, one = 1;
  while (b) {
    if (b & one) p = p * a;
    a = a * a;
    b >>= 1;
  }
  return p;
}
template <typename T>
T pwm(T a, T b, T md = mod) {
  T p = 1, one = 1;
  while (b) {
    if (b & one) p = p * a % md;
    a = a * a % md;
    b >>= 1;
  }
  return p;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &it : v) is >> it;
  return is;
}
long long cont(int vl, int p) {
  int q = vl / p;
  int r = vl % p;
  int Q = q + 1;
  return 1ll * (p - r) * q * q + 1ll * r * Q * Q;
}
struct car {
  int val, p;
  car(int val_, int p_) : val{val_}, p{p_} {}
  long long ch() const { return cont(val, p) - cont(val, p + 1); }
  bool operator<(const car &rhs) const { return ch() > rhs.ch(); }
};
void solve() {
  int n, k;
  cin >> n >> k;
  multiset<car> st;
  int ar;
  for (int i = 0; i < n; ++i) {
    cin >> ar;
    st.insert(car{ar, 1});
  }
  int need = k - n;
  while (need != 0) {
    auto b = *st.begin();
    st.erase(st.begin());
    ++b.p;
    st.insert(b);
    --need;
  }
  long long ans = 0;
  for (auto &it : st) ans += cont(it.val, it.p);
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  solve();
}
