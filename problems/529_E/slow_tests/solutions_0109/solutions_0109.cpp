#include <bits/stdc++.h>
const long long OO = 1000000007;
const long long MAXN = 100005;
using namespace std;
int n, k, q;
int a[5005];
vector<int> res;
map<int, bool> in;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
    in[a[i]] = true;
  }
  cin >> q;
  for (long long z = 0; z < q; ++z) {
    int x;
    int mn = k + 1;
    cin >> x;
    for (int i = k; i > 0; --i) {
      for (int j = i; j > 0; --j) {
        for (int t = 0; t < n; ++t) {
          if (((x - a[t] * j == 0) && i == j) ||
              (i != j && (x - a[t] * j > 0) &&
               ((x - a[t] * j) % (i - j) == 0) &&
               in[(x - a[t] * j) / (i - j)])) {
            mn = i;
            break;
          }
        }
      }
    }
    if (mn == k + 1)
      res.push_back(-1);
    else
      res.push_back(mn);
  }
  for (int i = 0; i < q; ++i) cout << res[i] << endl;
  return 0;
}
