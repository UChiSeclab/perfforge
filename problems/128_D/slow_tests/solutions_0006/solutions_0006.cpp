#include <bits/stdc++.h>
using namespace std;
const int inf = 1010101010;
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < (n); i++) cin >> v[i];
  int mi = inf, mx = 0;
  for (int i = 0; i < (n); i++) mi = min(mi, v[i]), mx = max(mx, v[i]);
  if (mx - mi > 100000) {
    puts("NO");
    return 0;
  };
  for (int i = 0; i < (n); i++) v[i] -= mi;
  mx -= mi;
  vector<int> cnt(100005);
  for (int i = 0; i < (n); i++) cnt[v[i]]++;
  int nd = 0;
  for (int i = mx - 1; i > 0; i--) {
    if (cnt[i] == 0) {
      puts("NO");
      return 0;
    };
    cnt[i]--;
    nd++;
  }
  for (int curpos = 0; curpos != mx + 1;) {
    if (cnt[curpos] == 0) {
      puts("NO");
      return 0;
    };
    cnt[curpos]--;
    nd++;
    if (curpos > 0 && cnt[curpos - 1]) {
      curpos--;
    } else {
      curpos++;
    }
  }
  if (nd == n)
    puts("YES");
  else {
    puts("NO");
    return 0;
  };
}
