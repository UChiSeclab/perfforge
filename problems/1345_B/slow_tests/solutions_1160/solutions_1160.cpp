#include <bits/stdc++.h>
using namespace std;
long long x;
bool fun(long long mid) {
  long long sum = 0;
  for (int i = 1; i < mid; i++) {
    sum += 3 * i;
  }
  sum += 2 * (mid);
  if (sum < x) {
    return false;
  } else {
    return true;
  }
}
long long Count(long long mid) {
  long long sum = 0;
  for (int i = 1; i < mid; i++) {
    sum += 3 * i;
  }
  sum += 2 * (mid);
  return sum;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> x;
    long long s = 0;
    while (x >= 2) {
      long long l = 0, r = x / 2 + 1;
      while (l < r) {
        long long mid = l + (r - l) / 2;
        if (fun(mid)) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }
      if (Count(l) == x) {
        x = 0;
        s++;
      } else if (Count(l) > x) {
        x -= Count(l - 1);
        s++;
      } else {
        x -= Count(l);
        s++;
      }
    }
    cout << s << endl;
  }
  return 0;
}
