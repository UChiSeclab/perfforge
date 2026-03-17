#include <bits/stdc++.h>
using namespace std;
char res[2000002], s[2000002];
int main() {
  int n, len = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int k, p = 1, l;
    cin >> s >> k;
    l = strlen(s);
    for (int j = 0; j < k; j++) {
      int x;
      cin >> x;
      for (int m = max(x, p); m < x + l; m++) {
        res[m] = s[m - x];
      }
      p = x + l - 1;
      if (len < p) len = p;
    }
  }
  for (int i = 1; i <= len; i++) {
    if (res[i])
      cout << res[i];
    else
      cout << 'a';
  }
  cout << endl;
  return 0;
}
