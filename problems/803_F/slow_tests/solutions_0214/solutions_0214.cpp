#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 9;
const int MOD = 1000000007;
int N, n = 1;
int w[maxn], mu[maxn], cnt[maxn], P[maxn];
int main() {
  cin >> N;
  memset(cnt, 0, sizeof cnt);
  P[0] = 1;
  for (int i = 0; i < N; i++) {
    scanf("%d", w + i);
    n = max(n, w[i]);
    cnt[w[i]]++;
    P[i + 1] = 2 * P[i] % MOD;
  }
  memset(mu, 0, sizeof mu);
  mu[1] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 2 * i; j <= n; j += i) {
      mu[j] -= mu[i];
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int c = 0;
    for (int j = i; j <= n; j += i) {
      c += cnt[j];
    }
    ans = ((ans + mu[i] * (P[c] - 1) % MOD) % MOD + MOD) % MOD;
  }
  cout << ans << endl;
  return 0;
}
