#include <bits/stdc++.h>
using namespace std;
void fastInOut() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL), cout.tie(NULL);
}
int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0, -1, 1, -1, 1};
int main() {
  map<int, long long> cnt;
  long long mi = 100000009, ma = -1, n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x < mi) mi = x;
    if (x > ma) ma = x;
    cnt[x]++;
  }
  for (int i = ma; i >= mi; i--) {
    if (cnt[i] % 2 == 1) {
      if (cnt[i - 1] > 0) cnt[i - 1]++;
      cnt[i]--;
    }
  }
  long long ans = 0;
  long long left = -1;
  for (int i = ma; i >= mi; i--) {
    long long num = i;
    if (left != -1 && cnt[i] > 0) {
      ans += left * num;
      cnt[i] -= 2;
      left = -1;
    }
    long long x = cnt[i] / 4;
    ans += (x * num * num);
    if (cnt[i] % 4 != 0) left = i;
  }
  cout << ans;
}
