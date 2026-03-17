#include <bits/stdc++.h>
using namespace std;
const int maxn = 600005;
const long long mod = 998244353;
int n, m;
vector<int> k;
vector<pair<int, int>> offers;
long long sum_k;
bool check(int i) {
  vector<int> offers_days(maxn + 5, 0);
  for (int j = 0; j < m; j++) {
    if (offers[j].first > i) continue;
    offers_days[offers[j].second] = offers[j].first;
  }
  vector<int> days_cnts(maxn + 5, 0);
  for (int j = 0; j < n; j++) {
    days_cnts[offers_days[j]] += k[j];
  }
  int balance = 0;
  int optimized = 0;
  for (int j = 1; j <= i; j++) {
    balance++;
    int delta = min(days_cnts[j], balance);
    balance -= delta;
    optimized += delta;
  }
  int left = sum_k - optimized;
  return left * 2 <= balance;
}
void solve() {
  cin >> n >> m;
  k.resize(n);
  sum_k = 0;
  for (int i = 0; i < n; i++) {
    cin >> k[i];
    sum_k += k[i];
  };
  offers.resize(m);
  for (int i = 0; i < m; i++) {
    cin >> offers[i].first >> offers[i].second;
    offers[i].second--;
  }
  sort(offers.begin(), offers.end());
  int sum = 0;
  int max_days = sum_k * 2;
  int l = 0;
  int r = max_days;
  while (l < r - 1) {
    int m = (l + r) / 2;
    if (check(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << r;
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
