#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

// Checker functions for performance-characterizing invariants
void check_carrot_split_invariant(int n, int k) {
    int requiredSplits = k - n;
    if (requiredSplits > 10000) {  // arbitrary threshold for a large number of splits
        cerr << "Warning: Performance bottleneck condition triggered - excessive carrot splits required!" << endl;
        abort();
    }
}

void check_carrot_length_invariant(const vector<int>& carrots) {
    int maxCarrotLength = *max_element(carrots.begin(), carrots.end());
    if (maxCarrotLength > 500000) {  // threshold for large carrots
        cerr << "Warning: Performance bottleneck condition triggered - very large carrot length!" << endl;
        abort();
    }
}

void check_reheap_operations(int need) {
    if (need > 10000) {  // threshold indicating many re-heap operations needed
        cerr << "Warning: Performance bottleneck condition triggered - excessive re-heap operations!" << endl;
        abort();
    }
}

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

  check_carrot_split_invariant(n, k);  // Check invariants before starting computations

  vector<int> carrots(n);
  cin >> carrots;
  check_carrot_length_invariant(carrots);

  multiset<car> st;
  for (int i = 0; i < n; ++i) {
    st.insert(car{carrots[i], 1});
  }
  int need = k - n;
  
  check_reheap_operations(need);  // Check before entering the while loop

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