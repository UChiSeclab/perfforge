#include <bits/stdc++.h>
using namespace std;
bool check(int a, int b, int c) {
  if (a + b > c && b + c > a && a + c > b) return true;
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  int mi = 1000;
  for (int i = 0; i <= max(a, max(b, c)); i++)
    for (int j = 0; j <= max(a, max(b, c)); j++)
      for (int k = 0; k <= max(a, max(b, c)); k++)
        if (check(a + i, b + j, c + k)) mi = min(mi, i + j + k);
  cout << mi;
}
