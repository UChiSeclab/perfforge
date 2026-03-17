#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 5;
char str[maxn];
char t[maxn];
int pos[maxn];
int main() {
  memset(str, 'a', sizeof(str));
  int n, k, m;
  int d = -1;
  cin >> n;
  while (n--) {
    cin >> t;
    cin >> k;
    int len = strlen(t);
    for (int i = 1; i <= k; i++) cin >> pos[i];
    int cnt = 0, ctt = 0;
    for (int i = 1; i <= k; i++) {
      ctt = max(ctt, pos[i] + len - 1);
      int cnn = max(cnt + 1, pos[i]);
      for (int j = cnn; j < pos[i] + len; j++) {
        str[j] = t[j - pos[i]];
      }
      cnt = ctt;
    }
    d = max(d, ctt);
  }
  for (int i = 1; i <= d; i++) {
    cout << str[i];
  }
  cout << endl;
  return 0;
}
