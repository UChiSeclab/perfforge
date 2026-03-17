#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
using D = double;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
template <typename T>
T sqr(T a) {
  return a * a;
}
template <typename T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <typename T>
T sgn(T a) {
  return a > 0 ? 1 : (a < 0 ? -1 : 0);
}
template <typename T>
T abs(T a) {
  return a > 0 ? a : -a;
}
const int inf = 2e9;
const ld st = 0.000001;
const ld pi = acos((ld)-1);
const ll MAXN = 1000000000 + 100;
ull f1(ull n, ull m) {
  vector<pair<ull, ull>> t;
  ull sr = 0;
  for (int i = 2; i <= sqrt(n); i++) {
    sr = 0;
    while (n % i == 0) {
      n /= i;
      sr++;
    }
    if (sr != 0) {
      t.push_back(make_pair(i, sr));
    }
  }
  if (n != 1) {
    t.push_back(make_pair(n, 1));
  }
  ull ans1 = 18e18;
  for (int i = 0; i < t.size(); i++) {
    ull temp = 0;
    ull s = 1;
    while (s <= m / t[i].first) {
      s *= t[i].first;
      temp += (m / s);
    }
    ans1 = min(ans1, temp / t[i].second);
  }
  return ans1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL), cout.tie(NULL);
  ull n, m;
  cin >> n >> m;
  cout << f1(m, n);
  return 0;
}
