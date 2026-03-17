#include <bits/stdc++.h>
using namespace std;
int mod = 998244353;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
template <typename T>
T GCD(T a, T b) {
  long long t;
  while (a) {
    t = a;
    a = b % a;
    b = t;
  }
  return b;
}
template <typename T>
string toString(T a) {
  return to_string(a);
}
template <typename T>
void toInt(string s, T& x) {
  stringstream str(s);
  str >> x;
}
inline int add(int x, int y) {
  x += y;
  if (x >= mod) x -= mod;
  return x;
}
inline int sub(int x, int y) {
  x -= y;
  if (x < 0) x += mod;
  return x;
}
inline int mul(int x, int y) { return (x * 1ll * y) % mod; }
inline int powr(int a, long long b) {
  int x = 1 % mod;
  while (b) {
    if (b & 1) x = mul(x, a);
    a = mul(a, a);
    b >>= 1;
  }
  return x;
}
inline int inv(int a) { return powr(a, mod - 2); }
int n, m;
const int MAX = 2010;
vector<int> vec;
vector<int> off[MAX];
bool isItPossible(int day) {
  int cur = 0;
  int req = accumulate(vec.begin(), vec.end(), 0);
  vector<int> temp = vec;
  vector<int> toff[MAX];
  vector<bool> vis(n + 1, false);
  for (int i = day; i >= 1; i--) {
    for (auto it : off[i]) {
      if (vis[it]) continue;
      vis[it] = true;
      toff[i].push_back(it);
    }
  }
  for (int i = 1; i <= day; i++) {
    cur++;
    if (req * 2 <= cur) {
      return true;
    }
    for (auto it : toff[i]) {
      int m = min(temp[it], cur);
      cur -= m;
      req -= m;
      temp[it] -= m;
    }
    if (req * 2 <= cur) {
      return true;
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  vec.push_back(0);
  int v;
  for (int i = 0; i < n; i++) {
    cin >> v;
    vec.push_back(v);
  }
  int d, t;
  for (int i = 0; i < m; i++) {
    cin >> d >> t;
    off[d].push_back(t);
  }
  int ans = 0;
  for (int i = 0; i <= 2000; i++) {
    if (isItPossible(i)) {
      ans = i;
      break;
    }
  }
  cout << ans << '\n';
  return 0;
}
