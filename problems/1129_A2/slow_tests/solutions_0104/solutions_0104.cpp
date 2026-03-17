#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const long long int inf = 1e18;
const long long int MAXN = 1000005;
template <typename S, typename T>
ostream& operator<<(ostream& out, pair<S, T> const& p) {
  out << '(' << p.f << ", " << p.s << ')';
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T> const& v) {
  long long int l = v.size();
  for (long long int i = 0; i < l - 1; i++) out << v[i] << ' ';
  if (l > 0) out << v[l - 1];
  return out;
}
template <typename T>
void trace(const char* name, T&& arg1) {
  cout << name << " : " << arg1 << endl;
}
template <typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  trace(comma + 1, args...);
}
void solve() {
  long long int n, m, u, v;
  cin >> n >> m;
  vector<long long int> dest[n + 1];
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    dest[u].push_back(v);
  }
  unordered_map<long long int, long long int> opt;
  for (int i = 1; i <= n; i++) {
    for (auto t : dest[i]) {
      long long int temp = t - i;
      if (temp < 0) {
        temp += n;
      }
      if (opt[i] == 0) {
        opt[i] = temp;
      } else {
        opt[i] = min(opt[i], temp);
      }
    }
  }
  vector<long long int> ans;
  for (int i = 1; i <= n; i++) {
    long long int optval = -1;
    for (int j = 1; j <= n; j++) {
      long long int temp = j - i;
      if (temp < 0) {
        temp += n;
      }
      long long int lulz = dest[j].size();
      temp += (lulz - 1) * n + opt[j];
      optval = max(temp, optval);
    }
    ans.push_back(optval);
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(50);
  solve();
}
