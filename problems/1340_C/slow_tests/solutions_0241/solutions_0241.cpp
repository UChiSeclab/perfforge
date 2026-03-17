#include <bits/stdc++.h>
using namespace std;
int N, M;
int A[10005];
int id[1000005];
int G, R;
bool vis[10005];
bool can[10005][1005];
vector<int> nx, nxx;
int ans = 1e9;
void anal(int n) {
  if (N - A[n] <= G) {
    ans = min(ans, N - A[n]);
    return;
  }
  int d;
  vector<vector<int>> V(G + 1);
  V[0].push_back(n);
  for (int i = 0; i <= G; i++) {
    for (int p : V[i]) {
      if (i == G) {
        nxx.push_back(p);
        continue;
      }
      if (p > 1 && i + A[p] - A[p - 1] <= G) {
        d = i + A[p] - A[p - 1];
        if (!can[p - 1][d]) {
          can[p - 1][d] = 1;
          V[d].push_back(p - 1);
        }
      }
      if (p < M && i + A[p + 1] - A[p] <= G) {
        d = i + A[p + 1] - A[p];
        if (!can[p + 1][d]) {
          can[p + 1][d] = 1;
          V[d].push_back(p + 1);
        }
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  for (int i = 1; i <= M; i++) {
    cin >> A[i];
    id[A[i]] = i;
  }
  sort(A + 1, A + 1 + M);
  cin >> G >> R;
  nx.push_back(1);
  can[1][0] = 1;
  for (int k = 1; k <= M; k++) {
    nxx.clear();
    for (int ni : nx) anal(ni);
    if (ans != 1e9) {
      cout << (k - 1) * (G + R) + ans << '\n';
      return 0;
    }
    nx = nxx;
  }
  cout << -1 << '\n';
  return 0;
}
