#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;
using vpll = vector<pll>;
using vvpll = vector<vpll>;
using vpdd = vector<pdd>;
using vvpdd = vector<vpdd>;
ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
ll ceeel(ll n, ll a) {
  if (n % a == 0) return n / a;
  return n / a + 1;
}
ll power(ll x, ll y) {
  ll ans = 1;
  for (ll i = (0); i < (y); i++) {
    ans *= x;
  }
  return ans;
}
void solve() {
  ll n;
  cin >> n;
  deque<ll> s1, s2;
  ll x, y;
  cin >> x;
  for (ll i = (0); i < (x); i++) {
    cin >> y;
    s1.push_back((y));
  }
  cin >> x;
  for (ll i = (0); i < (x); i++) {
    cin >> y;
    s2.push_back((y));
  }
  set<pair<ll, ll> > states;
  ll ans = 0;
  while (!s1.empty() and !s2.empty()) {
    ans++;
    if (ans > 39916800) {
      cout << "-1";
      return;
    }
    x = s1.front();
    s1.pop_front();
    y = s2.front();
    s2.pop_front();
    if (x < y) {
      s2.push_back((x));
      s2.push_back((y));
    } else {
      s1.push_back((y));
      s1.push_back((x));
    }
  }
  cout << ans << " ";
  if (s1.empty()) {
    cout << "2";
  } else
    cout << "1";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
