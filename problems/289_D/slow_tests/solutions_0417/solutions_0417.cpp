#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int max_k = 10;
long long n, k, cnt, ret = 1, niz[max_k], memo[max_k];
bool ok, onstack[max_k];
bool dfs(int curr) {
  if (!curr) return true;
  if (memo[curr] != -1) return memo[curr];
  if (onstack[curr]) return memo[curr] = false;
  onstack[curr] = true;
  memo[curr] = dfs(niz[curr]);
  onstack[curr] = false;
  return memo[curr];
}
void rec(int idx) {
  if (idx == k) {
    for (int i = 0; i < k; i++) memo[i] = -1;
    ok = true;
    for (int i = 1; i < k; i++) ok &= dfs(i);
    cnt += ok;
    return;
  }
  for (int i = 0; i < k; i++) {
    niz[idx] = i;
    rec(idx + 1);
  }
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n - k; i++) ret = (ret * (n - k)) % MOD;
  rec(0);
  cout << (cnt * ret) % MOD;
  return 0;
}
