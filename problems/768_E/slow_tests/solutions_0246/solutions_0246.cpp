#include <bits/stdc++.h>
using namespace std;
int n;
map<pair<int, long long>, int> m;
int f(int s, long long mask) {
  if (s == 0) {
    return 0;
  }
  pair<int, long long> node = make_pair(s, mask);
  if (m.count(node)) {
    return m[node];
  }
  vector<bool> v(s + 1, false);
  for (int i = 1; i <= s; i++) {
    if ((1LL << (i - 1)) & mask) {
      v[f(s - i, mask ^ (1LL << (i - 1)))] = true;
    }
  }
  for (int i = 0; i <= s; i++) {
    if (!v[i]) {
      m[node] = i;
      break;
    }
  }
  return m[node];
}
int main() {
  scanf("%d", &n);
  int ans = 0;
  int s;
  for (int i = 0; i < n; i++) {
    scanf("%d", &s);
    ans ^= f(s, (1LL << s) - 1);
  }
  printf("%s\n", ans == 0 ? "YES" : "NO");
  return 0;
}
