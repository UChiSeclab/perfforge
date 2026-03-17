#include <bits/stdc++.h>
using namespace std;
int n, m;
long long dpa[111][111][111], a[111][111], dpb[111][10011];
int arr[111][111], sz[111], idx;
int vis[111][111][111], cnt = 1;
long long funa(int l, int r, int rem) {
  if (!rem || l > r) return 0;
  long long &ret = dpa[l][r][rem];
  if (vis[l][r][rem] == cnt) return ret;
  long long a = arr[idx][l] + funa(l + 1, r, rem - 1);
  long long b = arr[idx][r] + funa(l, r - 1, rem - 1);
  vis[l][r][rem] = cnt;
  return ret = max(a, b);
}
long long funb(int id, int rem) {
  if (rem == 0) return 0;
  if (id == n) return 0;
  long long &ret = dpb[id][rem];
  if (ret != -1) return ret;
  for (int i = 0; i <= sz[id]; ++i) {
    if (i <= rem) ret = max(ret, a[id][i] + funb(id + 1, rem - i));
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> sz[i];
    for (int j = 0; j < sz[i]; ++j) cin >> arr[i][j];
  }
  memset(dpb, -1, sizeof dpb);
  for (int i = 0; i < n; ++i) {
    idx = i;
    for (int j = 0; j <= sz[i]; ++j) {
      a[i][j] = funa(0, sz[i] - 1, j);
    }
    ++cnt;
  }
  cout << funb(0, m) << '\n';
}
