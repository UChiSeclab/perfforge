#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using dd = long double;
namespace {
static bool constexpr dbg = 0;
ll constexpr N = -1;
ll n, a, b;
string s;
void init() { cin >> a >> b >> s; }
bool mv(ll &x, ll &y) {
  if (x == a && y == b) return true;
  for (auto ch : s) {
    if (ch == 'U')
      ++y;
    else if (ch == 'D')
      --y;
    else if (ch == 'L')
      --x;
    else
      ++x;
    if (x == a && y == b) return true;
  }
  return false;
}
void solve() {
  ll x = 0, y = 0;
  if (mv(x, y)) {
    cout << "Yes";
    return;
  }
  ll dx = x, dy = y;
  ll cnt = 0;
  if (dx)
    cnt = a / dx;
  else if (dy)
    cnt = b / dy;
  for (ll i = max(0LL, cnt - 200); i <= cnt + 200; ++i) {
    x = i * dx;
    y = i * dy;
    for (ll _ = 1; _ <= (ll)(200); ++_)
      if (mv(x, y)) {
        cout << "Yes";
        return;
      }
  }
  cout << "No";
  return;
}
}  // namespace
int main() {
  if (!dbg) {
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  }
  cout << fixed << setprecision(20);
  init();
  solve();
  return 0;
}
