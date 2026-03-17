#include <bits/stdc++.h>
using namespace std;
const int N = 1000, M = 100;
int k[3], kmax, lit[N];
bool check(int n = 0, int xmax = 0) {
  if (n == 3) {
    for (int y = xmax; y < N; y++)
      if (!lit[y]) return false;
    return true;
  }
  for (int p = n + 1, q = k[n], x = 0; x < M; x++) {
    for (int y = x; y < N; y += q) lit[y]++;
    if (check(p, max(x, xmax))) return true;
    for (int y = x; y < N; y += q) lit[y]--;
  }
  return false;
}
int main() {
  for (int i = 0; i < 3; i++) cin >> k[i];
  sort(k, k + 3), kmax = k[2];
  if (check())
    cout << "YES";
  else
    cout << "NO";
}
