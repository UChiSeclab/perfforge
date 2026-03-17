#include <bits/stdc++.h>
using namespace std;
int n, k;
int go[100];
int chega[100];
int dfs(int v) {
  if (v == 0) return chega[v] = 1;
  if (chega[v] == 0) return 0;
  chega[v] = 0;
  return chega[v] = dfs(go[v]);
}
bool check() {
  for (int i = 0; i < k; i++) chega[i] = -1;
  for (int i = 0; i < k; i++)
    if (chega[i] == -1) {
      chega[i] = dfs(i);
    }
  for (int i = 0; i < k; i++)
    if (!chega[i]) return 0;
  return 1;
}
long long solve(int pos) {
  if (pos == k) {
    if (check()) return 1;
    return 0;
  }
  long long ret = 0;
  for (int i = 0; i < k; i++) {
    go[pos] = i;
    ret += solve(pos + 1);
    if (ret >= 1000000007) ret -= 1000000007;
  }
  return ret;
}
int main() {
  cin >> n >> k;
  long long ans = 1;
  long long m = (n - k);
  for (int i = 0; i < n - k; i++) {
    ans *= m;
    ans %= 1000000007;
  }
  ans *= solve(0);
  ans %= 1000000007;
  cout << ans << endl;
  return 0;
}
