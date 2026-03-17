#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int N = 1e5 + 5;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, x;
  cin >> n >> m >> x;
  n = n - 2 * x + 2;
  m = m - 2 * x + 2;
  if (n < 0 or m < 0) return cout << 0, 0;
  int result = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (i == 0 or j == 0 or i == n - 1 or j == m - 1)
        if ((i + j) % 2 == 0) result++;
  cout << result << endl;
}
