#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y;
  cin >> x >> y;
  int sum = 1, sum1 = 0;
  for (;;) {
    if (sum == y) break;
    if (sum > y) {
      cout << "No";
      return 0;
    }
    sum++;
    sum1++;
  }
  for (;;) {
    if (sum1 == x && sum == y) {
      cout << "Yes";
      return 0;
    }
    if (sum1 > x) {
      cout << "No";
      return 0;
    }
    if (sum1 > 0) sum1 += 2;
    if (sum1 == 0) {
      cout << "No";
      return 0;
    }
  }
  return 0;
}
