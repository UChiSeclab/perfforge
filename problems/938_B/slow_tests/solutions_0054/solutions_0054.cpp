#include <bits/stdc++.h>
using namespace std;
long long ar[1000007];
int main() {
  long long n, i, j, k;
  cin >> n;
  for (i = 0; i < n; i++) {
    long long x;
    cin >> x;
    ar[x] = 1;
  }
  long long s1 = 1, e1 = 1000000, cnt = 0, ans = 0;
  while (1) {
    ans++;
    s1++;
    if (ar[s1] == 1) cnt++;
    if (cnt == n || s1 == e1 - 1) break;
    e1--;
    if (ar[e1] == 1) cnt++;
    if (cnt == n || s1 == e1 - 1) break;
  }
  cout << ans << endl;
  return 0;
}
