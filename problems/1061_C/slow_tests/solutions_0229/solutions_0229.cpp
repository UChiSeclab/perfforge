#include <bits/stdc++.h>
using namespace std;
template <class X, class Y>
void amax(X& x, const Y& y) {
  if (x < y) x = y;
}
template <class X, class Y>
void amin(X& x, const Y& y) {
  if (x > y) x = y;
}
const int INF = 1e9 + 10;
const long long INFL = (long long)1e18 + 10;
const int MAX = 1e6 + 10;
const int MOD = 1e9 + 7;
int n;
int a[MAX];
int f[MAX];
vector<int> dv[MAX];
int add(int a, int b) { return (a + b) % MOD; }
void process() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int maxa = *max_element(a + 1, a + n + 1);
  for (int i = 1; i <= maxa; i++)
    for (int j = 1; j <= maxa / i; j++) dv[i * j].push_back(i);
  f[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = int((dv[a[i]]).size()) - 1; j >= 0; j--) {
      f[dv[a[i]][j]] = add(f[dv[a[i]][j]], f[dv[a[i]][j] - 1]);
    }
  }
  int res = 0;
  for (int i = 1; i <= n; i++) res = add(res, f[i]);
  cout << res;
}
int main() {
  ios_base::sync_with_stdio(false);
  process();
}
