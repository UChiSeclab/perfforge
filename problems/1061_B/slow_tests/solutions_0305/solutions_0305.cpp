#include <bits/stdc++.h>
using namespace std;
int a[100010];
bool cmp(int a, int b) { return a > b; }
int main() {
  int n, m;
  cin >> n >> m;
  long long sum = 0;
  int flag = 0;
  int M = n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a, a + n, cmp);
  long long h = a[0], ans = 0;
  for (int i = 0; i < n; i++) {
    if (h == 1) {
      ans += n - i;
      break;
    }
    if (h <= a[i + 1]) {
      h--;
      ans++;
    }
    if (h > a[i + 1]) {
      ans += h - a[i + 1];
      h = a[i + 1];
    }
    if (h == 1) {
      ans += (n - i - 1);
      break;
    }
  }
  cout << sum - ans << endl;
}
