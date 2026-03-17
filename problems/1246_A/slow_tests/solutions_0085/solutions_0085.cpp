#include <bits/stdc++.h>
using namespace std;
const int QQ = 3e5 + 10;
const int maxN = 2e5 + 100;
const int maxM = 3e5 + 10;
const long long oo = 1e18;
const int module = 1e9 + 7;
const long double du = 1e-9;
void doc() {
  freopen(
      "solve"
      ".inp",
      "r", stdin);
  freopen(
      "solve"
      ".out",
      "w", stdout);
}
void solve() {
  long long n, p;
  cin >> n >> p;
  for (int i = 1; i <= 2000000; i++) {
    long long m = n - p * i;
    long long value = 0;
    for (int j = 0; j < 40; j++) {
      if ((m >> j) & 1) value += 1;
    }
    if (value <= i && i <= m) {
      cout << i;
      return;
    }
  }
  cout << -1;
}
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
}
