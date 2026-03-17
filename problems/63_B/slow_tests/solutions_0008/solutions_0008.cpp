#include <bits/stdc++.h>
using namespace std;
const double EPS = (1e-7);
double PI = 3.1415926535897932384626433832795;
int arr[123456];
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", arr + i);
  }
  int ans = 0;
  if (n == 1) ans = max(0, k - arr[0]);
  for (int i = 0; i < 100000; ++i) {
    bool b = 0;
    for (int j = 0; j < n - 1; ++j) {
      if (arr[j] != arr[j + 1] && arr[j] < k) {
        arr[j]++;
        b = 1;
      }
      if (j == n - 2 && arr[j + 1] < k) {
        arr[j + 1]++;
        b = 1;
      }
    }
    ans += b;
  }
  cout << ans;
  return 0;
}
