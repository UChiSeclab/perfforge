#include <bits/stdc++.h>
const long long int MOD = 1e9 + 7;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long int finish[5005] = {0}, freq[5005][5005] = {0}, total[5005] = {0};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    total[a]++;
    freq[a][b]++;
  }
  for (int i = 0; i < n; ++i) {
    long long int tmp = max(0LL, (total[i] - 1) * n);
    int j = (i + 1 + n) % n;
    while (j != i) {
      if (freq[i][j] != 0) {
        if (j > i)
          tmp += j - i;
        else
          tmp += n - i + j;
        break;
      }
      j++;
      j %= n;
    }
    finish[i] = tmp;
  }
  for (int i = 0; i < n; ++i) {
    long long int ans = finish[i];
    int j = (i + 1) % n;
    while (j != i) {
      int tmp;
      if (j > i)
        tmp = j - i;
      else
        tmp = n - i + j;
      if (finish[j] != 0) ans = max(ans, finish[j] + tmp);
      ++j;
      j %= n;
    }
    cout << ans << " ";
  }
  return 0;
}
