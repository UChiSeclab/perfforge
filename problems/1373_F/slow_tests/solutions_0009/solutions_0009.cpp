#include <bits/stdc++.h>
using namespace std;
int T, N, a[1000001], b[1000001];
bool chk[1000001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> T;
  while (T--) {
    cin >> N;
    for (int i = 0; i < N; i++) {
      cin >> a[i];
      chk[i] = 0;
    }
    for (int i = 0; i < N; i++) cin >> b[i];
    int s, prev = -1, cnt = 0;
    while (1) {
      int f = 0;
      for (s = 0; s < N; s++) {
        if (a[s] > b[s] && f == 0)
          f = 1;
        else if (f == 1 && b[s] >= a[s])
          break;
      }
      if (f == 0) {
        cout << "YES\n";
        break;
      } else if (s == N && a[0] > b[0]) {
        cout << "NO\n";
        break;
      }
      if (f == 1 && s == N) {
        s = 0;
      }
      chk[s] = 1;
      for (int i = 0; i < N; i++) {
        int now = (s + i) % N;
        int nxt = (now + 1) % N;
        if (b[now] < a[now]) continue;
        chk[nxt] = 0;
        int x = min(a[nxt], b[now] - a[now]);
        a[nxt] -= x;
        b[now] -= x;
      }
      cnt++;
      if (cnt == 71) {
        cout << "NO\n";
        break;
      }
    }
  }
}
