#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  vector<int> balance(100005);
  vector<int>::iterator it;
  int sum = 0, total = 0;
  char c, last = '*';
  int ok = 0, zero = 0;
  int ans = 0;
  scanf("%d ", &n);
  for (int i = 0; i < n;) {
    scanf("%c", &c);
    if (c == '(') {
      if (last == ')') {
        if (sum < 0) {
          total += sum;
          ok++;
          sum = 0;
        }
      }
      sum++;
      last = '(';
    } else if (c == ')') {
      sum--;
      last = ')';
    } else {
      if (sum > 0) {
        if (ok == 0)
          balance[i] = total + sum;
        else
          balance[i] = 0x3f3f3f3f;
      } else {
        balance[i] = total + sum;
        if (balance[i] == 0) zero++;
      }
      i++;
      total = 0;
      sum = 0;
      last = '*';
      ok = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    if (balance[i] != 0x3f3f3f3f && balance[i] != 0) {
      it = find(balance.begin(), balance.end(), 0 - balance[i]);
      if (it != balance.end()) {
        *it = 0x3f3f3f3f;
        balance[i] = 0x3f3f3f3f;
        ans++;
      }
    }
  }
  ans += zero / 2;
  printf("%d\n", ans);
  return 0;
}
