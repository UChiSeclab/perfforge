#include <bits/stdc++.h>
using namespace std;
int n, k, ans, st[10], edge[10];
vector<int> L[10];
bool fr[10];
inline int Pow_Log(int x, int p) {
  int sol = 1;
  while (p) {
    if (p & 1) {
      sol = (1LL * sol * x) % 1000000007;
      --p;
    }
    p >>= 1;
    x = (1LL * x * x) % 1000000007;
  }
  return sol;
}
inline void Dfs(int nod) {
  vector<int>::iterator it;
  for (it = L[nod].begin(); it != L[nod].end(); ++it)
    if (!fr[*it]) {
      fr[*it] = true;
      Dfs(*it);
    }
}
inline bool Ok() {
  int i, cnt;
  for (i = 1; i <= k; ++i) L[i].clear();
  for (i = 1; i <= k; ++i) {
    fr[i] = false;
    L[st[i]].push_back(i);
  }
  Dfs(1);
  for (i = 1, cnt = 0; i <= k; ++i) cnt += fr[i];
  return (cnt == k);
}
inline void Back(int pas) {
  int i;
  if (pas == k + 1) {
    if (Ok()) ++ans;
    return;
  }
  for (i = 1; i <= k; ++i) {
    st[pas] = i;
    Back(pas + 1);
  }
}
int main() {
  int i, j;
  cin.sync_with_stdio(0);
  cin >> n >> k;
  Back(1);
  ans = (1LL * ans * Pow_Log(n - k, n - k)) % 1000000007;
  cout << ans;
  return 0;
}
