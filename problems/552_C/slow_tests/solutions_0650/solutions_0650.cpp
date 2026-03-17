#include <bits/stdc++.h>
using namespace std;
long long int a[200], w, m, dp[200][4], i = 0;
bool mm = 0;
void asdd(long long int q, int s) {
  if (s == i + 1) {
    if (q == 0) mm = 1;
    return;
  }
  asdd(q, s + 1);
  asdd(q + a[s], s + 1);
  asdd(q - a[s], s + 1);
}
int main() {
  cin >> w >> m;
  if (w == 2 || w == 3) {
    cout << "YES";
    return 0;
  }
  a[0] = 1;
  while (a[i] <= 2 * 1e9) {
    i++;
    a[i] = a[i - 1] * w;
  }
  asdd(m, 0);
  if (mm)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
