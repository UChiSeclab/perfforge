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
const int MAXN = 100000;
const int mod = 1e9 + 7;
vector<vector<ll>> g;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  ll n, m;
  cin >> n >> m;
  g.resize(n);
  ll r = -1;
  for (int i = 0; i < m; i++) {
    ll x, y;
    cin >> x >> y;
    --x, --y;
    g[x].push_back(y);
    g[y].push_back(x);
    if (r == -1) r = x;
  }
  if (r == -1) return cout << 0, 0;
  vector<ll> tr;
  for (int i = 1; i <= 6; i++) {
    tr.push_back(i);
  }
  ll ansr = 0;
  do {
    map<ll, ll> ans;
    for (int j = 0; j < 6; j++) {
      ans[j] = tr[j];
    }
    if (n == 7) {
      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          ans[i] = ans[j];
          vector<ll> rs;
          for (int k = 0; k < tr.size(); k++) {
            if (tr[k] == ans[i]) {
              continue;
            } else {
              rs.push_back(tr[k]);
            }
          }
          ll l = 0;
          for (int k = 0; k < n; k++) {
            if (k != i && k != j) {
              ans[k] = rs[l];
              ++l;
            }
          }
          set<pair<ll, ll>> answ;
          ll tem = 0;
          for (int i = 0; i < n; i++) {
            for (int j = 0; j < g[i].size(); j++) {
              int to = g[i][j];
              if (ans[i] == 7 || ans[to] == 7) continue;
              if (answ.find(make_pair(ans[i], ans[to])) == answ.end() ||
                  answ.find(make_pair(ans[to], ans[i])) == answ.end())
                tem++;
              answ.insert(make_pair(ans[i], ans[to]));
              answ.insert(make_pair(ans[to], ans[i]));
            }
          }
          ansr = max(ansr, tem);
        }
      }
    } else {
      set<pair<ll, ll>> answ;
      ll tem = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < g[i].size(); j++) {
          int to = g[i][j];
          if (ans[i] == 7 || ans[to] == 7) continue;
          if (answ.find(make_pair(ans[i], ans[to])) == answ.end() ||
              answ.find(make_pair(ans[to], ans[i])) == answ.end())
            tem++;
          answ.insert(make_pair(ans[i], ans[to]));
          answ.insert(make_pair(ans[to], ans[i]));
        }
      }
      ansr = max(ansr, tem);
    }
  } while (next_permutation(tr.begin(), tr.end()));
  cout << ansr;
  return 0;
}
