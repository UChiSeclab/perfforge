#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll lim, n, k;
map<ll, ll> cnt;
struct data {
  ll l, r, x, y;
};
vector<data> dp;

// Checkers implementation
void check_get_invocation_count(int count, int threshold) {
    if (count > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive get() invocations!" << endl;
        abort();
    }
}

void check_getcnt_invocation_count(int count, int threshold) {
    if (count > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive getcnt() invocations!" << endl;
        abort();
    }
}

void check_dp_size(int size, int threshold) {
    if (size > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - large dp structure causing inefficient lookups!" << endl;
        abort();
    }
}

void check_cnt_updates(int count, int threshold) {
    if (count > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive cnt updates!" << endl;
        abort();
    }
}

int get_invocation_count = 0;
int getcnt_invocation_count = 0;
int cnt_update_count = 0;

ll get(ll x) {
  get_invocation_count++;
  if (x > lim) return 0;
  if (cnt.count(x)) {
    return cnt[x];
  }
  for (auto it : dp)
    if (it.l <= x && it.r >= x) {
      if (x & 1)
        return it.y;
      else
        return it.x;
    }
}

ll getcnt(ll x) {
  getcnt_invocation_count++;
  if (x & 1) return 1 + get(2ll * x);
  return 1 + get(2ll * x) + get(x + 1);
}

int main() {
  cin >> n >> k;
  lim = n;
  cnt[n] = 1;
  for (int step = 2;; step++) {
    if (n <= 50) {
      for (ll i = n; i > 0; i--) {
          cnt[i] = getcnt(i);
          cnt_update_count++;
      }
      break;
    }
    ll x = n / 2;
    while (2 * x <= n) x++;
    for (ll i = n;; i--) {
      cnt[i] = getcnt(i);
      cnt_update_count++;
      if (i + 2 <= n && cnt[i] == cnt[i + 2]) {
        dp.push_back({x, i + 1, cnt[i], cnt[i + 1]});
        int sz = dp.size();
        if (i & 1) swap(dp[sz - 1].x, dp[sz - 1].y);
        break;
      }
    }
    n = x - 1;
  }
  
  // Place checks here to avoid checking inside tight loops
  check_get_invocation_count(get_invocation_count, 10000);
  check_getcnt_invocation_count(getcnt_invocation_count, 1000);
  check_dp_size(dp.size(), 1000); // Arbitrary thresholds
  check_cnt_updates(cnt_update_count, 10000);

  ll ans = -1;
  for (auto it : cnt) {
    if (it.second >= k) ans = max(ans, it.first);
  }
  cout << ans << "\n";
  return 0;
}