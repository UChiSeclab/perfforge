#include <bits/stdc++.h>
using namespace std;
int a[200005], cnt[200005], acc_cnt[200005];
bool color[200005];
int n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  bool there_ai_eq_1 = false;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 1) {
      there_ai_eq_1 = true;
    }
  }
  if (there_ai_eq_1) {
    long long int sum = 0;
    for (int i = 1; i <= n; i++) {
      sum += a[i];
    }
    cout << sum;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    cnt[a[i]]++;
  }
  for (int i = 2; i < 200005; i++) {
    acc_cnt[i] = acc_cnt[i - 1] + cnt[i];
  }
  long long int ans = 0;
  for (int i = 2; i < 200005; i++) {
    if (cnt[i] > 0 && color[i] == false) {
      int j = i;
      while (j < 200005) {
        color[j] = true;
        j += i;
      }
      j = i;
      long long int multi = i;
      long long int power = 0;
      do {
        j += i;
        j = min(j, 200005 - 1);
        power += (acc_cnt[j - 1] - acc_cnt[multi - 1]) * multi;
        multi += i;
      } while (j < 200005 - 1);
      ans = max(ans, power);
    }
  }
  cout << ans;
  return 0;
}
