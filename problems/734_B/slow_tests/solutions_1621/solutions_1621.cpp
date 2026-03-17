#include <bits/stdc++.h>
using namespace std;
int cnt[5];
long long Solve() {
  long long ans = 0;
  for (;;) {
    if (cnt[0] && cnt[2] && cnt[3]) {
      ans += 256;
      --cnt[0];
      --cnt[2];
      --cnt[3];
    } else if (cnt[0] && cnt[1]) {
      ans += 32;
      --cnt[0];
      --cnt[1];
    } else
      break;
  }
  return ans;
}
int main() {
  scanf("%d%d%d%d", &cnt[0], &cnt[1], &cnt[2], &cnt[3]);
  cout << Solve() << endl;
  return 0;
}
