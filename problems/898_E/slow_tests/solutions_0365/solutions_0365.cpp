#include <bits/stdc++.h>
using namespace std;
long long closest_sq(long long num) {
  double sqrt_ = sqrt(num);
  int a1 = int(sqrt_);
  int a2 = int(sqrt_) + 1;
  long long ans1 = a1 * a1;
  long long ans2 = a2 * a2;
  if (num - ans1 > ans2 - num) {
    return ans2;
  } else {
    return ans1;
  }
}
int main() {
  int n;
  while (cin >> n) {
    vector<long long> a(n);
    vector<long long> d;
    int sq = 0;
    int not_sq = 0;
    int zeros = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (a[i] == 0) {
        zeros++;
      } else {
        long long closest = closest_sq(a[i]);
        if (closest != a[i]) {
          d.push_back(abs(closest - a[i]));
          not_sq++;
        } else {
          sq++;
        }
      }
    }
    int half = n / 2;
    if (sq + zeros == half) {
      cout << 0 << endl;
    } else if (sq + zeros > half) {
      if (zeros <= half) {
        cout << (sq + zeros - half) << endl;
      } else {
        cout << sq + 2 * (zeros - half) << endl;
      }
    } else {
      int cnt = not_sq - half;
      sort(d.begin(), d.end());
      long long ans = 0;
      for (int i = 0; i < cnt; ++i) {
        ans += d[i];
      }
      cout << ans << endl;
    }
  }
  return 0;
}
