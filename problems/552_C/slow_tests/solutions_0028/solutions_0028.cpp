#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll OO = 1e18;
int di[8] = {0, 0, 1, -1, -1, 1, -1, 1};
int dj[8] = {1, -1, 0, 0, 1, 1, -1, -1};
string ys = "YES", no = "NO";
const long double dgr = acos(-1) / 180, dg = 180 / acos(-1);
const int mod = 1e8 + 7, N = 1e7, M = 2001;
vector<ll> v;
void solve(ll m, int i = 0) {
  if (!m) exit(puts("YES"));
  if (i == v.size()) return;
  solve(m, i + 1);
  solve(m + v[i], i + 1);
  solve(m - v[i], i + 1);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  ll w, m;
  cin >> w >> m;
  if (w == 2 || w == 3) return cout << ys << '\n', 0;
  v.push_back(1);
  while (v.back() * w <= 9e9 + 99) v.push_back(v.back() * w);
  solve(m, 0);
  cout << no << '\n';
}
