#include <bits/stdc++.h>
using namespace std;
const int inf = 10000 * 20000;
int n, w[2000], ans = inf;
int main() {
  cin >> n;
  n *= 2;
  for (int i = 0; i < n; i++) cin >> w[i];
  sort(w, w + n);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int p = w[i], q = w[j];
      w[i] = inf, w[j] = inf;
      sort(w, w + n);
      int s = 0;
      for (int k = 0; k < n; k += 2) s += w[k + 1] - w[k];
      ans = min(ans, s);
      w[n - 1] = p, w[n - 2] = q;
      sort(w, w + n);
    }
  }
  cout << ans << endl;
}
