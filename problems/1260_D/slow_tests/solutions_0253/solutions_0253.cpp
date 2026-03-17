#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;
template <typename T>
void DEBUG(string label, T value) {
  cerr << "[" << label << " = " << value << "]\n";
}
struct trap {
  int l, r, d;
  trap() {}
  trap(int a, int b, int c) {
    l = a;
    r = b;
    d = c;
  }
};
void solve() {
  int m, n, k, t;
  cin >> m >> n >> k >> t;
  vector<int> agility(m);
  vector<trap> Traps(k);
  for (int i = 0; i < m; ++i) {
    cin >> agility[i];
  }
  for (int i = 0; i < k; ++i) {
    int l, r, d;
    cin >> l >> r >> d;
    Traps[i] = trap(l, r, d);
  }
  sort(agility.begin(), agility.end());
  const int N = 2e5 + 10;
  auto check = [&Traps, &k, &t, &n](int x) -> bool {
    vector<int> R(N, -1);
    for (int i = 0; i < k; ++i) {
      if (Traps[i].d > x) {
        R[Traps[i].l] = max(R[Traps[i].l], Traps[i].r);
      }
    }
    ll total = 0;
    int i = 0;
    while (i < n + 1) {
      int j = i;
      int target = R[j];
      if (target == -1) {
        i++;
        total++;
        continue;
      }
      while (j < target) {
        j++;
        target = max(target, R[j]);
      }
      total += 1LL * (j - i + 1) * 2 + (j - i);
      if (i == j) {
        i++;
        total++;
        continue;
      }
      i = j;
    }
    return total <= (ll)t;
  };
  int ans = 0;
  int left = 0;
  int right = m - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (check(agility[mid])) {
      ans = m - 1 - mid + 1;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
