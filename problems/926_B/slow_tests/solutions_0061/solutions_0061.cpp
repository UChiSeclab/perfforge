#include <bits/stdc++.h>
using namespace std;
int gdc(int a, int b) {
  if (!b)
    return a;
  else
    return gdc(b, a % b);
}
int execute() {
  int n;
  cin >> n;
  int a[n], i, diff[n], minDiff, ans = 0;
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (i = 1; i < n; i++) diff[i - 1] = a[i] - a[i - 1];
  minDiff = diff[0];
  for (i = 1; i < n - 1 && ans != 1; i++) minDiff = gdc(minDiff, diff[i]);
  for (i = 0; i < n - 1; i++) {
    while (a[i] + minDiff != a[i + 1]) {
      a[i] += minDiff;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
char mtest = false;
unsigned short TE = 1;
int main() {
  ios_base::sync_with_stdio(false);
  if (mtest) cin >> TE;
  while (TE--) execute();
  return 0;
}
