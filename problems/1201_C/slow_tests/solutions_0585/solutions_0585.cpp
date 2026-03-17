#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, a;
  cin >> n >> k;
  vector<int> g;
  for (int i = 0; i < n; i++) {
    cin >> a;
    g.push_back(a);
  }
  sort(g.begin(), g.end());
  for (int j = 0; j < (n + 1) / 2; j++) {
    if (j == (n + 1) / 2 - 1) {
      while (k >= j + 1) {
        k -= (j + 1);
        g[((n - 1) / 2)]++;
      }
    } else {
      while (k >= (j + 1) && g[((n - 1) / 2) + j] < g[((n - 1) / 2) + j + 1]) {
        g[((n - 1) / 2)]++;
        if (j) {
          g[((n - 1) / 2) + j]++;
        }
        k -= (j + 1);
      }
    }
  }
  cout << g[((n - 1) / 2)];
  return 0;
}
