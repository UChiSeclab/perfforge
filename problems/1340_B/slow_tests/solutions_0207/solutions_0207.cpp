#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
string rep[] = {"1110111", "0010010", "1011101", "1011011", "0111010",
                "1101011", "1101111", "1010010", "1111111", "1111011"};
string dig[2005];
bitset<N> val[2005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int k;
  cin >> k;
  for (int i = 1; i <= n; ++i) cin >> dig[i];
  reverse(dig + 1, dig + 1 + n);
  val[0] = 1;
  for (int i = 1; i <= n; ++i)
    for (int c = 0; c < 10; ++c) {
      int w = 0;
      for (int j = 0; j < 7; ++j) {
        if (dig[i][j] > rep[c][j]) {
          w = k + 1;
          break;
        }
        w += rep[c][j] - dig[i][j];
      }
      val[i] |= (val[i - 1] << w);
    }
  if (!val[n][k]) {
    cout << "-1";
    return 0;
  }
  for (int i = n; i >= 1; --i)
    for (int c = 9; c >= 0; --c) {
      int w = 0;
      for (int j = 0; j < 7; ++j) {
        if (dig[i][j] > rep[c][j]) {
          w = k + 1;
          break;
        }
        w += rep[c][j] - dig[i][j];
      }
      if (w > k) continue;
      if (val[i - 1][k - w]) {
        k -= w;
        cout << c;
        break;
      }
    }
}
