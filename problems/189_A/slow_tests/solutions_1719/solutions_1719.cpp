#include <bits/stdc++.h>
using namespace std;
int n, a, b, c;
void input() { cin >> n >> a >> b >> c; }
int mx = -1;
int k = 0;
void solve() {
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      k = n - (i * a + j * b);
      if (k % c == 0 && k >= 0) {
        mx = max(mx, i + j + (k / c));
      }
    }
  }
}
void output() { cout << mx; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  input();
  solve();
  output();
  return 0;
}
