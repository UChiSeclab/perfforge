#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
const int mod = (int)1e9 + 7;
int getInRange(vector<int> &a, int start, int lo, int hi) {
  return upper_bound(a.begin() + start, a.end(), hi) -
         lower_bound(a.begin() + start, a.end(), lo);
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  int ans = 0;
  for (int b = 0; b < 30; b++) {
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
      int num = 0;
      for (int j = b; j >= 0; j--) {
        num *= 2;
        if (a[i] & (1 << j)) {
          num++;
        }
      }
      A[i] = num;
    }
    sort(A.begin(), A.end());
    int B = b + 1;
    int64_t cntPairs = 0;
    for (int i = 0; i < n; i++) {
      cntPairs +=
          getInRange(A, i + 1, (1 << (B - 1)) - A[i], (1 << B) - 1 - A[i]);
      cntPairs +=
          getInRange(A, i + 1, (1 << B) + (1 << (B - 1)) - A[i], (int)1e9);
    }
    if (cntPairs % 2 != 0) {
      ans |= (1 << b);
    }
  }
  cout << ans << "\n";
  return 0;
}
