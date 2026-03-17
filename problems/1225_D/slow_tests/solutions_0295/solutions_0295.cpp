#include <bits/stdc++.h>
using namespace std;
long long cnt[200000];
long long sosuu[200000];
int main() {
  sosuu[1] = 1;
  for (long long i = 2; i <= 100000; ++i) {
    if (sosuu[i] == 1) continue;
    for (long long q = 2; i * q <= 100000; ++q) {
      sosuu[i * q] = 1;
    }
  }
  long long n, k;
  cin >> n >> k;
  long long ans = 0;
  for (long long i = 0; i < n; ++i) {
    long long a = 0;
    cin >> a;
    for (long long i = 2; i <= 100000; ++i) {
      if (sosuu[i] == 1) continue;
      long long hoge = 1;
      for (long long q = 0; q < k; ++q) {
        hoge *= i;
        if (hoge > a) break;
      }
      if (hoge > a) break;
      while (a % hoge == 0) {
        a /= hoge;
      }
    }
    cnt[a]++;
  }
  for (long long i = 1; i <= 100000; ++i) {
    long long target = 1;
    long long now = i;
    for (long long q = 2; q <= sqrt(now); ++q) {
      if (sosuu[q] == 1) continue;
      long long cnt = 0;
      while (now % q == 0) {
        now /= q;
        cnt++;
      }
      if (cnt != 0) {
        if (cnt >= k) {
          target = 200000;
          break;
        }
        cnt = k - cnt;
        for (long long t = 0; t < cnt; ++t) {
          if (target > 100000) break;
          target *= q;
        }
        if (target > 100000) break;
      }
    }
    if (now != 1) {
      for (long long t = 0; t < k - 1; ++t) {
        if (target > 100000) break;
        target *= now;
      }
    }
    if (target <= 100000) {
      if (target == i) {
        ans += cnt[i] * (cnt[i] - 1LL);
      } else {
        ans += cnt[i] * cnt[target];
      }
    }
  }
  cout << ans / 2LL << endl;
}
