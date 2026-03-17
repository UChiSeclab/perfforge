#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  map<int, int> cnt;
  int a;
  for (int i = 0; i < n; i++) {
    cin >> a;
    ++cnt[a];
  }
  int ones = cnt[1], twos = cnt[2], threes = cnt[3], fours = cnt[4];
  int ans = 0;
  if (ones >= twos) {
    ans += twos;
    threes += twos;
    ones -= twos;
    twos = 0;
  } else {
    ans += ones;
    threes += ones;
    twos -= ones;
    ones = 0;
  }
  if (ones) {
    ans += ones / 3 * 2;
    threes += ones / 3;
    ones = ones % 3;
    if (ones <= threes) {
      ans += ones;
      ones = 0;
    } else if (ones == 2 && fours >= 1) {
      ans += 2;
    } else if (ones == 1 && fours >= 2) {
      ans += 2;
    } else {
      ans = -1;
    }
  } else if (twos) {
    ans += twos / 3 * 2;
    threes += twos / 3 * 2;
    twos %= 3;
    if (twos == 1) {
      if (fours) {
        ans += 1;
        twos = 0;
      } else if (threes >= 2) {
        ans += 2;
        twos = 0;
      } else {
        ans = -1;
      }
    } else if (twos == 2) {
      ans += 2;
      twos = 0;
    }
  }
  printf("%d\n", ans);
}
