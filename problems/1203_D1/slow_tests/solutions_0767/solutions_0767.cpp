#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int maxm = 5000 + 5;
const int MOD = 1e9 + 7;
char s[maxn], t[maxn], ss[maxn];
int next_[10010];
int ans;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> s >> t;
  int len1 = strlen(s), len2 = strlen(t);
  for (int i = (0); i <= (len1 - 1); i++) {
    for (int j = (i); j <= (len1 - 1); j++) {
      int cur = 0;
      for (int k = (0); k <= (len1 - 1); k++) {
        if (k < i || k > j) ss[cur++] = s[k];
      }
      int l = 0, r = 0;
      while (l < cur && r < len2) {
        if (t[r] == ss[l]) r++;
        l++;
      }
      if (r == len2) {
        ans = max(ans, j - i + 1);
      }
    }
  }
  cout << ans;
  return 0;
}
