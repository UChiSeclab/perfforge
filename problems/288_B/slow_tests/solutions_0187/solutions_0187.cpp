#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int add(int a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
  return a;
}
int rest(int a, int b) {
  a -= b;
  if (a < 0) {
    a += mod;
  }
  return a;
}
int mult(int a, int b) { return ((long long)a * (long long)b) % mod; }
int bpow(int b, int exp) {
  if (exp == 0) {
    return 1;
  }
  if (exp == 1) {
    return b;
  }
  int ret = bpow(b, exp / 2);
  ret = mult(ret, ret);
  if (exp & 1) {
    ret = mult(ret, b);
  }
  return ret;
}
int sol;
int p[10];
bool mk[10];
vector<int> g[10];
void dfs(int u) {
  mk[u] = true;
  for (int i = 0; i < g[u].size(); i++) {
    if (!mk[g[u][i]]) {
      dfs(g[u][i]);
    }
  }
}
int pw;
void solve(int step, int k) {
  if (step > k) {
    for (int i = 1; i <= k; i++) {
      g[i].clear();
      mk[i] = false;
    }
    for (int i = 1; i <= k; i++) {
      g[p[i]].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= k; i++) {
      if (!mk[i]) {
        return;
      }
    }
    sol = add(sol, pw);
    return;
  }
  for (int i = 1; i <= k; i++) {
    p[step] = i;
    solve(step + 1, k);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  pw = 1;
  for (int i = 1; i <= n - k; i++) {
    pw = mult(pw, n - k);
  }
  sol = 0;
  solve(1, k);
  cout << sol << '\n';
}
