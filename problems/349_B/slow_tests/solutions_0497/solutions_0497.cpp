#include <bits/stdc++.h>
using namespace std;
int kn;
int main() {
  int k;
  cin >> k;
  int n = 9;
  kn = k;
  int a[10];
  int minm = INT_MAX, ind = -1;
  for (int i = 1; i <= 9; i++) {
    int x;
    cin >> x;
    a[i] = x;
    if (minm > a[i]) {
      minm = a[i];
      ind = i;
    }
  }
  int len = k / minm;
  if (len == 0) {
    cout << "-1\n";
  } else {
    string ans = "";
    k = k - (len)*minm;
    for (int i = 0; i < len; i++) {
      ans += to_string(ind);
    }
    int i = 9, j = 0;
    while (j < ans.length() && i > 0) {
      if (k + a[ans[j] - '0'] >= a[i]) {
        string f = to_string(i);
        k = k + a[ans[j] - '0'] - a[i];
        ans[j] = f[0];
        j++;
      } else
        i--;
    }
    cout << ans << "\n";
  }
}
