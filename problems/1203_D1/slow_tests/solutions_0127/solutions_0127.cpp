#include <bits/stdc++.h>
using namespace std;
long long int expo(long long int n) {
  long long int t;
  if (n == 0)
    return 1;
  else if (n == 1)
    return 2;
  t = expo(n / 2);
  if (n % 2) {
    return t * t * 2;
  } else
    return t * t;
}
long long int exponentMod(long long int A, long long int B, long long int C) {
  if (A == 0) return 0;
  if (B == 0) return 1;
  long long int y;
  if (B % 2 == 0) {
    y = exponentMod(A, B / 2, C);
    y = (y * y) % C;
  } else {
    y = A % C;
    y = (y * exponentMod(A, B - 1, C) % C) % C;
  }
  return (long long int)((y + C) % C);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int q = 1;
  while (q--) {
    string s, t;
    cin >> s >> t;
    long long int mx = 0;
    for (int i = 0; i < s.length(); i++) {
      for (int j = 0; j < s.length(); j++) {
        long long int pos = 0;
        for (int p = 0; p < s.length(); p++) {
          if (i <= p && p <= j) continue;
          if (pos <= t.length() && s[p] == t[pos]) pos++;
        }
        if (pos == t.length()) {
          mx = max(mx, (long long int)j - i + 1);
        }
      }
    }
    cout << mx << "\n";
  }
}
