#include <bits/stdc++.h>
using namespace std;
void solve() {}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  deque<long long> dq;
  for (long long i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    dq.push_back(x);
  }
  for (long long i = 1; i <= 2e6; i++) {
    while ((long long)dq.size()) {
      if (dq.front() - 1 <= i) {
        dq.pop_front();
      } else
        break;
    }
    while ((long long)dq.size()) {
      if (1e6 - dq.back() <= i) {
        dq.pop_back();
      } else
        break;
    }
    if (dq.empty()) {
      cout << i << '\n';
      break;
    }
  }
}
