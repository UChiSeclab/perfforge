#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int v[10];
int pos[8];
int k;
long long ans;
vector<int> adj[8];
int qtd = 0;
bool visi[10];
void dfs(int src) {
  visi[src] = true;
  ++qtd;
  for (__typeof((adj[src]).begin()) it = (adj[src]).begin();
       it != (adj[src]).end(); ++it)
    if (!visi[*it]) dfs(*it);
}
bool ok() {
  for (int i = 0; i < (k); ++i) adj[i].clear();
  for (int i = 0; i < (k); ++i) adj[v[i]].push_back(i);
  memset(visi, 0, sizeof(visi));
  qtd = 0;
  dfs(0);
  return (qtd == k);
}
void solve(int p) {
  if (p == k) {
    if (ok()) ans = (ans + 1) % MOD;
  } else {
    for (int i = 0; i < (k); ++i) {
      v[p] = i;
      solve(p + 1);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  ;
  int n;
  cin >> n >> k;
  solve(0);
  long long pans = 1;
  for (int i = 0; i < (n - k); ++i) pans = (pans * (n - k)) % MOD;
  ans = (ans * pans) % MOD;
  cout << ans << endl;
  return 0;
}
