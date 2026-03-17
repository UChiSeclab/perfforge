#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<long long int> v;
  for (int i = 0; i < n; i++) {
    long long int a;
    cin >> a;
    v.push_back(a);
  }
  int x = 0;
  int a = 0, b = 0;
  for (int j = 0; j < n; j++) {
    x = x + v[j];
    b = min(x, b);
    a = max(x, a);
  }
  int y = 0;
  for (int i = 0; i <= m; i++) {
    if (i + b >= 0 and i + a <= m) {
      y++;
    }
  }
  cout << y;
  return 0;
}
