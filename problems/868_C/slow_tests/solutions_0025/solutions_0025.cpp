#include <bits/stdc++.h>
using namespace std;
const long long int INF = 0x3f3f3f3f3f3f3f3f;
int n, k;
int cnt[64];
bool valid(int x) {
  int CNT[6], sum = 0;
  memset(CNT, 0, sizeof(CNT));
  for (int i = 0; i < (1 << k); i++) {
    if (((1 << i) & x) != 0 && cnt[i]) {
      sum++;
      for (int j = 0; j < k; j++) {
        if ((1 << j) & i) {
          CNT[j]++;
        }
      }
    }
  }
  if (sum == 0) return false;
  for (int i = 0; i < k; i++) {
    if ((CNT[i] * 2) > sum) return false;
  }
  return true;
}
int main() {
  scanf("%d%d", &n, &k);
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < n; i++) {
    int code = 0;
    for (int j = 0; j < k; j++) {
      int tmp;
      scanf("%d", &tmp);
      if (tmp) code |= (1 << j);
    }
    cnt[code]++;
  }
  bool flag = false;
  for (int i = 0; i < (1 << k); i++) {
    for (int j = 0; j < (1 << k); j++) {
    }
  }
  int limit = (1 << k);
  limit = (1 << limit);
  for (int i = 1; i < limit; i++) {
    if (valid(i)) {
      flag = true;
      break;
    }
  }
  puts(flag ? "YES" : "NO");
  return 0;
}
