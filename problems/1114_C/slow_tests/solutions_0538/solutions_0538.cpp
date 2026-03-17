#include <bits/stdc++.h>
using namespace std;
template <typename t>
t in(t q) {
  cin >> q;
  return q;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  for (int i = 0; i < ((int)(v).size()); ++i) {
    os << v[i];
    if (i != ((int)(v).size()) - 1) os << ",";
  }
  os << "]";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const map<T, S>& v) {
  for (auto it : v) os << "(" << it.first << ":" << it.second << ")";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const pair<T, S>& v) {
  os << "(" << v.first << "," << v.second << ")";
  return os;
}
const long double PI = acosl(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
inline int rand(int l, int r) {
  return uniform_int_distribution<int>(l, r)(rng);
}
inline long long rand(long long l, long long r) {
  return uniform_int_distribution<long long>(l, r)(rng);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(10);
  long long n, b;
  cin >> n >> b;
  map<long long, long long> pr;
  for (long long i = 2; i <= sqrt(b); ++i) {
    while (b % i == 0) {
      pr[i]++;
      b /= i;
    }
  }
  if (b > 1) pr[b]++;
  long long mi = -1;
  for (auto el : pr) {
    if (el.second == 0) continue;
    long long first = el.first;
    long long c = 0;
    while (first <= n) {
      c += n / first;
      if (first > n / el.first) break;
      first *= el.first;
    }
    c /= el.second;
    if (mi == -1) mi = c;
    mi = min(mi, c);
  }
  cout << mi << '\n';
  return 0;
}
