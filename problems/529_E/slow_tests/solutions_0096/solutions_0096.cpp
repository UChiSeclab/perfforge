#include <bits/stdc++.h>
using namespace std;
ifstream fin("in.in");
ofstream fout("out.out");
const int N = 5000 + 10, A = 1e5 + 10;
int n, k, q, a[N];
int solve(int x) {
  int res = k + 1;
  vector<int> v;
  int mn[A], cnt[A];
  fill(mn, mn + A, k);
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n; i++)
    for (int j = 1; j <= k; j++) {
      if (a[i] * j == x) res = min(res, j);
      v.push_back(a[i] * j);
    }
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  for (int i = 0; i < n; i++)
    for (int j = 1; j <= k; j++) {
      int ind = (lower_bound(v.begin(), v.end(), a[i] * j) - v.begin());
      if (mn[ind] > j) {
        mn[ind] = j;
        cnt[ind]++;
      } else if (mn[ind] == j)
        cnt[ind]++;
    }
  for (int i = 0; i < n; i++)
    for (int j = 1; j <= k; j++) {
      int ind1 = (lower_bound(v.begin(), v.end(), a[i] * j) - v.begin());
      int rem = x - a[i] * j;
      int ind2 = (lower_bound(v.begin(), v.end(), rem) - v.begin());
      if (ind2 == v.size() || v[ind2] != rem) continue;
      if (mn[ind2] <= k - j) {
        if (ind1 != ind2 || cnt[ind2] > 1) res = min(res, mn[ind2] + j);
      }
    }
  return (res == k + 1 ? -1 : res);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> q;
  for (; q; q--) {
    int x;
    cin >> x;
    cout << solve(x) << endl;
  }
  return 0;
}
