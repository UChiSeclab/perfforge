#include <bits/stdc++.h>
using namespace std;
int dist(int a, int b, int n) {
  if (a <= b) return b - a;
  return b + n - a;
}
int main() {
  int n, m, i, a, b;
  cin >> n;
  cin >> m;
  int mini[n], nume[n];
  for (i = 0; i < n; i++) {
    mini[i] = n + 3;
    nume[i] = 0;
  }
  for (i = 0; i < m; i++) {
    cin >> a;
    cin >> b;
    a--;
    b--;
    nume[a]++;
    if (dist(a, b, n) < mini[a]) mini[a] = dist(a, b, n);
  }
  for (i = 0; i < n; i++) {
    a = 0;
    for (b = 0; b < n; b++) {
      if ((n * (nume[b] - 1) + mini[b] + dist(i, b, n) > a) && (nume[b] != 0)) {
        a = n * (nume[b] - 1) + mini[b] + dist(i, b, n);
      }
    }
    cout << a << " ";
  }
  return 0;
}
