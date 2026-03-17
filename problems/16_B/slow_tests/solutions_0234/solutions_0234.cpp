#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long m, n;
  cin >> m >> n;
  long ar[n], br[n];
  for (int i = 0; i < n; i++) {
    cin >> ar[i] >> br[i];
  }
  int tmp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (br[j] < br[j + 1]) {
        tmp = br[j];
        br[j] = br[j + 1];
        br[j + 1] = tmp;
        tmp = ar[j];
        ar[j] = ar[j + 1];
        ar[j + 1] = tmp;
      }
    }
  }
  int cnt = 0, i = 0;
  long sum = 0;
  while (cnt != m && i < n) {
    while (ar[i] != 0) {
      sum += br[i];
      ar[i]--;
      cnt++;
      if (cnt == m) break;
    }
    i++;
  }
  cout << sum;
  return 0;
}
