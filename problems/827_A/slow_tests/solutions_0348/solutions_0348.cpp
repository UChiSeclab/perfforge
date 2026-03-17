#include <bits/stdc++.h>
using namespace std;
char rez[2000001], s[2000001];
int main() {
  int n, k, l, len = 0, p, poz;
  cin >> n;
  for (int i = 0; i < n; i++) {
    p = 1;
    cin >> s >> k;
    l = strlen(s);
    for (int j = 0; j < k; j++) {
      cin >> poz;
      for (int m = max(poz, p); m < poz + l; m++) {
        rez[m] = s[m - poz];
      }
      p = poz + l - 1;
      if (len < p) len = p;
    }
  }
  for (int i = 1; i <= len; i++) {
    if (rez[i])
      cout << rez[i];
    else
      cout << 'a';
  }
  return 0;
}
