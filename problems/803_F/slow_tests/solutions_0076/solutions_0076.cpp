#include <bits/stdc++.h>
using namespace std;
long long int quick_pow(long long int a, long long int b, long long int MOD) {
  long long int ans = 1;
  long long int base = a;
  while (b) {
    if (b & 1) {
      ans = ans * base % MOD;
    }
    b >>= 1;
    base = base * base % MOD;
  }
  return ans;
}
const int maxn = 2e6 + 20;
int ans[maxn], num[maxn];
const int MOD = 1e9 + 7;
void work() {
  int n, k;
  scanf("%d", &n);
  int mx = -(0x3f3f3f3f);
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    num[x]++;
    mx = max(mx, x);
  }
  long long int res = 0;
  if (num[0]) {
    ans[0] = (quick_pow(2, num[0], MOD) - 1 + MOD) % MOD;
    res = ans[0];
  }
  for (int i = mx; i >= 1; --i) {
    int has = num[0];
    for (int j = i; j <= mx; j += i) has += num[j];
    ans[i] = (quick_pow(2, has, MOD) - 1 + MOD) % MOD;
    for (int j = 2 * i; j <= mx; j += i) {
      ans[i] = (ans[i] - ans[j] + MOD) % MOD;
    }
    ans[i] = (ans[i] - ans[0] + MOD) % MOD;
    res = (res + quick_pow(i, k, MOD) * ans[i] % MOD) % MOD;
  }
  cout << ans[1] << endl;
  for (int i = 0; i <= mx; ++i) ans[i] = num[i] = 0;
}
int main() {
  work();
  return 0;
}
