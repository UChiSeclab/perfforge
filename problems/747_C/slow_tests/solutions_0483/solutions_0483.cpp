#include <bits/stdc++.h>
using namespace std;
void fastio() {
  ios::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
}
struct rec {
  long long flg;
  long long end;
};
int main() {
  fastio();
  long long i, j, n, q;
  cin >> n >> q;
  struct rec serv[n + 1];
  long long arry[q][3];
  for (i = 0; i < q; i++) cin >> arry[i][0] >> arry[i][1] >> arry[i][2];
  for (i = 0; i < n + 1; i++) {
    serv[i].flg = 0;
    serv[i].end = -5;
  }
  long long t = 0;
  long long k = 0;
  long long servcnt = n;
  while (k != q) {
    t++;
    for (i = 1; i < n + 1; i++) {
      if (serv[i].end == t) {
        serv[i].flg = 0;
        serv[i].end = -5;
        servcnt++;
      }
    }
    if (t == arry[k][0]) {
      if (servcnt < arry[k][1]) {
        cout << -1 << endl;
        k++;
      } else {
        long long scnt = arry[k][1];
        long long ans = 0;
        for (i = 1; i < n + 1; i++) {
          if (serv[i].flg == 0) {
            serv[i].flg = 1;
            serv[i].end = arry[k][2] + t;
            ans += i;
            scnt--;
            if (scnt == 0) {
              break;
            }
          }
        }
        cout << ans << endl;
        servcnt -= arry[k][1];
        k++;
      }
    }
  }
  return (0);
}
