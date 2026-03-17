#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 4;
int a[maxn], b[maxn];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (a[i] == a[j]) b[i]++;
    }
  sort(b + 1, b + n + 1);
  cout << b[n];
  return 0;
}
