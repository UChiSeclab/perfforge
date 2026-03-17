#include <bits/stdc++.h>
using namespace std;
int main() {
  long long cnt[1000010] = {0};
  long long n, a, ma = -1;
  long long ans = 0, last = 0;
  cin >> n;
  for (long long i = 0; i < n; ++i) {
    cin >> a;
    if (a > ma) ma = a;
    cnt[a]++;
  }
  for (long long i = ma; i >= 1; --i) {
    if ((cnt[i] % 2 == 1) && (cnt[i - 1])) {
      --cnt[i];
      ++cnt[i - 1];
    } else if ((cnt[i] % 2 == 1) && !cnt[i - 1]) {
      --cnt[i];
    }
  }
  ans += ((cnt[ma] / 4) * ma * ma);
  cnt[ma] %= 4;
  last = (cnt[ma] ? ma : 0);
  for (long long i = ma - 1; i >= 1; --i) {
    if (cnt[last] && cnt[i] >= 2) {
      ans += (i * (last));
      cnt[i] -= 2;
      cnt[last] -= 2;
    }
    ans += ((cnt[i] / 4) * i * i);
    cnt[i] %= 4;
    last = (cnt[i] ? i : last);
  }
  cout << ans << endl;
  return 0;
}
